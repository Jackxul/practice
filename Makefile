# -*-Sub  Makefile  -*-
CC:=g++
CFLAGS = -c -Wall
SRC=${wildcard *.cpp}
OBJ = $(patsubst %.cpp,%.o,$(SRC))
EXE = $(patsubst %.o,%,$(OBJ))
#$@ 工作目標名稱
#$< 第一個必條件的檔名
#$^ 所有必要條件的檔名
#$* 工作目標的主檔名
$(EXE): $(OBJ)
	@${CC} $(OBJ) -o $@


%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf test
