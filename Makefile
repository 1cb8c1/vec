build:
	cmake -B build
	cmake --build build

clean:
	rm -rf build

install:
	sudo cmake --install build
