#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 20
#define MAX_NUM 30

int main(void)
{
	bool term_ch_correct = true;
	char sentence[MAX_NUM][MAX_LEN + 2], *word, term_ch;
	int i, word_num, word_len;

	printf("Enter a sentence: ");
	for (i = 0; i < MAX_NUM; i++) {
		scanf("%s", sentence[i]);
		word = sentence[i];
		word_len = strlen(word);
		term_ch = word[word_len - 1];

		if (term_ch == '.' || term_ch == '?' || term_ch == '!') {
			break;
		} else if (getchar() == '\n') {
			term_ch_correct = false;
			break;
		}
	}
	word_num = i + 1;
	if (term_ch_correct)
		word[word_len - 1] = '\0';

	printf("\nReversal of sentence: ");
	for (i = word_num - 1; i >= 0; i--) {
		printf("%s", sentence[i]);
		if ((i != word_num - 1 || strcmp(word, "") != 0) && i != 0)
			putchar(' ');
	}
	if (term_ch_correct)
		printf("%c\n", term_ch);

	return 0;
}
