CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -std=c23

inventory: inventory.o readline.o compare.o
	$(CC) $(CFLAGS) -o $@ $^

inventory.o: inventory.c readline.h compare.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<

compare.o: compare.c compare.h
	$(CC) $(CFLAGS) -c $<
