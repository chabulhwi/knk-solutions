CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -std=c23

inventory2: inventory2.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

inventory2.o: inventory2.c readline.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<
