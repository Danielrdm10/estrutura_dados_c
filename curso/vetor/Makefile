CFLAGS = -Wall -Werror

all: rodar

rodar: main.o vetor.o
	gcc main.o vetor.o -o main

vetor.o: vetor.c vetor.h
	gcc $(CFLAGS) -c vetor.c

main.o: main.c vetor.h
	gcc $(CFLAGS) -c main.c

