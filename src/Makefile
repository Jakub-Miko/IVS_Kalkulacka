.PHONY: all clean run dependencies

all: dependencies build/Ivs_Calculator 

build/Ivs_Calculator: build/Makefile
	cd build && make


build/Makefile: CMakeLists.txt 
	cmake -S . -B ./build -G "Unix Makefiles"

clean:
	rm -rf ./build
	git clean -dfX
run: build/Ivs_Calculator
	cd build && ./Ivs_Calculator

dependencies: 
	sudo apt install -y qt6-base-dev cmake
