/*
 * This program doesn't consider a punctuation mark to be part of the word to
 * which it's attached.
 */

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 2000

double compute_average_word_length(const char *sentence);

int main(void)
{
	char sentence[MAX_LEN + 2];

	printf("Enter a sentence: ");
	fgets(sentence, MAX_LEN + 2, stdin);
	printf("Average word length: %.1f\n",
	       compute_average_word_length(sentence));

	return 0;
}

double compute_average_word_length(const char *sentence)
{
	const char *ch = sentence;
	int sum = 0, num = 0;

	while ((isspace(*ch) && *ch != '\n') || *ch == ',' || *ch == ':' ||
	       *ch == ';' || *ch == '\'' || *ch == '"')
		ch++;

	if (*ch != '.' && *ch != '?' && *ch != '!' && *ch != '\n') {
		while (1) {
			if ((isspace(*ch) && *ch != '\n') || *ch == ',' ||
			    *ch == ':' || *ch == ';' || *ch == '\'' ||
			    *ch == '"') {
				num++;

				do
					ch++;
				while ((isspace(*ch) && *ch != '\n') ||
				       *ch == ',' || *ch == ':' || *ch == ';' ||
				       *ch == '\'' || *ch == '"');

				if (*ch == '.' || *ch == '?' || *ch == '!' ||
				    *ch == '\n')
					break;
			} else {
				sum++;
				ch++;
				if (*ch == '.' || *ch == '?' || *ch == '!' ||
				    *ch == '\n') {
					num++;
					break;
				}
			}
		}
	}

	if (num == 0)
		return 0;
	else
		return (double)sum / num;
}
