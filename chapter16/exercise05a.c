#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct date {
	int month;
	int day;
	int year;
};

void check_range(struct date d);

bool leap_year(int year);

int days_of_month(int month, int year);

int day_of_year(struct date d);

int main(void)
{
	struct date d;

	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &d.month, &d.day, &d.year);
	check_range(d);
	printf("Day of the year: %d\n", day_of_year(d));

	return 0;
}

void check_range(struct date d)
{
	if (d.month < 1 || d.month > 12 || d.day < 1 ||
	    d.day > days_of_month(d.month, d.year) || d.year < 0) {
		printf("You entered an invalid date.\n");
		exit(EXIT_FAILURE);
	}
}

bool leap_year(int year)
{
	/*
	 * A viewer of my Chzzk stream told me how to simplify the cascaded
	 * if-else statement. Thanks!
	 */
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false;
}

int days_of_month(int month, int year)
{
	switch (month) {
	case 1:
		return 31;
	case 2:
		if (leap_year(year))
			return 29;	// February has 29 days in a leap year
		else
			return 28;
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		return 31;
	default:
		printf("You entered an invalid date.\n");
		exit(EXIT_FAILURE);
	}
}

int day_of_year(struct date d)
{
	int days = 0;
	for (int i = 1; i < d.month; i++)
		days += days_of_month(i, d.year);
	days += d.day;

	return days;
}
