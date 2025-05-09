/*
 * The function prints the binary representation of the integer entered by the
 * user.
 */

#include <stdio.h>

void pb(int n)
{
	if (n != 0) {
		pb(n / 2);
		putchar('0' + n % 2);
	}
}

int main(void)
{
	int n;

	printf("Enter the value of the integer n: ");
	scanf("%d", &n);

	if (n == 0) {
		putchar('0');
	} else if (n > 0) {
		pb(n);
	} else {
		putchar('-');
		pb(-n);
	}

	putchar('\n');

	return 0;
}
