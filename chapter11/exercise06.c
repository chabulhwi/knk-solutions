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
		scanf("%d", &a[i]);
	}

	find_two_largest(n, a, &largest, &second_largest);

	printf("Largest: %d\n", largest);
	printf("Second-largest: %d\n", second_largest);

	return 0;
}

void find_two_largest(int n, int a[n], int *largest, int *second_largest)
{
	int largest_count = 0;

	*largest = a[0];
	for (int i = 1; i < n; i++) {
		if (*largest < a[i])
			*largest = a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == *largest)
			largest_count++;

		if (largest_count > 1) {
			*second_largest = *largest;
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] < *largest) {
			*second_largest = a[i];
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (*second_largest < a[i] && a[i] < *largest)
			*second_largest = a[i];
	}
}
