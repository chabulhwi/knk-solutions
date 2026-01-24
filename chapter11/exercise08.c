#include <stdio.h>
#include <stdbool.h>

int *find_largest(int n, int a[n]);

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

	printf("Largest element: %d\n", *find_largest(n, a));

	return 0;
}

int *find_largest(int n, int a[n])
{
	int *max = &a[0];

	for (int i = 1; i < n; i++) {
		if (*max < a[i])
			max = &a[i];
	}

	return max;
}
