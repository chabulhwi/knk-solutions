#include <stdio.h>

int gcd(int m, int n)
{
	return n == 0 ? m : gcd(n, m % n);
}

int main(void)
{
	int m, n;

	do {
		printf("Enter the value of the nonnegative integer m: ");
		scanf("%d", &m);
	} while (m < 0);
	do {
		printf("Enter the value of the nonnegative integer n: ");
		scanf("%d", &n);
	} while (n < 0);

	printf("Greatest common divisor: %d\n", gcd(m, n));

	return 0;
}
