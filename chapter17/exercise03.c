#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value);

int main(void)
{
	int n = 0, initial_value = 0, *result;

	do {
		printf("Enter the length of the array: ");
		scanf("%d", &n);
	} while (n <= 0);

	printf("Enter the initial value: ");
	scanf("%d", &initial_value);

	result = create_array(n, initial_value);

	if (result == NULL) {
		printf("Error: memory allocation failed\n");
		free(result);
		exit(EXIT_FAILURE);
	}

	printf("Result:\n");
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0)
			printf("  ");

		printf("%d", result[i]);

		if (i % 10 == 9)
			putchar('\n');
		else
			putchar(' ');
	}
	free(result);

	return 0;
}

int *create_array(int n, int initial_value)
{
	int *result = malloc(n * sizeof(*result));

	if (result != NULL) {
		for (int i = 0; i < n; i++)
			result[i] = initial_value;
	}

	return result;
}
