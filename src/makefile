IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = pilha.h catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pilha.o pilha_vector.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: list vector

list: testa_pilha.cpp pilha.c
	g++ -std=c++11 -o list -ftest-coverage -fprofile-arcs testa_pilha.cpp pilha.c -I../include

vector: testa_pilha.cpp pilha_vector.c
	g++ -std=c++11 -o vector -ftest-coverage -fprofile-arcs testa_pilha.cpp pilha_vector.c -I../include	
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
