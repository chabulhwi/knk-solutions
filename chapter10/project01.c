#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);

/* external variables */
char contents[STACK_SIZE];
int top = 0;

int main(void)
{
	char ch;

	printf("Enter parentheses and/or braces: ");

	while ((ch = getchar()) != '\n') {
		switch (ch) {
		case '(':
		case '{':
			push(ch);
			break;
		case ')':
			if (pop() != '(')
				goto error;
			break;
		case '}':
			if (pop() != '{')
				goto error;
			break;
		}
	}

	if (is_empty()) {
		printf("Parentheses/braces are nested properly\n");
		return EXIT_SUCCESS;
	} else {
		printf("The parentheses/braces aren't matched\n");
		exit(EXIT_FAILURE);
	}

error:
	printf("Parentheses/braces aren't nested properly\n");
	return EXIT_FAILURE;
}

void stack_overflow(void)
{
	printf("Stack overflow\n");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("The parentheses/braces aren't matched\n");
	exit(EXIT_FAILURE);
}

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(char ch)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = ch;
}

char pop(void)
{
	if (is_empty())
		stack_underflow();

	return contents[--top];
}
