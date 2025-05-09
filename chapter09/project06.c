#include <stdio.h>

double power(double x, int n);
double polynomial(double x);

int main(void)
{
	double x;

	printf("Enter the values for the variable x: ");
	scanf("%lf", &x);
	printf("The value of the polynomial: %f\n", polynomial(x));

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

double polynomial(double x)
{
	return 3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2)
		+ 7 * x - 6;
}
