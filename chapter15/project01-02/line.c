#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "line.h"

/* This should be greater than MAX_WORD_LEN from the justify.c file. */
#define MAX_LINE_LEN 60

bool wider_gaps_at_end = true;
char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}
	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void add_extra_spaces(int pos, int count, int extra_spaces, int *spaces_to_add)
{
	int num_gaps = num_words - 1;

	if (count == num_gaps - extra_spaces % num_gaps + 1)
		*spaces_to_add += 1;

	if (*spaces_to_add > 0) {
		for (int i = line_len; i > pos; i--)
			line[i + *spaces_to_add] = line[i];
		for (int i = pos + 1; i <= pos + *spaces_to_add; i++)
			line[i] = ' ';
	}
	line_len += *spaces_to_add;
}

void write_line(void)
{
	int low = 0, high = line_len - 1, count = 0, extra_spaces,
		num_gaps, spaces_to_add;

	extra_spaces = space_remaining();
	num_gaps = num_words - 1;

	if (num_gaps == 0) {
		for (int i = 0; i < extra_spaces; i++) {
			line[line_len + i] = ' ';
		}
		line[line_len + extra_spaces] = '\0';
		puts(line);
		return;
	}
	spaces_to_add = extra_spaces / num_gaps;

	if (wider_gaps_at_end) {
		while (1) {
			while (low < line_len && line[low] != ' ')
				low++;
			if (low >= line_len)
				break;
			count++;
			add_extra_spaces(low, count, extra_spaces,
					 &spaces_to_add);
			low += spaces_to_add + 1;
		}
	} else {
		while (1) {
			while (high >= 0 && line[high] != ' ')
				high--;
			if (high < 0)
				break;
			count++;
			add_extra_spaces(high, count, extra_spaces,
					 &spaces_to_add);
			high--;
		}
	}
	puts(line);
	wider_gaps_at_end = !wider_gaps_at_end;
}

void flush_line(void)
{
	if (line_len > 0)
		puts(line);
}
