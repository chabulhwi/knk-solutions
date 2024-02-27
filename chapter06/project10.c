#include <stdio.h>

int main(void)
{
	int month, day, year, earliest_month, earliest_day, earliest_year;

	do {
		printf("Enter a date (mm/dd/yyyy): ");
		scanf("%2d/%2d/%4d", &month, &day, &year);
	} while (month < 1 || month > 12 || day < 1 || day > 31);

	earliest_month = month;
	earliest_day = day;
	earliest_year = year;

	for (;;) {
		printf("Enter a date (mm/dd/yyyy): ");
		scanf("%2d/%2d/%4d", &month, &day, &year);

		if (month == 0 && day == 0 && year == 0)
			break;
		else if (month < 1 || month > 12 || day < 1 || day > 31)
			continue;

		if (year < earliest_year ||
		    (year == earliest_year && month < earliest_month) ||
		    (year == earliest_year && month == earliest_month &&
		     day < earliest_day)) {
			earliest_month = month;
			earliest_day = day;
			earliest_year = year;
		}
	}

	printf("%d/%d/%.4d is the earliest date\n", earliest_month,
	       earliest_day, earliest_year);

	return 0;
}
