SHELL := /bin/bash
.PHONY: all configure compile format install-dependencies

install-dependencies:
	@echo "Installing required dependencies"
	sudo apt-get install libsfml-dev clang-format

configure:
	@echo "Configuring project"
	cmake -S . -B build

compile:
	@echo "Building project"
	cmake --build build --parallel $(nproc)

format:
	@echo "Formatting code"
	clang-format -style=file -i $(wildcard src/*.cpp src/*.hpp)

all: configure compile
