#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MONTHS 12

int days_of_month[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool year_is_leap_year;

int day_of_year(int month, int day, int year)
{
	/*
	 * A viewer of my Chzzk stream told me how to simplify the cascaded
	 * if-else statement. Thanks!
	 */
	if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0) {
		printf("Some of the arguments have incorrect values.\n");
		exit(1);
	} else if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
		year_is_leap_year = true;
		days_of_month[1] = 29;	// February has 29 days in a leap year
	} else {
		year_is_leap_year = false;
	}

	int days = 0;
	for (int i = 1; i < month; i++)
		days += days_of_month[i - 1];
	days += day;

	return days;
}

int main(void)
{
	int month, day, year;

	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("Day of the year: %d\n", day_of_year(month, day, year));

	return 0;
}
