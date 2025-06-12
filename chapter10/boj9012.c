/*
 * My solution to Problem 9012 from Baekjoon:
 * https://www.acmicpc.net/problem/9012.
 *
 * Check whether the input is a valid Parenthesis String.
 */

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 50

bool line_is_vps(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);

/* external variables */
char contents[STACK_SIZE];
int top = 0;

int main(void)
{
	char ch;
	int num;

	do {
		scanf("%d", &num);
	} while (num < 0);

	scanf(" ");

	for (int i = 0; i < num; i++) {
		if (line_is_vps())
			printf("YES\n");
		else
			printf("NO\n");

		make_empty();

	}

	return 0;
}

bool line_is_vps(void)
{
	char ch;

	while (1) {
		scanf("%c", &ch);
		if (ch == '\n') {
			break;
		} else if (ch == '(') {
			if (is_full()) {
				// discard the rest of characters
				while (getchar() != '\n')
					/* empty loop body */ ;

				return false;
			} else {
				contents[top++] = ch;
			}
		} else if (ch == ')') {
			if (is_empty()) {
				// discard the rest of characters
				while (getchar() != '\n')
					/* empty loop body */ ;

				return false;
			} else if (contents[--top] != '(') {
				return false;
			}
		}
	}

	if (is_empty())
		return true;
	else
		return false;
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
