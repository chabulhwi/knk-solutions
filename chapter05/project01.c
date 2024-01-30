#include <stdio.h>

int main(void)
{
	int n, digits;

	printf("Enter a number: ");
	scanf("%5d", &n);

	if (-10 < n && n < 10)
		digits = 1;
	else if ((-100 < n && n <= -10) || (10 <= n && n < 100))
		digits = 2;
	else if ((-1000 < n && n <= -100) || (100 <= n && n < 1000))
		digits = 3;
	else if ((-10000 < n && n <= -1000) || (1000 <= n && n < 10000))
		digits = 4;
	else if (10000 <= n && n < 100000)
		digits = 5;

	printf("The number %d has %d digits\n", n, digits);

	return 0;
}
