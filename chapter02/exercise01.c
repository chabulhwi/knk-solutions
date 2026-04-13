/*
 * I ran the following command on my Linux machine:
 *
 * gcc -g -O0 -Wall -Wextra -Wpedantic -std=c89 -o exercise01 exercise01.c
 *
 * Here's the warning message that I got from GGC:
 *
 * exercise01.c: In function ‘main’:
 * exercise01.c:15:1: warning: control reaches end of non-void function [-Wreturn-type]
 *    15 | }
 *       | ^
 *
 * To make it go away, I added a return statement to the end of the main
 * function.
 */

#include <stdio.h>

int main(void)
{
	printf("hello, world\n");
	return 0;		/* we need this */
}
