#include <stdio.h>
#include <stdbool.h>

int *find_middle(int n, int a[n]);

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

	printf("Middle element: %d\n", *find_middle(n, a));

	return 0;
}

int *find_middle(int n, int a[n])
{
	return a + (n - 1) / 2;
}
