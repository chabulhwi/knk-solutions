#include <stdio.h>

int sum_array(int n, int a[n]);

int main(void)
{
	int n;

	do {
		printf("Enter the length of the array: ");
		scanf("%d", &n);
	} while (n <= 0);

	int a[n];

	for (int i = 0; i < n; i++) {
		printf("Enter element %d of the array: ", i);
		scanf("%d", &a[i]);
	}

	printf("Sum: %d\n", sum_array(n, a));

	return 0;
}

/*
 * I removed the const qualifier because assigning to int * from const int *
 * discards qualifiers.
 */
int sum_array(int n, int a[n])
{
	int sum = 0;

	for (int *p = a; p < a + n; p++)
		sum += *p;

	return sum;
}
