#include <stdio.h>

double triangle_area(double base, double height)
{
	double product = base * height;
	return product / 2;
}

int main(void)
{
	double base, height;

	printf("Enter the length of the base of the triangle: ");
	scanf("%lf", &base);
	printf("Enter the length of the height of the triangle: ");
	scanf("%lf", &height);

	printf("The area of the triangle: %.2f\n", triangle_area(base, height));

	return 0;
}
