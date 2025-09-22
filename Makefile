.PHONY: all build clean

all: build

build:
	cmake -S . -B build
	cmake --build build -j

clean:
	rm -rf build
