#include <stdio.h>

#define PRODUCT_LT_ONE_HUNDRED(x, y) ((x) * (y) < 100 ? 1 : 0)

int main(void)
{
	printf("2 * 5 < 100: ");
	if (PRODUCT_LT_ONE_HUNDRED(2, 5))
		printf("true\n");
	else
		printf("false\n");

	printf("\"Hi!\" * \"Bye.\" < 100: ");
	if (PRODUCT_LT_ONE_HUNDRED("Hi!", "Bye."))	// this won't work
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
