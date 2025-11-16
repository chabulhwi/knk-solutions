#include <stdio.h>

struct fraction {
	int numerator;
	int denominator;
};

int gcd(int m, int n);

struct fraction reduce_fraction(struct fraction f);

int main(void)
{
	struct fraction f;

	while (1) {
		printf("Enter a fraction: ");
		scanf("%d / %d", &f.numerator, &f.denominator);
		if (f.denominator == 0)
			printf("The denominator of the fraction can't be zero.\n");
		else
			break;
	}

	f = reduce_fraction(f);
	printf("Reduced fraction: %d/%d\n", f.numerator, f.denominator);

	return 0;
}

int gcd(int m, int n)
{
	return n == 0 ? m : gcd(n, m % n);
}

struct fraction reduce_fraction(struct fraction f)
{
	int g = gcd(f.numerator, f.denominator);
	struct fraction r = { f.numerator / g, f.denominator / g };

	if (r.denominator < 0) {
		r.numerator *= -1;
		r.denominator *= -1;
	}

	return r;
}
