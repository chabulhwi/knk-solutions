#include <stdio.h>

int main(void)
{
	int n, start_day;

	do {
		printf("Enter number of days in month: ");
		scanf("%d", &n);
	} while (n < 28 || n > 31);

	do {
		printf("Enter starting day of the week (1=Sun, 7=Sat): ");
		scanf("%1d", &start_day);
	} while (start_day < 1 || start_day > 7);

	printf("\nSu Mo Tu We Th Fr Sa\n");

	/* print leading blanks */
	for (int i = 1; i < start_day; i++)
		printf("   ");

	/* print dates */
	for (int i = 1; i < n; i++) {
		if ((start_day + i - 1) % 7 == 0)
			printf("%2d\n", i);
		else
			printf("%2d ", i);
	}
	printf("%d\n", n);

	return 0;
}
