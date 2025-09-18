#include <stdio.h>
#include <stdbool.h>

int num_digits(int n)
{
	int count = 0;

	while (1) {
		n /= 10;
		count++;
		if (n == 0)
			break;
	}

	return count;
}

int main(void)
{
	int n;

	printf("Enter an integer: ");
	scanf("%d", &n);

	printf("%d has %d digit", n, num_digits(n));
	if (num_digits(n) != 1)
		putchar('s');
	printf(".\n");

	return 0;
}
