#include <stdio.h>

int main(void)
{
	int n, d;

	printf("Enter a natural number: ");
	scanf("%d", &n);

	if (n < 0) {
		printf("%d isn't a natural number\n", n);
	} else if (n == 0 || n == 1) {
		printf("%d isn't prime\n", n);
	} else {
		/* modified loop */
		for (d = 2; d * d < n; d++) {
			if (n % d == 0)
				break;
		}

		/* modified if statement */
		if (d * d <= n)
			printf("%d is divisible by %d\n", n, d);
		else
			printf("%d is prime\n", n);
	}

	return 0;
}
