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
	for (char *p = sentence;; p++) {
		if (p > sentence + LENGTH)
			goto error;

		ch = getchar();
		if (ch == '.' || ch == '?' || ch == '!') {
			term_ch = ch;
			actual_length = p - sentence + 1;
			break;
		} else if (isspace(ch)) {
			scanf(" ");
			ch = getchar();
			if (ch == '.' || ch == '?' || ch == '!') {
				term_ch = ch;
				actual_length = p - sentence + 1;
				break;
			} else if (p == sentence + LENGTH) {
				goto error;
			} else {
				*p = ' ';
				p++;
				*p = ch;
			}
		} else {
			*p = ch;
		}
	}

	printf("\nReversal of sentence: ");

	if (actual_length >= 2) {
		end = actual_length - 2;
		begin = end;

		while (1) {
			while (begin != 0 && *(sentence + begin - 1) != ' ')
				begin--;

			for (char *p = sentence + begin; p <= sentence + end;
			     p++)
				putchar(*p);

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
