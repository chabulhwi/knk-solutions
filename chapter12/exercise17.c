#include <stdio.h>

int sum_two_dimensional_array(int m, int n, int a[m][n]);

int main(void)
{
	int m, n;

	do {
		printf("Enter the number of the rows: ");
		scanf("%d", &m);
	} while (m <= 0);

	do {
		printf("Enter the number of the columns: ");
		scanf("%d", &n);
	} while (n <= 0);

	int a[m][n];

	for (int *p = a[0]; p < a[m - 1] + n; p++) {
		printf("Enter the value of a[%d][%d]: ", (int)(p - a[0]) / n,
		       (int)(p - a[0]) % n);
		scanf("%d", p);
	}

	printf("\nThe contents of the array:\n");
	for (int *p = a[0]; p < a[m - 1] + n; p++) {
		printf("%8d", *p);

		if ((p - a[0]) % n == n - 1)
			putchar('\n');
		else
			putchar('\t');
	}

	printf("\nSum: %d\n", sum_two_dimensional_array(m, n, a));

	return 0;
}

/*
 * I removed the const qualifier because assigning to int * from const int *
 * discards qualifiers.
 */
int sum_two_dimensional_array(int m, int n, int a[m][n])
{
	int sum = 0;

	for (int *p = a[0]; p < a[m - 1] + n; p++) {
		sum += *p;
	}

	return sum;
}
