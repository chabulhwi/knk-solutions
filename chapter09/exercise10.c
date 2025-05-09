#include <stdio.h>

int max(int n, int a[n]);
double avg(int n, int a[n]);
int num_pos(int n, int a[n]);

int main(void)
{
	int n;

	do {
		printf("Enter the length of the array a of int values: ");
		scanf("%d", &n);
	} while (n <= 0);

	int a[n];

	for (int i = 0; i < n; i++) {
		printf("Enter the value of a[%d]: ", i);
		scanf("%d", &a[i]);
	}

	printf("The largest element in a: %d\n", max(n, a));
	printf("The average of all elements in a: %.2f\n", avg(n, a));
	printf("The number of positive element in a: %d\n", num_pos(n, a));

	return 0;
}

int max(int n, int a[n])
{
	int M = a[0];

	for (int i = 1; i < n; i++) {
		if (M < a[i])
			M = a[i];
	}

	return M;
}

double avg(int n, int a[n])
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += a[i];

	return (double)sum / n;
}

int num_pos(int n, int a[n])
{
	int num = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] > 0)
			num++;
	}

	return num;
}
