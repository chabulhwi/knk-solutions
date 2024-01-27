#include <stdio.h>

int main(void)
{
	float loan, interest_rate, monthly_interest_rate, monthly_payment,
		balance;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);

	monthly_interest_rate = interest_rate / 12.0f;

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	balance = (1.0f + monthly_interest_rate / 100.0f) * loan -
		monthly_payment;
	printf("Balance remaining after first payment: $%.2f\n", balance);

	balance = (1.0f + monthly_interest_rate / 100.0f) * balance -
		monthly_payment;
	printf("Balance remaining after second payment: $%.2f\n", balance);

	balance = (1.0f + monthly_interest_rate / 100.0f) * balance -
		monthly_payment;
	printf("Balance remaining after third payment: $%.2f\n", balance);

	return 0;
}
