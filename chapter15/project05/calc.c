#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

int main(void)
{
	char ch;
	int left, right;

	printf("Enter an RPN expression: ");
	while (1) {
		scanf(" %c", &ch);
		switch (ch) {
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
				return 1;
			}
			left = pop();
			push(left / right);
			break;
		case '=':
			printf("Value of expression: %d\n", contents[top - 1]);
			make_empty();
			printf("Enter an RPN expression: ");
			break;
		default:
			return 0;
		}
	}
}
