#include <stdio.h>

struct complex {
	double real;
	double imaginary;
};

struct complex make_complex(double real, double imaginary);

int main(void)
{
	double real, imaginary;
	struct complex c;

	printf("Enter the real part of a complex number: ");
	scanf("%lf", &real);
	printf("Enter the imaginary part of the complex number: ");
	scanf("%lf", &imaginary);

	c = make_complex(real, imaginary);
	printf("Complex number: %.2f", c.real);
	if (c.imaginary >=0)
		printf(" + %.2fi\n", c.imaginary);
	else
		printf(" - %.2fi\n", -c.imaginary);

	return 0;
}

struct complex make_complex(double real, double imaginary)
{
	return (struct complex) { real, imaginary };
}
