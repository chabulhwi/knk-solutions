#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int read_line(int n, char str[n + 1]);
int compare_words(const void *w1, const void *w2);
void clear_words(char **words, int num_words);

int main(void)
{
	bool malloc_failed = false;
	char **words = NULL, **tmp = NULL, line[MAX_WORD_LEN + 1];
	int word_len, num_words = 0;

	while (1) {
		tmp = realloc(words, (num_words + 1) * sizeof(char *));
		if (tmp == NULL) {
			printf("Error: memory allocation failed\n");
			malloc_failed = true;
			break;
		}
		words = tmp;

		printf("Enter word: ");
		word_len = read_line(MAX_WORD_LEN, line);
		if (word_len == 0)
			break;
		words[num_words] = malloc(word_len + 1);
		if (words[num_words] == NULL) {
			printf("Error: memory allocation failed\n");
			malloc_failed = true;
			break;
		}
		strcpy(words[num_words], line);
		num_words++;
	}

	if (num_words == 0) {
		printf("No words to sort.\n");
	} else {
		qsort(words, num_words, sizeof(char *), compare_words);
		printf("In sorted order:");
		for (int i = 0; i < num_words; i++)
			printf(" %s", words[i]);
		putchar('\n');
	}
	clear_words(words, num_words);

	if (malloc_failed)
		return 1;
	else
		return 0;
}

int read_line(int n, char str[n + 1])
{
	int ch, i = 0;

	ch = getchar();
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';

	return i;
}

int compare_words(const void *w1, const void *w2)
{
	return strcmp(*(const char **)w1, *(const char **)w2);
}

void clear_words(char **words, int num_words)
{
	for (int i = 0; i < num_words; i++)
		free(words[i]);
	free(words);
}
