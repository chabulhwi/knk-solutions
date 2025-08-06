#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main(void)
{
	char word[MAX_LEN + 1], smallest_word[MAX_LEN + 1],
		largest_word[MAX_LEN + 1];

	printf("Enter word: ");
	scanf("%s", word);

	strcpy(smallest_word, word);
	strcpy(largest_word, word);

	while (strlen(word) != 4) {
		printf("Enter word: ");
		scanf("%s", word);

		if (strcmp(word, smallest_word) < 0)
			strcpy(smallest_word, word);
		else if (strcmp(largest_word, word) < 0)
			strcpy(largest_word, word);
	}

	putchar('\n');
	printf("Smallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}
