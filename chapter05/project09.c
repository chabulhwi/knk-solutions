#include <stdio.h>

int main(void)
{
	int month1, day1, year1, month2, day2, year2;

	printf("Enter first date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &month1, &day1, &year1);

	printf("Enter second date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &month2, &day2, &year2);

	if (month1 < 1 || month1 > 12 || day1 < 1 || day1 > 31 ||
	    month2 < 1 || month2 > 12 || day2 < 1 || day2 > 31)
		printf("There is an invalid date\n");
	else if (year1 == year2 && month1 == month2 && day1 == day2)
		printf("The two dates are the same\n");
	else if (year1 < year2 || (year1 == year2 && month1 < month2) ||
		 (year1 == year2 && month1 == month2 && day1 < day2))
		printf("%d/%d/%.4d is earlier than %d/%d/%.4d\n",
		       month1, day1, year1, month2, day2, year2);
	else
		printf("%d/%d/%.4d is earlier than %d/%d/%.4d\n",
		       month2, day2, year2, month1, day1, year1);

	return 0;
}
