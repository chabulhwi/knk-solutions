/*
 * If the user enters 12abc34 56def78, the values of i, s and j after the call
 * will be as follows:
 *
 * i: 12
 * s: abc34
 * j: 56
 */

#include <stdio.h>

int main(void)
{
	int i, j;
	char *s;

	scanf("%d%s%d", &i, s, &j);
	printf("i: %d\n", i);
	printf("s: %s\n", s);
	printf("j: %d\n", j);

	return 0;
}
