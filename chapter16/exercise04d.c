#include <stdio.h>

typedef struct complex {
	double real;
	double imaginary;
} Complex;

Complex add_complex(Complex c1, Complex c2);

int main(void)
{
	Complex c1, c2, sum;

	printf("Enter the real part of the first complex number: ");
	scanf("%lf", &c1.real);
	printf("Enter the imaginary part of the first complex number: ");
	scanf("%lf", &c1.imaginary);

	printf("Enter the real part of the second complex number: ");
	scanf("%lf", &c2.real);
	printf("Enter the imaginary part of the second complex number: ");
	scanf("%lf", &c2.imaginary);

	sum = add_complex(c1, c2);
	printf("Sum: %.2f", sum.real);
	if (sum.imaginary >=0)
		printf(" + %.2fi\n", sum.imaginary);
	else
		printf(" - %.2fi\n", -sum.imaginary);

	return 0;
}

Complex add_complex(Complex c1, Complex c2)
{
	return (Complex) {
		.real = c1.real + c2.real,
		.imaginary = c1.imaginary + c2.imaginary,
	};
}
