#include <stdio.h>

#define NUM_MONTHS 12

int main(void)
{
	char *month_name[NUM_MONTHS] = {
		"January", "February", "March", "April", "May", "June", "July",
		"August", "September", "October", "November", "December"
	};
	int month, day, year;

	while (1) {
		printf("Enter a date (mm/dd/yyyy): ");
		scanf("%2d/%2d/%4d", &month, &day, &year);

		if (month < 1 || month > 12 || day < 1 || day > 31)
			printf("Invalid date\n");
		else
			break;
	}

	printf("You entered the date %s %d, %d", month_name[month - 1], day,
	       year);

	return 0;
}
