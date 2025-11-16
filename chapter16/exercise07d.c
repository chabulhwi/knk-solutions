#include <stdio.h>

struct fraction {
	int numerator;
	int denominator;
};

int gcd(int m, int n);

struct fraction reduce_fraction(struct fraction f);

struct fraction mul_fractions(struct fraction f1, struct fraction f2);

int main(void)
{
	struct fraction f1, f2, prod;

	while (1) {
		printf("Enter the first fraction: ");
		scanf("%d / %d", &f1.numerator, &f1.denominator);
		if (f1.denominator == 0)
			printf("The denominator of the fraction can't be zero.\n");
		else
			break;
	}
	while (1) {
		printf("Enter the second fraction: ");
		scanf("%d / %d", &f2.numerator, &f2.denominator);
		if (f2.denominator == 0)
			printf("The denominator of the fraction can't be zero.\n");
		else
			break;
	}

	prod = mul_fractions(f1, f2);
	printf("Product: %d/%d\n", prod.numerator, prod.denominator);

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

struct fraction mul_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction prod = {
		.numerator = f1.numerator * f2.numerator,
		.denominator = f1.denominator * f2.denominator,
	};

	return reduce_fraction(prod);
}
