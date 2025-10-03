#include <stdio.h>
#include <string.h>
#include "line.h"

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

void insert_extra_spaces(int pos, int count, int *extra_spaces,
			 int *spaces_to_insert)
{
	int num_gaps = num_words - 1;

	if (count == num_gaps - *extra_spaces % num_gaps + 1)
		*spaces_to_insert += 1;

	if (*spaces_to_insert > 0) {
		for (int i = line_len + 1; i > pos; i--)
			line[i + *spaces_to_insert] = line[i];
		for (int i = pos + 1; i <= pos + *spaces_to_insert; i++)
			line[i] = ' ';
	}
	line_len += *spaces_to_insert;
}

void write_line(void)
{
	int low = 0, high = line_len - 1, count = 0, extra_spaces,
		num_gaps, spaces_to_insert;

	extra_spaces = space_remaining();
	num_gaps = num_words - 1;
	spaces_to_insert = extra_spaces / num_gaps;

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
		insert_extra_spaces(low, count, &extra_spaces,
				    &spaces_to_insert);
		low--;
		high += spaces_to_insert;

		while (high < line_len && line[high] != ' ')
			high++;
		if (high >= line_len)
			break;
		count++;
		insert_extra_spaces(high, count, &extra_spaces,
				    &spaces_to_insert);
		high += spaces_to_insert + 1;
	}
	puts(line);
}

void flush_line(void)
{
	if (line_len > 0)
		puts(line);
}
