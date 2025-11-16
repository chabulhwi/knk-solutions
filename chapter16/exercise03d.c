#include <stdio.h>

struct complex {
	double real;
	double imaginary;
};

struct complex add_complex(struct complex c1, struct complex c2);

int main(void)
{
	struct complex c1, c2, sum;

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

struct complex add_complex(struct complex c1, struct complex c2)
{
	return (struct complex) {
		.real = c1.real + c2.real,
		.imaginary = c1.imaginary + c2.imaginary,
	};
}
