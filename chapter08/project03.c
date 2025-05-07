/* Checks numbers for repeated digits */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool repeated_digit_exists = false;
	int repeat_count[10], digit;
	long n;

	while (1) {
		for (int i = 0; i < 10; i++)
			repeat_count[i] = 0;

		printf("Enter a positive integer: ");
		scanf("%ld", &n);

		if (n <= 0) {
			break;
		} else {
			do {
				digit = n % 10;
				repeat_count[digit]++;
				n /= 10;
			} while (n != 0);

			for (int i = 0; !repeated_digit_exists && i < 10; i++)
				repeated_digit_exists = repeat_count[i] > 1;

			if (repeated_digit_exists) {
				printf("Repeated digit(s):");
				for (int i = 0; i < 10; i++) {
					if (repeat_count[i] > 1)
						printf(" %d", i);
				}
				putchar('\n');
			} else {
				printf("No repeated digit\n");
			}
		}
	}

	return 0;
}
