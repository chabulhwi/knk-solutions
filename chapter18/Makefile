CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -std=c23

exercise09%: exercise09%.c
	$(CC) $(CFLAGS) -fsyntax-only $<

exercise10: exercise10.c
	$(CC) $(CFLAGS) -fsyntax-only $<

exercise11: exercise11.c
	$(CC) $(CFLAGS) -fsyntax-only $<

exercise12: exercise12.c
	$(CC) $(CFLAGS) -fsyntax-only $<

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
