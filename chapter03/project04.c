#include <stdio.h>

int main(void)
{
	int area_code, central_office_code, line_number;

	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d) %d-%d", &area_code, &central_office_code, &line_number);

	printf("You entered %.3d.%.3d.%.4d\n", area_code, central_office_code,
	       line_number);

	return 0;
}
