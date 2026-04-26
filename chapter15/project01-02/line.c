#include <stdio.h>
#include <string.h>
#include "line.h"

/* This should be greater than MAX_WORD_LEN in the justify.c file. */
#define MAX_LINE_LEN 60

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

void add_extra_spaces(int pos, int count, int *extra_spaces, int *spaces_to_add)
{
	int num_gaps = num_words - 1;

	/*
	 * The write_line function inserts the larger gaps into both the
	 * beginning and the end of every line.
	 *
	 * The pos variable starts at the middle of the line. As the count
	 * variable increases, the pos variable alternates between going to the
	 * left and going to the right, until it reaches the beginning or the
	 * end of the line.
	 */
	if (count == num_gaps - *extra_spaces % num_gaps + 1)
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
		printf("num_gaps: %d\n", num_gaps);
		return;
	}
	spaces_to_add = extra_spaces / num_gaps;

	for (int pos = 0; pos < line_len; pos++) {
		if (line[pos] == ' ')
			count++;
		if (count == num_gaps / 2 + num_gaps % 2)
			low = pos;
		if (count == num_gaps / 2 + num_gaps % 2 + 1) {
			high = pos;
			break;
		}
	}

	count = 0;
	while (1) {
		while (low >= 0 && line[low] != ' ')
			low--;
		if (low < 0)
			break;
		count++;
		add_extra_spaces(low, count, &extra_spaces, &spaces_to_add);
		low--;
		high += spaces_to_add;

		while (high < line_len && line[high] != ' ')
			high++;
		if (high >= line_len)
			break;
		count++;
		add_extra_spaces(high, count, &extra_spaces, &spaces_to_add);
		high += spaces_to_add + 1;
	}
	puts(line);
}

void flush_line(void)
{
	if (line_len > 0)
		puts(line);
}
