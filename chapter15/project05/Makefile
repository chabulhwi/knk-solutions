CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -std=c23

calc: calc.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

calc.o: calc.c stack.h
	$(CC) $(CFLAGS) -c $<

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c $<
