#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
	if (m == 0 || n == 0) {
		printf("Either m or n is zero.\n");
		exit(1);
	} else {
		int r;

		while (n != 0) {
			r = m % n;
			m = n;
			n = r;
		}

		if (m < 0)
			return -m;
		else
			return m;
	}
}

int main(void)
{
	int m, n;

	do {
		printf("Enter the value of the nonzero integer m: ");
		scanf("%d", &m);
	} while (m == 0);
	do {
		printf("Enter the value of the nonzero integer n: ");
		scanf("%d", &n);
	} while (n == 0);

	printf("Greatest common divisor: %d\n", gcd(m, n));

	return 0;
}
