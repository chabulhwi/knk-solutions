CC = gcc
CFLAGS = -g -O -Wall -Wextra -Wpedantic -std=c23

remind: remind.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

remind.o: remind.c readline.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<
