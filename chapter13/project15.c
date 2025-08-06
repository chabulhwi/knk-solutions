#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 2000
#define STACK_SIZE 100

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

/* external variables */
int contents[STACK_SIZE];
int top = 0;

int evaluate_RPN_expression(const char *expression);

int main(void)
{
	char expression[MAX_LEN + 2];

	while (1) {
		printf("Enter an RPN expression: ");
		fgets(expression, MAX_LEN + 2, stdin);
		printf("Value of expression: %d\n",
		       evaluate_RPN_expression(expression));
		make_empty();
	}
}

void stack_overflow(void)
{
	printf("Expression is too complex\n");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression\n");
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

void push(int i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

int pop(void)
{
	if (is_empty())
		stack_underflow();

	return contents[--top];
}

int evaluate_RPN_expression(const char *expression)
{
	int left, right;

	for (int i = 0; i < MAX_LEN; i++) {
		switch (expression[i]) {
		case '0':
			push(0);
			break;
		case '1':
			push(1);
			break;
		case '2':
			push(2);
			break;
		case '3':
			push(3);
			break;
		case '4':
			push(4);
			break;
		case '5':
			push(5);
			break;
		case '6':
			push(6);
			break;
		case '7':
			push(7);
			break;
		case '8':
			push(8);
			break;
		case '9':
			push(9);
			break;
		case '+':
			right = pop();
			left = pop();
			push(left + right);
			break;
		case '-':
			right = pop();
			left = pop();
			push(left - right);
			break;
		case '*':
			right = pop();
			left = pop();
			push(left * right);
			break;
		case '/':
			right = pop();
			if (right == 0) {
				printf("Error: division by zero\n");
				exit(EXIT_FAILURE);
			}
			left = pop();
			push(left / right);
			break;
		case '=':
			return contents[top - 1];
		default:
			if (!isspace(expression[i]))
				exit(EXIT_SUCCESS);
		}
	}

	printf("Error: the = operator not found\n");
	exit(EXIT_FAILURE);
}
