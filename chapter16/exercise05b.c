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

int compare_dates(struct date d1, struct date d2);

int main(void)
{
	struct date d1, d2;

	printf("Enter first date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &d1.month, &d1.day, &d1.year);
	check_range(d1);

	printf("Enter second date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &d2.month, &d2.day, &d2.year);
	check_range(d2);

	switch (compare_dates(d1, d2)) {
	case -1:
		printf("%d/%d/%.4d is earlier than %d/%d/%.4d.\n", d1.month,
		       d1.day, d1.year, d2.month, d2.day, d2.year);
		break;
	case 0:
		printf("The two dates are the same.\n");
		break;
	case 1:
		printf("%d/%d/%.4d is earlier than %d/%d/%.4d.\n", d2.month,
		       d2.day, d2.year, d1.month, d1.day, d1.year);
		break;
	}

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

int compare_dates(struct date d1, struct date d2)
{
	if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
		return 0;
	else if (d1.year < d2.year ||
		 (d1.year == d2.year && d1.month < d2.month) ||
		 (d1.year == d2.year && d1.month == d2.month &&
		  d1.day < d2.day))
		return -1;
	else
		return 1;
}
