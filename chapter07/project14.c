/* Computes the square root of a positive floating-point number */

#include <math.h>
#include <stdio.h>

int main(void)
{
	double pos, sqrt = 1.0;

	printf("Enter a positive floating-point number: ");
	scanf("%lf", &pos);

	while (fabs(pos / sqrt - sqrt) / 2.0 >= .000001)
		sqrt = (sqrt + pos / sqrt) / 2.0;

	printf("Square root: %.5f\n", sqrt);

	return 0;
}
