#include <stdio.h>

#define DOUBLE(x) 2*x
#define DOUBLE_FIXED(x) (2 * (x))

int main(void)
{
	printf("DOUBLE(1+2) == %d\n", DOUBLE(1 + 2));	// 4
	printf("4/DOUBLE(2) == %d\n", 4 / DOUBLE(2));	// 4
	putchar('\n');
	printf("DOUBLE_FIXED(1 + 2) == %d\n", DOUBLE_FIXED(1 + 2));	// 6
	printf("4 / DOUBLE_FIXED(2) == %d\n", 4 / DOUBLE_FIXED(2));	// 1

	return 0;
}
