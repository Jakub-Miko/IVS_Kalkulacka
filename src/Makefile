.PHONY: all clean run dependencies build/Ivs_Calculator pack

all: dependencies build/Ivs_Calculator 

build/Ivs_Calculator: build/Makefile
	cd build && make --no-print-directory

pack: build/Ivs_Calculator
	cd build && cpack -G DEB

build/Makefile: CMakeLists.txt 
	cmake -S . -B ./build -G "Unix Makefiles"

clean:
	rm -rf ./build
	git clean -dfX
run: build/Ivs_Calculator
	cd build && ./Ivs_Calculator

dependencies: 
	sudo apt install -y qt6-base-dev cmake build-essential libgl1-mesa-dev qt6-multimedia-dev libqt6svg6-dev 
