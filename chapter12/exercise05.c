/*
 * (a) is illegal; the rest of them are all true.
 *
 * Note that the compiler treats p[0] as *(p + 0), which is the same as *p.
 */
#include <stdio.h>

int main(void)
{
	int a[3] = { -6, -5, -4 }, *p;
	p = a;
	printf("Value of p[0]: %d\n", p[0]);

	return 0;
}
