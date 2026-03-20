#include <stdio.h>
#include <stdbool.h>

void find_two_largest(int n, int a[n], int *largest, int *second_largest);

int main(void)
{
	int n, largest, second_largest;

	do {
		printf("Enter the length of the array: ");
		scanf("%d", &n);
	} while (n <= 0);

	int a[n];

	for (int i = 0; i < n; i++) {
		printf("Enter element %d of the array: ", i);
		scanf("%d", a + i);
	}

	find_two_largest(n, a, &largest, &second_largest);

	printf("Largest: %d\n", largest);
	printf("Second-largest: %d\n", second_largest);

	return 0;
}

/*
 * (a) If the array has only one element, the second largest element equals the
 *     largest one.
 * (b) If all elements in the array are the same, the second largest element
 *     equals the largest one.
 * (c) Otherwise, the second largest element is less than the largest one.
 */
void find_two_largest(int n, int a[n], int *largest, int *second_largest)
{
	*largest = *a;
	*second_largest = *largest;

	for (int i = 1; i < n; i++) {
		if (*largest < *(a + i)) {
			if (*second_largest < *largest)
				*second_largest = *largest;
			*largest = *(a + i);
		} else if (*(a + i) < *largest
			   && (*second_largest == *largest
			       || *second_largest < *(a + i))) {
			*second_largest = *(a + i);
		}
	}
}
