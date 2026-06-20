#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

/* MAX_LINE_LEN should be greater than MAX_WORD_LEN from the line.h file. */
#define MAX_LINE_LEN 60

struct node {
	const char *word;
	struct node *next;
};

int line_len = 0, num_words = 0;
struct node *line = NULL;	/* points to node containing first word */
struct node *last = NULL;	/* points to node containing last word */

void clear_line(void)
{
	struct node *first;

	while (1) {
		first = line;
		if (first == NULL)
			break;
		line = line->next;
		free((void *)first->word);
		free(first);
	}
	last = NULL;
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	char *new_word;
	struct node *new_node;

	new_word = malloc(strlen(word) + 1);
	if (new_word == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new_word, word);

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: memory allocation failed\n");
		free(new_word);
		exit(EXIT_FAILURE);
	}
	new_node->word = new_word;
	new_node->next = NULL;

	if (line == NULL) {
		line = new_node;
		last = line;
	} else {
		last->next = new_node;
		last = new_node;
	}
	if (line_len != 0)
		line_len++;
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int count = 0, extra_spaces, num_gaps, spaces_to_add;

	extra_spaces = space_remaining();
	num_gaps = num_words - 1;

	if (num_gaps == 0) {
		printf("%s", line->word);
		for (int i = 0; i < extra_spaces; i++)
			putchar(' ');
		putchar('\n');
		return;
	}
	spaces_to_add = extra_spaces / num_gaps + 1;

	for (struct node *p = line; p != NULL; p = p->next) {
		if (count == num_gaps - extra_spaces % num_gaps + 1)
			spaces_to_add++;
		if (count != 0) {
			for (int i = 0; i < spaces_to_add; i++)
				putchar(' ');
		}
		printf("%s", p->word);
		count++;
	}
	putchar('\n');
}

void flush_line(void)
{
	int count = 0;

	if (line_len > 0) {
		for (struct node *p = line; p != NULL; p = p->next) {
			if (count != 0)
				putchar(' ');
			printf("%s", p->word);
			count++;
		}
		putchar('\n');
	}
}
