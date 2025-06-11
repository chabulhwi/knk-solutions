#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LENGTH 2000

int main(void)
{
	char ch, term_ch, sentence[LENGTH];
	int actual_length, begin, end;

	printf("Enter a sentence: ");
	scanf(" ");
	for (int i = 0;; i++) {
		if (i > LENGTH)
			goto error;

		ch = getchar();
		if (ch == '.' || ch == '?' || ch == '!') {
			term_ch = ch;
			actual_length = i + 1;
			break;
		} else if (isspace(ch)) {
			scanf(" ");
			ch = getchar();
			if (ch == '.' || ch == '?' || ch == '!') {
				term_ch = ch;
				actual_length = i + 1;
				break;
			} else if (i == LENGTH) {
				goto error;
			} else {
				sentence[i] = ' ';
				i++;
				sentence[i] = ch;
			}
		} else {
			sentence[i] = ch;
		}
	}

	printf("\nReversal of sentence: ");

	if (actual_length >= 2) {
		end = actual_length - 2;
		begin = end;

		while (1) {
			while (begin != 0 && sentence[begin - 1] != ' ')
				begin--;

			for (int i = begin; i <= end; i++)
				putchar(sentence[i]);

			if (begin == 0) {
				break;
			} else {
				putchar(' ');

				end = begin - 2;
				begin = end;
			}
		}
	}

	printf("%c\n", term_ch);

	return 0;

error:
	printf("The sentence is too long.\n");
	return 1;
}
