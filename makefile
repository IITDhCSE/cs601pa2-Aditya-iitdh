SRC=./src
BIN=./bin
INC=./inc
OBJ=./obj
CC=g++
CFLAGS= -O3 -g -Wall
PROB=1
N=2
Params= -D NUMBER_OF_ELEMENTS=$(N) -D PROB=$(PROB)
eigen= -I /home/resiliente/cs601software/eigen-3.3.9/

all: $(BIN) $(OBJ) fem

$(BIN):
	mkdir bin

$(OBJ):
	mkdir obj

fem: fem.o element.o rod.o
	$(CC) $(CFLAGS) $(OBJ)/* -o $(BIN)/$@ -I$(INC)
	$(BIN)/fem

# $(INC)/computation.h
fem.o: $(SRC)/fem.cpp $(INC)/element.h $(INC)/rod.h
	$(CC) -c $(CFLAGS) $< -o $(OBJ)/$@ -I$(INC) $(eigen) $(Params)

element.o: $(SRC)/element.cpp $(INC)/element.h 
	$(CC) -c $(CFLAGS) $< -o $(OBJ)/$@ -I$(INC) $(eigen)

rod.o: $(SRC)/rod.cpp $(INC)/element.h $(INC)/rod.h
	$(CC) -c $(CFLAGS) $< -o $(OBJ)/$@ -I$(INC) $(eigen)

clean:
	$(RM) $(BIN)/*
	$(RM) $(OBJ)/*

.PHONY: clean all fem fem.o element.o rod.o