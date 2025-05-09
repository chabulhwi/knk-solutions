#include <stdio.h>
#include <stdbool.h>

double median(double x, double y, double z)
{
	double max12, min12, mid;

	if (x <= y) {
		max12 = y;
		min12 = x;
	} else {
		max12 = x;
		min12 = y;
	}

	if (max12 <= z)
		mid = max12;
	else if (min12 <= z)
		mid = z;
	else
		mid = min12;

	return mid;
}

int main(void)
{
	double x, y, z;

	printf("Enter the values of x, y, and z: ");
	scanf("%lf%lf%lf", &x, &y, &z);

	printf("The median is %.2f.\n", median(x, y, z));

	return 0;
}
