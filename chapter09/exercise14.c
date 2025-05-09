/*
 * Suppose that the length of the array a is 2, the first element is nonzero,
 * and the second is zero. The function will return false, even though that the
 * array a has a zero element.
 *
 * I fixed the definition of the function as follows.
 */
#include <stdio.h>
#include <stdbool.h>

bool has_zero(int n, int a[n])
{
	int i;

	for (i = 0; i < n; i++) {
		if (a[i] == 0)
			return true;
	}

	return false;
}

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

	if (has_zero(n, a))
		printf("The array a has an element whose value is zero.\n");
	else
		printf("All elements in the array a are nonzero.\n");

	return 0;
}
