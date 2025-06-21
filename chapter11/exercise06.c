#include <stdio.h>
#include <stdbool.h>

void find_two_largest(int n, int a[n], int *largest, int *second_largest);
void all_the_same(int n, int a[n], int *largest);

int main(void)
{
	bool all_the_same = true;
	int n, largest, second_largest;

	do {
		printf("Enter the length of the array: ");
		scanf("%d", &n);
	} while (n <= 0);

	int a[n];

	for (int i = 0; i < n; i++) {
		printf("Enter elemenet %d of the array: ", i);
		scanf("%d", &a[i]);
	}

	find_two_largest(n, a, &largest, &second_largest);

	printf("Largest: %d\n", largest);
	printf("Second-largest: ");

	for (int i = 0; i < n; i++) {
		if (a[i] < largest)
			all_the_same = false;
	}

	if (all_the_same)
		printf("none\n");
	else
		printf("%d\n", second_largest);

	return 0;
}

void find_two_largest(int n, int a[n], int *largest, int *second_largest)
{
	bool all_the_same = true;

	*largest = a[0];
	for (int i = 1; i < n; i++) {
		if (*largest < a[i])
			*largest = a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] < *largest) {
			all_the_same = false;
			*second_largest = a[i];
		}
	}

	if (all_the_same) {
		return;
	} else {
		for (int i = 0; i < n; i++) {
			if (*second_largest < a[i] && a[i] < *largest)
				*second_largest = a[i];
		}
	}
}
