#include <stdio.h>

int main(void)
{
	int n;
	float current_term, sum;

	do {
		printf("Enter a nonnegative integer: ");
		scanf("%d", &n);
	} while (n < 0);

	printf("The %d", n + 1);

	switch ((n + 1) % 10) {
	case 1:
		if ((n + 1) % 100 == 11)
			printf("th");
		else
			printf("st");
		break;
	case 2:
		if ((n + 1) % 100 == 12)
			printf("th");
		else
			printf("nd");
		break;
	case 3:
		if ((n + 1) % 100 == 13)
			printf("th");
		else
			printf("rd");
		break;
	default:
		printf("th");
		break;
	}

	current_term = 1.0f;
	sum = 1.0f;

	for (int i = 1; i <= n; i++) {
		current_term /= i;
		sum += current_term;
	}

	printf(" partial sum of the series is %f\n", sum);

	return 0;
}
