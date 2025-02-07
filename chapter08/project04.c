/* Reverses a series of numbers using a variable-length array - C99 only */

#include <stdio.h>

#define SIZE ((int) (sizeof(a) / sizeof(a[0])))

int main(void)
{
	int i, n;

	printf("How many numbers do you want to reverse? ");
	scanf("%d", &n);

	int a[n];		// C99 only - length of array depends on n

	printf("Enter %d numbers: ", SIZE);
	for (i = 0; i < SIZE; i++)
		scanf("%d", &a[i]);

	printf("In reverse order:");
	for (i = SIZE - 1; i >= 0; i--)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
