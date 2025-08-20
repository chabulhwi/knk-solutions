#include <stdio.h>

#define MEDIAN(x, y, z) ((x) < (y) ? ((y) < (z) ? (y) : ((x) < (z) ? (z) : (x))) : ((x) < (z) ? (x) : ((y) < (z) ? (z) : (y))))

int main(void)
{
	double x, y, z;

	printf("Enter three double values: ");
	scanf("%lf%lf%lf", &x, &y, &z);
	printf("Median: %.2f", MEDIAN(x, y, z));

	return 0;
}
