#include <stdio.h>

float tax(float income);

int main(void)
{
	float income;

	printf("Enter the amount of taxable income in dollars: ");
	scanf("%f", &income);

	printf("Amount of tax: $%.2f\n", tax(income));

	return 0;
}

float tax(float income)
{
	float result;

	if (income <= 750.00f)
		result = .01f * income;
	else if (income <= 2250.00f)
		result = 7.50f + .02f * (income - 750.00f);
	else if (income <= 3750.00f)
		result = 37.50f + .03f * (income - 2250.00f);
	else if (income <= 5250.00f)
		result = 82.50f + .04f * (income - 3750.00f);
	else if (income <= 7000.00f)
		result = 142.50f + .05f * (income - 5250.00f);
	else
		result = 230.00f + .06f * (income - 7000.00f);

	return result;
}
