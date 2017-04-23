CC=gcc
CFLAGS=-Wall -Wextra -ansi 
EXEC=grille

all: $(EXEC)

#grille: grille.o main.o maintest.o
grille: grille.o main.o
	$(CC) -o $@ $^ 

grille.o: grille.c
	$(CC) $(CFLAGS) -o $@ -c $< 

main.o: main.c grille.h
	$(CC) $(CFLAGS) -o $@ -c $< 

#maintest.o: maintest.c grille.h
#	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
