IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = pilha.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pilha.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

T_OBJ = testa_pilha.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pilhamake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

testemake: $(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ pilhamke
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ testemake
