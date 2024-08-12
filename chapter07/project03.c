/* Sums a series of numbers (using double variables) */

#include <stdio.h>

int main(void)
{
	double d, sum = .0;

	printf("This program sums a series of double values.\n");
	printf("Enter double values (0 to terminate): ");

	scanf("%lf", &d);
	while (d != .0) {
		sum += d;
		scanf("%lf", &d);
	}
	printf("The sum is: %f\n", sum);

	return 0;
}
