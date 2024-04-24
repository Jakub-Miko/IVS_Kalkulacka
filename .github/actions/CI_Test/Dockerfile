FROM ubuntu

RUN apt update && apt install -y xvfb sudo git cmake libglx-dev \ 
libgl1-mesa-dev qt6-base-dev doxygen g++ imagemagick x11-utils build-essential make qt6-multimedia-dev libqt6svg6-dev --no-install-recommends && rm -rf var/lib/apt/lists/*


COPY ./script.sh /
COPY ./spinlock.sh /
RUN chmod 770 /script.sh
RUN chmod 770 /spinlock.sh
ENTRYPOINT [ "/script.sh" ]



