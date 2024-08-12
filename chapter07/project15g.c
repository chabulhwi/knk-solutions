/* Computes the factorial of a nonnegative integer */

#include <stdio.h>

int main(void)
{
	long double n, fact = 1.0, num;

	do {
		printf("Enter a nonnegative integer: ");
		scanf("%Lf", &n);
	} while (n < .0);

	for (num = n; num >= 1.0; num--)
		fact *= num;

	/*
	 * 1754 is the largest value of n for which the program correctly prints
	 * the factorial of n.
	 */
	printf("Factorial of %.0Lf: %.6Lg\n", n, fact);

	return 0;
}
