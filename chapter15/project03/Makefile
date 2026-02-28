CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -std=c23

qsort: qsort.o quicksort.o
	$(CC) $(CFLAGS) -o $@ $^

qsort.o: qsort.c quicksort.h
	$(CC) $(CFLAGS) -c $<

quicksort.o: quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c $<
