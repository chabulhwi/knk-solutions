/* Computes the factorial of a nonnegative integer */

#include <stdio.h>

int main(void)
{
	double n, fact = 1.0, num;

	do {
		printf("Enter a nonnegative integer: ");
		scanf("%lf", &n);
	} while (n < .0);

	for (num = n; num >= 1.0; num--)
		fact *= num;

	/*
	 * 170 is the largest value of n for which the program correctly prints
	 * the factorial of n.
	 */
	printf("Factorial of %.0f: %.6g\n", n, fact);

	return 0;
}
