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

	if (num_digits(n) == 1)
		printf("%d has %d digit.\n", n, num_digits(n));
	else
		printf("%d has %d digits.\n", n, num_digits(n));

	return 0;
}
