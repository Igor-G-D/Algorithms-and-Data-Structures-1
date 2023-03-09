main.o: main.c
	gcc -g -c main.c
library.o: library.c -lm
	gcc -g -c library.c
all: library.o main.o -lm
	gcc library.o main.o -g -o Ex_4
valgrind: all 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./Ex_4