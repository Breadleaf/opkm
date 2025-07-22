ROOT_DIR := $(shell git rev-parse --show-toplevel)
C_SOURCE_DIR := $(ROOT_DIR)/source/
C_HEADER_DIR := $(ROOT_DIR)/headers/

format:
	clang-format -i $(C_SOURCE_DIR)/*.c $(C_HEADER_DIR)/*.h --style Microsoft