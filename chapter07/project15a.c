/* Computes the factorial of a nonnegative integer */

#include <stdio.h>

int main(void)
{
	short n, fact = 1, num;

	do {
		printf("Enter a nonnegative integer: ");
		scanf("%hd", &n);
	} while (n < 0);

	for (num = n; num >= 1; num--)
		fact *= num;

	/*
	 * On my computer, 7 is the largest value of n for which the program
	 * correctly prints the factorial of n.
	 */
	printf("Factorial of %hd: %hd\n", n, fact);

	return 0;
}
