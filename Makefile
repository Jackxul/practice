# -*- Sub Makefile -*-
# Time-stamp: <2016-03-31 16:32:00 kmodi>

CC:=gcc
CFLAGS:=-Wall -c

build:=$(shell mkdir -p build)
build:=$(shell mkdir -p include)
B_DIR := build
I_DIR := include
SRC=${wildcard *.c}
OBJ = $(patsubst %.c,$(B_DIR)/%.o,$(SRC))

exe:=start

$(exe): $(OBJ)
	$(CC) $(OBJ) -lncurses -o $@
	@echo "Makefile: Done."
$(B_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -I $(I_DIR) -c $< -o $@
	@echo  "Building objective file $@ from $< ..."
.PHONY: clean
clean:
	@echo "Makefile_sub : Cleaning up..."
	rm -rf build
	rm ./start
	@echo "Makefile: Done."
	@tree .
