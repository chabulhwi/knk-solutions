/* Computes the factorial of a nonnegative integer */

#include <stdio.h>

int main(void)
{
	long n, fact = 1, num;

	do {
		printf("Enter a nonnegative integer: ");
		scanf("%ld", &n);
	} while (n < 0);

	for (num = n; num >= 1; num--)
		fact *= num;

	/*
	 * 20 is the largest value of n for which the program correctly prints
	 * the factorial of n.
	 */
	printf("Factorial of %ld: %ld\n", n, fact);

	return 0;
}
