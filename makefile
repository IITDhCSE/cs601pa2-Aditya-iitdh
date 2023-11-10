SRC=./src
BIN=./bin
INC=./inc
OBJ=./obj
CC=g++
CFLAGS= -O3 -g -Wall
Prob=1
N=2
Params= -D NUMBER_OF_ELEMENTS=$(N) -D PROB=$(Prob)
eigen= -I /home/resiliente/cs601software/eigen-3.3.9/

all: $(BIN) $(OBJ) $(BIN)/fem

$(BIN):
	mkdir bin

$(OBJ):
	mkdir obj

$(BIN)/fem: $(SRC)/fem.cpp $(INC)/discretize.h $(OBJ)/element.o $(OBJ)/rod.o
	$(CC) $(CFLAGS) $^ -o $@ -I$(INC) $(Params)

$(OBJ)/fem.o: $(SRC)/fem.cpp $(INC)/discretize.h $(INC)/element.h $(INC)/rod.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC) $(Params) $(eigen)

$(OBJ)/element.o: $(SRC)/element.cpp $(INC)/element.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC) $(eigen)

$(OBJ)/rod.o: $(SRC)/rod.cpp $(INC)/discretize.h $(INC)/element.h $(INC)/rod.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC) $(Params) $(eigen)

clean:
	$(RM) $(BIN)/*
	$(RM) $(OBJ)/*

.PHONY: clean all