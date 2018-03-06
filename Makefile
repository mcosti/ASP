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
	rm -f gplot.o libgplot.so exBesselJ0
gplot: gplot.h gplot.c
	$(CC) -o gplot.o -c gplot.c -fpic
	$(CC) -shared gplot.o -o libgplot.so
exBessel: gplot.h gplot.o
	LD_LIBRARY_PATH=$(LIBS) $(CC) -o exBesselJ0 ex2.c $(LIBS) -L $(LIBDIR) -lgplot
	
