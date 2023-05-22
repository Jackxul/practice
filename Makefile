# -*- Sub Makefile -*-
# Time-stamp: <2016-03-31 16:32:00 kmodi>

CC:=gcc
CFLAGS:=-Wall -c

build:=$(shell mkdir -p build)
build:=$(shell mkdir -p include)
build:=$(shell mkdir -p exe)
B_DIR := build
I_DIR := include
E_DIR := exe
SRC=${wildcard *.c}
OBJ = $(patsubst %.c,$(B_DIR)/%.o,$(SRC))
EXE = $(patsubst $(B_DIR)/%.o,$(E_DIR)/%,$(OBJ))

exe:=start

$(EXE): $(OBJ)
	$(CC) $(OBJ) -lncurses -o $@
	@echo "Makefile: Done."
$(B_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -I $(I_DIR) -c $< -o $@
	@echo  "Building objective file $@ from $< ..."
.PHONY: clean
clean:
	@echo "Makefile_sub : Cleaning up..."
	rm -rf build
	rm -rf exe
	@echo "Makefile: Done."
	@tree .
