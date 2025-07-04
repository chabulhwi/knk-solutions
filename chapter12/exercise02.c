/* You can't add a pointer to another, but you can subtract one from another. */
#include <stdio.h>

int main(void)
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *low = &a[0], *middle, *high = &a[9];

	middle = low + (int)(high - low) / 2;

	printf("Value of *middle: %d\n", *middle);

	return 0;
}
