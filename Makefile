CC = g++ -I ./include
CFLAGS = -std=c++14 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
BIN = ./bin
OBJ = ./obj

EXECS = mkpaths dnasequencer 

all: mkpaths $(EXECS)

mkpaths:
	mkdir -p $(OBJ) $(BIN)

$(OBJ)/algorithms.o: $(SRC)/algorithms.cpp $(INC)/algorithms.h
	$(CC) $(CFLAGS) -c $(SRC)/algorithms.cpp -o $(OBJ)/algorithms.o

$(OBJ)/sequence.o: $(SRC)/sequence.cpp $(INC)/sequence.h
	$(CC) $(CFLAGS) -c $(SRC)/sequence.cpp -o $(OBJ)/sequence.o

dnasequencer: $(SRC)/dnasequencer.cpp $(OBJ)/algorithms.o $(OBJ)/sequence.o
	$(CC) $(CFLAGS) $(OBJ)/sequence.o $(OBJ)/algorithms.o $(SRC)/dnasequencer.cpp -o $(BIN)/dnasequencer 

all: $(EXECS)

.PHONY: clean
clean:
	rm -rf $(OBJ)/* $(BIN)/* *.dSYM $(EXECS)
