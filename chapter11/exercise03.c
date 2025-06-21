#include <stdio.h>

void avg_sum(int n, double a[n], double *avg, double *sum);

int main(void)
{
	int n;
	double avg, sum;

	do {
		printf("Enter the length of the array: ");
		scanf("%d", &n);
	} while (n <= 0);

	double a[n];

	for (int i = 0; i < n; i++) {
		printf("Enter elemenet %d of the array: ", i);
		scanf("%lf", &a[i]);
	}

	avg_sum(n, a, &avg, &sum);

	printf("Average: %.2f\n", avg);
	printf("Sum: %.2f\n", sum);

	return 0;
}

void avg_sum(int n, double a[n], double *avg, double *sum)
{
	*sum = 0.0;

	for (int i = 0; i < n; i++)
		*sum += a[i];

	*avg = *sum / n;
}
