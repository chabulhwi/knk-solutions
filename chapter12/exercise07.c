#include <stdio.h>
#include <stdbool.h>

bool search(int n, int a[n], int key);

int main(void)
{
	int n, key;

	do {
		printf("Enter the length of the array: ");
		scanf("%d", &n);
	} while (n <= 0);

	int a[n];

	for (int i = 0; i < n; i++) {
		printf("Enter element %d of the array: ", i);
		scanf("%d", &a[i]);
	}

	printf("Enter the value of the key: ");
	scanf("%d", &key);

	if (search(n, a, key))
		printf("The key matches some element of a.\n");
	else
		printf("The key doesn't match any element of a.\n");

	return 0;
}

/*
 * I removed the const qualifier because assigning to int * from const int *
 * discards qualifiers.
 */
bool search(int n, int a[n], int key)
{
	for (int *p = a; p < a + n; p++) {
		if (*p == key)
			return true;
	}

	return false;
}
