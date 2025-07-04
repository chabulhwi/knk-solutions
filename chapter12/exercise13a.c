#include <stdio.h>

int main(void)
{
	int n;

	do {
		printf("Enter the length of the array: ");
		scanf("%d", &n);
	} while (n <= 0);

	double ident[n][n];

	printf("Identity matrix of size %d:\n", n);
	for (double *p = ident[0]; p < ident[n - 1] + n; p++) {
		if ((p - ident[0]) % n == 0)
			printf("  ");

		if ((p - ident[0]) % (n + 1) == 0)
			*p = 1.0;
		else
			*p = 0.0;

		printf("%.0lf", *p);

		if ((p - ident[0]) % n == n - 1)
			putchar('\n');
		else
			putchar(' ');
	}

	return 0;
}
