#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size);

int main(void)
{
	char *p = my_malloc(1);
	printf("Enter an ASCII character: ");
	scanf("%c", p);
	printf("You entered '%c'.\n", *p);
	free(p);

	return 0;
}

void *my_malloc(size_t size)
{
	void *result = malloc(size);

	if (result == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	return result;
}
