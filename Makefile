# Definitii de variabile utile

# Folderul care contine biblioteca gplot 
LIBDIR = $(shell pwd)

# Compilatorul
CC = gcc

# Optiuni de compilare
CFLAGS = -O2

# Bibliotecile externe
LIBS = -gslcblas -lgsl -lm

all: gplot exBessel
clean: 
	rm -f gplot.o libgplot.so exBesselI0
gplot: gplot.h gplot.c
	$(CC) -o gplot.o -c gplot.c -fpic
	$(CC) -shared gplot.o -o libgplot.so
