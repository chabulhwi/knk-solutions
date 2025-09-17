/* Checks numbers for repeated digits */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool repeated_digit_exists = false;
	int repeat_count[10] = { 0 }, digit;
	long n;

	do {
		printf("Enter a nonnegative integer: ");
		scanf("%ld", &n);
	} while (n < 0);

	do {
		digit = n % 10;
		repeat_count[digit]++;
		n /= 10;
	} while (n != 0);

	for (int i = 0; !repeated_digit_exists && i < 10; i++)
		repeated_digit_exists = repeat_count[i] > 1;

	printf("Digit:      ");
	for (int i = 0; i < 10; i++)
		printf("%3d", i);
	putchar('\n');
	printf("Occurrences:");
	for (int i = 0; i < 10; i++)
		printf("%3d", repeat_count[i]);
	putchar('\n');

	if (!repeated_digit_exists)
		printf("No repeated digit\n");

	return 0;
}
