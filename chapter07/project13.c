/*
 * This program doesn't consider a punctuation mark to be part of the word to
 * which it's attached.
 */

#include <stdio.h>

int main(void)
{
	char ch;
	int sum = 0, num = 0;

	printf("Enter a sentence: ");
	do
		ch = getchar();
	while (ch == ' ' || ch == ',' || ch == ':' ||
	       ch == ';' || ch == '\'' || ch == '"');

	while (1) {
		if (ch == ' ' || ch == ',' || ch == ':' ||
		    ch == ';' || ch == '\'' || ch == '"') {
			num++;

			do
				ch = getchar();
			while (ch == ' ' || ch == ',' || ch == ':' ||
			       ch == ';' || ch == '\'' || ch == '"');

			if (ch == '.' || ch == '?' || ch == '!' || ch == '\n')
				break;
		} else {
			sum++;

			ch = getchar();
			if (ch == '.' || ch == '?' || ch == '!' || ch == '\n') {
				num++;
				break;
			}
		}
	}

	printf("Sum of word lengths: %d\n", sum);
	printf("Number of words: %d\n", num);
	printf("Average word length: %.1f\n", (float)sum / num);

	return 0;
}
