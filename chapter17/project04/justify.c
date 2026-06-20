/* Formats a file of text. */

#include "line.h"
#include "word.h"

int main(void)
{
	char word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();
	for (;;) {
		word_len = read_word(word, MAX_WORD_LEN + 1);
		if (word_len == 0) {
			flush_line();
			clear_line();
			return 0;
		}

		/*
		 * When num_words is greater than zero, there should be one
		 * space between the last word of the line and the new word that
		 * the program will add to the line.
		 */
		if (num_words > 0 && word_len + 1 > space_remaining()) {
			write_line();
			clear_line();
		}
		add_word(word);
	}
}
