#include <stdio.h>

double inner_product(int n, double a[n], double b[n])
{
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}

	return sum;
}

int main(void)
{
	int n;

	do {
		printf("Enter the length of the arrays a and b: ");
		scanf("%d", &n);
	} while (n <= 0);

	double a[n], b[n];

	for (int i = 0; i < n; i++) {
		printf("Enter the value of a[%d]: ", i);
		scanf("%lf", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("Enter the value of b[%d]: ", i);
		scanf("%lf", &b[i]);
	}

	printf("The inner product of a and b: %.2f\n", inner_product(n, a, b));

	return 0;
}
