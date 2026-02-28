CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -std=c23

inventory: inventory.o readline.o qsort.o
	$(CC) $(CFLAGS) -o $@ $^

inventory.o: inventory.c readline.h qsort.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<

qsort.o: qsort.c qsort.h
	$(CC) $(CFLAGS) -c $<
