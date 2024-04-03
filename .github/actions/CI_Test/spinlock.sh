#!/bin/bash
input=""
while [[ $input != "$1" ]] ; do
        read input
done
echo "Captured $1"