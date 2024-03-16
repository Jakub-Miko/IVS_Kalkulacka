.PHONY: all clean run

all: build/Ivs_Calculator

build/Ivs_Calculator: build/Makefile
	cd build && make


build/Makefile: CMakeLists.txt
	cmake -S . -B ./build -G "Unix Makefiles"

clean:
	rm -rf ./build
	git clean -dfX
run:
	cd build && ./Ivs_Calculator

