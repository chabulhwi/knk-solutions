/*
 * On my Linux machine, the values of the first and the last int variables are
 * usually 0; the values of the first two float variables are usually 0.000000.
 */

#include <stdio.h>

int main(void)
{
	int i, j, k;
	float x, y, z;

	printf("%d %d %d\n%f %f %f\n", i, j, k, x, y, z);

	return 0;
}
