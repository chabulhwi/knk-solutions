CC = gcc
CFLAGS = -g -O -Wall -Wextra -Wpedantic -std=c23

calc: calc.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

calc.o: calc.c stack.h
	$(CC) $(CFLAGS) -c $<

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c $<
