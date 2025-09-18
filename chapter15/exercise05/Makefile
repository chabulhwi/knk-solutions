CC = gcc
CFLAGS = -g -O -Wall -Wextra -Wpedantic -std=c23

demo: main.o f1.o f2.o
	$(CC) $(CFLAGS) -o $@ $?

main.o: main.c f1.h
	$(CC) $(CFLAGS) -c $<

f1.o: f1.c f1.h f2.h
	$(CC) $(CFLAGS) -c $<

f2.o: f2.c f1.h f2.h
	$(CC) $(CFLAGS) -c $<
