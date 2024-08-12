#include <stdio.h>

int main(void)
{
	float n, max = .0f;

	while (1) {
		printf("Enter a nonnegative number: ");
		scanf("%f", &n);

		if (max == 0) {
			if (n < 0)
				continue;
			else if (n == 0)
				break;
			else
				max = n;
		} else {
			if (n <= 0)
				break;
			else if (max < n)
				max = n;
		}
	}

	printf("\nThe largest number entered was %.2f\n", max);

	return 0;
}
