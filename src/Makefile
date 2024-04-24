.PHONY: all clean run dependencies build/Ivs_Calculator pack prof doc install uninstall

all: dependencies build/Ivs_Calculator doc pack 

build/Ivs_Calculator: build/Makefile
	cd build && make --no-print-directory

pack: build/Ivs_Calculator doc
	cd build && cpack -G DEB

build/Makefile: CMakeLists.txt 
	cmake -S . -B ./build -G "Unix Makefiles"

clean:
	rm -rf ./build
	git clean -dfX
run: build/Ivs_Calculator
	cd build && ./Ivs_Calculator

dependencies: 
	sudo apt install -y qt6-base-dev cmake build-essential libgl1-mesa-dev qt6-multimedia-dev libqt6svg6-dev doxygen

prof: build/Makefile
	cd build && make stddev --no-print-directory

doc:
	doxygen

install: build/Ivs_Calculator
	cd build && sudo make install

uninstall: install
	cd build && sudo xargs rm < install_manifest.txt
