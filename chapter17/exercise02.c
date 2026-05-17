#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *str);

int main(void)
{
	int len = 0;
	char *result;

	do {
		printf("Enter the length of the string: ");
		scanf("%d", &len);
	} while (len <= 0);

	// dispose of the previous characters
	while (getchar() != '\n')
		/* empty loop body */ ;

	char str[len + 1];

	printf("Enter the string: ");
	fgets(str, len + 1, stdin);
	result = duplicate(str);

	if (result == NULL) {
		printf("Error: memory allocation failed\n");
		free(result);
		exit(EXIT_FAILURE);
	}

	printf("You entered:\n%s\n", result);
	if (strcmp(result, str) != 0) {
		printf("Error: duplication failed\n");
		free(result);
		exit(EXIT_FAILURE);
	}
	free(result);

	return 0;
}

char *duplicate(char *str)
{
	char *result = malloc(strlen(str) + 1);

	if (result != NULL)
		strcpy(result, str);

	return result;
}
