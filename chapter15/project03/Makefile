CC = gcc
CFLAGS = -g -O -Wall -Wextra -Wpedantic -std=c23

qsort: qsort.o quicksort.o
	$(CC) $(CFLAGS) -o $@ $^

qsort.o: qsort.c quicksort.h
	$(CC) $(CFLAGS) -c $<

quicksort.o: quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c $<
