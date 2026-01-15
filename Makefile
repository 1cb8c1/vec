build:
	cmake -B build
	cmake --build build

test:
	cmake -B build
	cmake --build build
	ctest --test-dir build

clean:
	rm -rf build

install:
	sudo cmake --install build
