/*
 * When we use the option -std=c89, GCC produces an error message. In order to
 * make it go away, we should add a return statement to the end of the main
 * function.
 */

#include <stdio.h>

int main(void)
{
	printf("hello, world\n");
	return 0;
}
