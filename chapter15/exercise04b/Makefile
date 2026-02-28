CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -std=c23

testdebug: testdebug.c debug.h
	$(CC) $(CFLAGS) -o $@ $<
