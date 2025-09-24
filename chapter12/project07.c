/* Finds the largest and smallest elements in an array */

#include <stdio.h>

#define N 10

void max_min(int n, int a[n], int *max, int *min);

int main(void)
{
	int b[N], big, small;

	printf("Enter %d numbers: ", N);
	for (int *p = b; p < b + N; p++)
		scanf("%d", p);

	max_min(N, b, &big, &small);

	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);

	return 0;
}

void max_min(int n, int a[n], int *max, int *min)
{
	*max = *min = *a;
	for (int *p = a + 1; p < a + n; p++) {
		if (*p > *max)
			*max = *p;
		else if (*p < *min)
			*min = *p;
	}
}
