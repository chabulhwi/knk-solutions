#include <stdio.h>

int main(void)
{
	float x, polynomial;

	printf("Enter a value for a variable x: ");
	scanf("%f", &x);

	polynomial = (3 * x * x * x * x * x) + (2 * x * x * x * x) -
		(5 * x * x * x) - (x * x) + (7 * x) - 6;

	printf("The value of the polynomial\n");
	printf("3 * x ^ 5 + 2 * x ^ 4 - 5 * x ^ 3 - x ^ 2 + 7 * x - 6\n");
	printf("is %.3f\n", polynomial);

	return 0;
}
