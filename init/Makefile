CC := clang
CFLAGS = -std=gnu2x -static -O0 -g
CFLAGS += -Wall -Wextra -Wvla -Wshadow -ffreestanding -nostdlib -nodefaultlibs -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter

C_SOURCES = $(shell find . -name "*.c")

init: $(C_SOURCES)
	clang $(CFLAGS) $^ -o $@
