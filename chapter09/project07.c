#include <stdio.h>

double power(double x, int n);

int main(void)
{
	double x;
	int n;

	printf("Enter the values for the base x and the exponent n: ");
	scanf("%lf%d", &x, &n);
	printf("x ^ n = %f\n", power(x, n));

	return 0;
}

double power(double x, int n)
{
	if (n == 0) {
		return 1.0;
	} else if (n > 0) {
		if (n % 2 == 0)
			return power(x, n / 2) * power(x, n / 2);
		else
			return x * power(x, n - 1);
	} else {
		return 1.0 / power(x, -n);
	}
}
