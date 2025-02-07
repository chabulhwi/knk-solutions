/* Prints a table of compound interest */

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
	int low_rate, num_years;
	double value[5];

	while (1) {
		printf("Enter integer value for interest rate: ");
		scanf("%d", &low_rate);
		if (low_rate <= -1000)
			printf("The value should be greater than -1000.\n");
		else if (low_rate >= 996)
			printf("The value should be less than 996.\n");
		else
			break;
	}

	while (1) {
		printf("Enter number of years: ");
		scanf("%d", &num_years);
		if (num_years < 0)
			printf("The number should not be negative.\n");
		else if (num_years >= 10000)
			printf("The number should be less than 10,000.\n");
		else
			break;
	}

	printf("\nYears");
	for (int i = 0; i < NUM_RATES; i++) {
		printf("\t%8d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

	for (int year = 0; year <= num_years; year++) {
		printf("%5d", year);
		for (int i = 0; i < NUM_RATES; i++) {
			printf("\t %8.2f", value[i]);
			for (int month = 1; month <= 12; month++)
				value[i] += ((double)(low_rate + i) / 12) /
					100.0 * value[i];
		}
		printf("\n");
	}

	return 0;
}
