/* Computes the factorial of a nonnegative integer */

#include <stdio.h>

int main(void)
{
	float n, fact = 1.0f, num;

	do {
		printf("Enter a nonnegative integer: ");
		scanf("%f", &n);
	} while (n < .0f);

	for (num = n; num >= 1.0f; num--)
		fact *= num;

	/*
	 * On my computer, 34 is the largest value of n for which the program
	 * correctly prints the factorial of n.
	 */
	printf("Factorial of %.6g: %.6g\n", n, fact);

	return 0;
}
