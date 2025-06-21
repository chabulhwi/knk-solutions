#include <stdio.h>
#include <stdbool.h>

#define MONTHS 12

void split_date(int day_of_year, int year, int *month, int *day);

int days_of_month[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool year_is_leap_year;

int main(void)
{
	int day_of_year, year, month, day;

	do {
		printf("Enter a year: ");
		scanf("%d", &year);
	} while (year < 0);

	do {
		printf("Enter a day of the year: ");
		scanf("%d", &day_of_year);
	} while (day_of_year < 1 || day_of_year > 366);

	split_date(day_of_year, year, &month, &day);

	printf("Date (mm/dd/yyyy): %.2d/%.2d/%.4d\n", month, day, year);

	return 0;
}

void split_date(int day_of_year, int year, int *month, int *day)
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
		year_is_leap_year = true;
		days_of_month[1] = 29;	// February has 29 days in a leap year
	} else {
		year_is_leap_year = false;
	}

	for (int m = 0; m < MONTHS; m++) {
		if (day_of_year <= days_of_month[m]) {
			*month = m + 1;
			*day = day_of_year;
			break;
		} else {
			day_of_year -= days_of_month[m];
		}
	}
}
