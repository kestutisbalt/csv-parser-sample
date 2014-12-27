SHELL = /bin/sh

build_dir ?= build
build_type ?= Debug
cmake_dir = $(CURDIR)


all:
	@echo "Usage:"
	@echo "\tmake debug"
	@echo "\tmake release"
	@echo "\tmake clean"
.PHONY: all


build:
	mkdir -p $(build_dir) ; cd $(build_dir) ; \
		cmake -D CMAKE_BUILD_TYPE=$(build_type) \
		$(cmake_dir) ; make
.PHONY: build


debug:
	build_type=Debug build_dir=build/debug $(MAKE) build
.PHONY: debug


release:
	build_type=Release build_dir=build/release $(MAKE) build
.PHONY: release


clean:
	rm -fr $(build_dir)
.PHONY: clean
