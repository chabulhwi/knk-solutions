/* Computes the factorial of a nonnegative integer */

#include <stdio.h>

long fact(long n)
{
	return n == 0 ? 1 : n * fact(n - 1);
}

int main(void)
{
	long n;

	do {
		printf("Enter a nonnegative integer: ");
		scanf("%ld", &n);
	} while (n < 0);

	/*
	 * On my computer, 20 is the largest value of n for which the program
	 * correctly prints the factorial of n.
	 */
	printf("Factorial of %ld: %ld\n", n, fact(n));

	return 0;
}
