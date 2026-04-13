#include <stdio.h>

int main(void)
{
	float x, polynomial;

	printf("Enter a floating-point number: ");
	scanf("%f", &x);

	polynomial = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

	printf("The value of the polynomial\n");
	printf("((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6\n");
	printf("is %.3f\n", polynomial);

	return 0;
}
