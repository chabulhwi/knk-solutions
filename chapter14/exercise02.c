#include <stdio.h>

#define NELEMS(a) (sizeof(a) / sizeof(a[0]))

int main(void)
{
	char abc[3] = { 'a', 'b', 'c' };

	printf("The array { 'a', 'b', 'c' } has %zu element(s).\n",
	       NELEMS(abc));

	return 0;
}
