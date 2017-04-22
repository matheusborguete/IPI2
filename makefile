CC = gcc
CFLAGS = -W -Wall -ansi -pedantic
LDFLAGS=
EXEC = grille

all: $(EXEC)
grille: grille.o main.o
$(CC) -o grille grille.o main.o $(LDFLAGS)
grille.o: grille.c
$(CC) -o grille.o -c grille.c $(CFLAGS)
main.o: main.c grille.h
$(CC) -o main.o -c main.c $(CFLAGS)
clean: rm -rf *.o
mrproper: clean
 rm -rf $(EXEC)
