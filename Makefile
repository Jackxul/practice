# -*- Makefile  -*-
CC:=g++
CC2:=gcc
CFLAGS = -c -Wall
SRC=${wildcard *.cpp}
SRC2=${wildcard *.c}
OBJ = $(patsubst %.cpp,%.o,$(SRC))
OBJ2 = $(patsubst %.c,%.o,$(SRC))
EXE = $(patsubst %.o,%,$(OBJ))
EXE2 = $(patsubst %.o,%,$(OBJ2))

#$@ 工作目標名稱
#$< 第一個必條件的檔名
#$^ 所有必要條件的檔名
#$* 工作目標的主檔名



$(EXE): $(OBJ)
	@${CC} $(OBJ) -o $@
$(EXE2): $(OBJ2)
	@${CC2} $(OBJ2) -lncurses -o $@
%.o: %.c
	@$(CC2) $(CFLAGS) -c $< -o $@
%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compile $< to $@"
.PHONY: clean
clean:
	rm -rf *.o
