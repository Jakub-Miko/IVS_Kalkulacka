#!/bin/bash
pwd
sleep 1m && echo "Build Timed out" && kill -s SIGINT -1 &
pid_timeout=$!


cd /github/workspace/
umask 000
mkdir artifacts
set -o pipefail
cd src
make 2>&1 | tee /github/workspace/artifacts/build_output
make_err=$?
if [[ "$make_err" -ne 0 ]] ; then 
    chmod 777 -R /github/workspace/
    exit 1
fi

kill $pid_timeout

Xvfb :99 -screen 1 1920x1080x8 &
export DISPLAY=:99

sleep 15s && echo "Tests Timed out" && kill -s SIGINT -1 &
pid_timeout=$!

cd build
ctest 2>&1 | tee /github/workspace/artifacts/test_output
test_err=$?

kill $pid_timeout

sleep 20s && echo "Screenshot Timed out" 1>&2 && kill -s SIGINT -1 &
pid_timeout=$!

mkfifo pipe
./Ivs_Calculator > pipe 2>&1 &
run_error=$?
window_pid=$!
/spinlock.sh "Window Opened" < pipe
rm pipe
sleep 0.5s
import -window E-Calculator /github/workspace/artifacts/Window.png
sleep 0.5s
kill $window_pid

kill $pid_timeout

chmod 777 -R /github/workspace/
if [[ "$make_err" -ne 0  || "$test_err" -ne 0 || "$run_error_err" -ne 0 ]] ; then 
    exit 1
fi
exit 0