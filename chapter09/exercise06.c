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

int digit(int n, int k)
{
	if (k <= 0 || num_digits(n) < k) {
		return 0;
	} else {
		for (int i = 1; i < k; i++)
			n /= 10;

		return n % 10;
	}
}

int main(void)
{
	int n, k;

	printf("Enter the values of n and k: ");
	scanf("%d%d", &n, &k);
	printf("digit(%d, %d) = %d\n", n, k, digit(n, k));

	return 0;
}
