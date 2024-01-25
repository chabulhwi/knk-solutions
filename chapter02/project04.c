#include <stdio.h>

int main(void)
{
	float amount, amount_with_tax;

	printf("Enter an amount: ");
	scanf("%f", &amount);

	amount_with_tax = 1.05f * amount;

	printf("With tax added: $%.2f\n", amount_with_tax);

	return 0;
}
