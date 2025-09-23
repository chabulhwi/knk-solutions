#include <stdio.h>
#include <stdbool.h>

void store_zeros(int n, int a[n]);

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

	printf("The contents of the array a:");
	for (int i = 0; i < n; i++)
		printf(" %d", a[i]);
	putchar('\n');

	store_zeros(n, a);

	printf("The program will store zero into each of its elements.\n");
	printf("The contents of the array a:");
	for (int i = 0; i < n; i++)
		printf(" %d", a[i]);
	putchar('\n');

	return 0;
}

void store_zeros(int n, int a[n])
{
	for (int *p = a; p < a + n; p++)
		*p = 0;
}
