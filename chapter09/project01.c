#include <stdio.h>

void selection_sort(int n, int a[n], int k);

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

	printf("You entered:\n");
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0)
			printf("  ");

		printf("%d", a[i]);

		if (i % 10 == 9)
			putchar('\n');
		else
			putchar(' ');

	}
	printf("\n");

	selection_sort(n, a, n);

	printf("Result of sorting:\n");
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0)
			printf("  ");

		printf("%d", a[i]);

		if (i % 10 == 9)
			putchar('\n');
		else
			putchar(' ');

	}
	printf("\n");

	return 0;
}

void selection_sort(int n, int a[n], int k)
{
	int max = a[0], idx = 0;

	if (k <= 1)
		return;

	if (k > n)
		k = n;

	for (int i = 1; i < k; i++) {
		if (max < a[i]) {
			max = a[i];
			idx = i;
		}
	}

	if (k > 1) {
		a[idx] = a[k - 1];
		a[k - 1] = max;
		selection_sort(n, a, k - 1);
	}
}
