#include <stdio.h>

int main(void)
{
	int m, n, r, gcd;

	do {
		printf("Enter two nonzero integers: ");
		scanf("%d%d", &m, &n);
	} while (m == 0 || n == 0);

	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}

	if (m < 0)
		gcd = -m;
	else
		gcd = m;

	printf("Greatest common divisor: %d\n", gcd);

	return 0;
}
