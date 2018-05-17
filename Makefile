acervo = ./bin/acervo

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc
LIB_DIR = ./lib

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11

OBJS = ./build/main.o ./build/Data.o ./build/Midia.o ./build/Livro.o ./build/CD.o

acervo: $(acervo)

$(acervo): CPPFLAGS += -I. -I./include/
$(acervo): $(OBJS)
	$(CC) $^ $(CPPFLAGS) -o $@

./build/main.o: ./src/main.cpp ./include/Midia.h
	$(CC) -c $(CPPFLAGS) $<	-o $@

./build/Data.o: ./src/Data.cpp ./include/Data.h
	$(CC) -c $(CPPFLAGS) $< -o $@

./build/Midia.o: ./src/Midia.cpp ./include/Midia.h ./include/Data.h
	$(CC) -c $(CPPFLAGS) $< -o $@

./build/Livro.o: ./src/Livro.cpp ./include/Livro.h
	$(CC) -c $(CPPFLAGS) $< -o $@

./build/CD.o: ./src/CD.cpp ./include/CD.h
	$(CC) -c $(CPPFLAGS) $< -o $@

debug: CPPFLAGS += -g -O0
debug: acervo

dir:
	mkdir -p bin
	mkdir -p build
	mkdir -p data
	mkdir -p include
	mkdir -p src
	mkdir -p doc
	mkdir -p lib
	mkdir -p test

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	
	
