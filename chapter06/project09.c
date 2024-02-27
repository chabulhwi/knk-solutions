#include <stdio.h>

int main(void)
{
	float loan, balance, interest_rate, monthly_interest_rate,
		monthly_payment;
	int n;

	do {
		printf("Enter amount of loan: ");
		scanf("%f", &loan);
	} while (loan < .0f);

	balance = loan;

	do {
		printf("Enter interest rate: ");
		scanf("%f", &interest_rate);
	} while (interest_rate < .0f);

	monthly_interest_rate = interest_rate / 12.0f;

	do {
		printf("Enter monthly payment: ");
		scanf("%f", &monthly_payment);
	} while (monthly_payment < .0f);

	do {
		printf("Enter number of payments: ");
		scanf("%d", &n);
	} while (n < 1);

	printf("\nPayments Balance\n");

	for (int i = 1; i <= n; i++) {
		balance = (1.0f + monthly_interest_rate / 100.0f) * balance -
			monthly_payment;

		if (balance < .0f)
			balance = .0f;

		printf("%-8d $%.2f\n", i, balance);

		if (balance <= .0f)
			break;
	}

	return 0;
}
