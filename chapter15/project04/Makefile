CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -std=c23

remind: remind.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

remind.o: remind.c readline.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<
