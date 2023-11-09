SRC=./src
BIN=./bin
INC=./inc
OBJ=./obj
CC=g++
CFLAGS= -O3 -g -Wall
Prob=1
N=2
Params= -D NUMBER_OF_ELEMENTS=$(N) -D PROB=$(Prob)

all: $(BIN) $(OBJ) $(BIN)/fem

$(BIN):
	mkdir bin

$(OBJ):
	mkdir obj

$(BIN)/fem: $(OBJ)/fem.o $(OBJ)/element.o $(OBJ)/rod.o
	CC CFLAGS $^ -o $@ -I$(INC) $(Params)

$(OBJ)/fem.o: $(SRC)/fem.cpp $(INC)/dicretize.h $(INC)/element.h $(INC)/rod.h
	CC CFLAGS $< -o $@ -I$(INC) $(Params)

$(OBJ)/element.o: $(SRC)/element.cpp $(INC)/element.h
	CC CFLAGS $< -o $@ -I$(INC) $(Params)

$(OBJ)/rod.o: $(SRC)/rod.cpp $(INC)/dicretize.h $(INC)/element.h $(INC)/rod.h
	CC CFLAGS $< -o $@ -I$(INC) $(Params)

clean:
	$(RM) $(BIN)/*
	$(RM) $(OBJ)/*

.PHONY: clean all