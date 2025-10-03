CC = gcc
CFLAGS = -g -O -Wall -Wextra -Wpedantic -std=c23

justify: justify.o word.o line.o
	$(CC) $(CFLAGS) -o $@ $^

justify.o: justify.c word.h line.h
	$(CC) $(CFLAGS) -c $<

word.o: word.c word.h
	$(CC) $(CFLAGS) -c $<

line.o: line.c line.h
	$(CC) $(CFLAGS) -c $<
