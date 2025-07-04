#include <stdio.h>

int main(void)
{
	int n;
	double *p;

	do {
		printf("Enter the length of the array: ");
		scanf("%d", &n);
	} while (n <= 0);

	double ident[n][n];

	p = ident[0];
	*p = 1.0;
	while (p < ident[n - 1] + n - 1) {
		for (int i = 0; i < n; i++)
			*++p = 0.0;

		*++p = 1.0;
	}

	printf("Identity matrix of size %d:\n", n);
	for (p = ident[0]; p < ident[n - 1] + n; p++) {
		if ((p - ident[0]) % n == 0)
			printf("  ");

		printf("%.0lf", *p);

		if ((p - ident[0]) % n == n - 1)
			putchar('\n');
		else
			putchar(' ');
	}

	return 0;
}
