#include <stdio.h>

struct {
	double real;
	double imaginary;
} c1 = { 0.0, 1.0 }, c2 = { 1.0, 0.0 }, c3;

int main(void)
{
	c1 = c2;

	printf("c1.real: %.1f\n", c1.real);
	printf("c1.imaginary: %.1f\n", c1.imaginary);

	return 0;
}
