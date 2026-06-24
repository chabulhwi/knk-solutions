/*
 * I tried not to declare the linked list (contents) as an external variable, so
 * I had to make the push function return a pointer to the first node of the
 * modified linked list.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
	int value;		// data stored in the node
	struct node *next;	// pointer to the next node
};

void stack_underflow(void);
struct node *make_empty(struct node *contents);
bool is_empty(struct node *contents);
struct node *push(struct node *contents, int i);
int first_value(struct node *contents);
struct node *pop(struct node *contents);

int main(void)
{
	struct node *contents = NULL;

	char ch;
	int left, right, result;

	printf("Enter an RPN expression: ");
	while (1) {
		scanf(" %c", &ch);
		switch (ch) {
		case '0':
			contents = push(contents, 0);
			break;
		case '1':
			contents = push(contents, 1);
			break;
		case '2':
			contents = push(contents, 2);
			break;
		case '3':
			contents = push(contents, 3);
			break;
		case '4':
			contents = push(contents, 4);
			break;
		case '5':
			contents = push(contents, 5);
			break;
		case '6':
			contents = push(contents, 6);
			break;
		case '7':
			contents = push(contents, 7);
			break;
		case '8':
			contents = push(contents, 8);
			break;
		case '9':
			contents = push(contents, 9);
			break;
		case '+':
			right = first_value(contents);
			contents = pop(contents);

			left = first_value(contents);
			contents = pop(contents);

			contents = push(contents, left + right);
			break;
		case '-':
			right = first_value(contents);
			contents = pop(contents);

			left = first_value(contents);
			contents = pop(contents);

			contents = push(contents, left - right);
			break;
		case '*':
			right = first_value(contents);
			contents = pop(contents);

			left = first_value(contents);
			contents = pop(contents);

			contents = push(contents, left * right);
			break;
		case '/':
			right = first_value(contents);
			contents = pop(contents);
			if (right == 0) {
				printf("Error: division by zero\n");
				contents = make_empty(contents);
				return 1;
			}

			left = first_value(contents);
			contents = pop(contents);

			contents = push(contents, left / right);
			break;
		case '=':
			result = first_value(contents);
			contents = pop(contents);

			if (!is_empty(contents)) {
				printf("Too many operands in expression\n");
				contents = make_empty(contents);
				exit(EXIT_FAILURE);
			}
			printf("Value of expression: %d\n", result);

			printf("Enter an RPN expression: ");
			break;
		default:
			contents = make_empty(contents);
			return 0;
		}
	}
}

void stack_underflow(void)
{
	printf("Not enough operands in expression\n");
	exit(EXIT_FAILURE);
}

struct node *make_empty(struct node *contents)
{
	struct node *tmp;

	while (contents != NULL) {
		tmp = contents;
		contents = contents->next;
		free(tmp);
	}

	return contents;
}

bool is_empty(struct node *contents)
{
	return contents == NULL;
}

/*
 * This function doesn't return a boolean value; instead, it returns a pointer
 * to the modified linked list.
 */
struct node *push(struct node *contents, int i)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: memory allocation failed\n");
		contents = make_empty(contents);
		exit(EXIT_FAILURE);
	}

	new_node->value = i;
	new_node->next = contents;

	return new_node;
}

int first_value(struct node *contents)
{
	if (is_empty(contents))
		stack_underflow();

	return contents->value;
}

struct node *pop(struct node *contents)
{
	struct node *tmp;

	if (is_empty(contents))
		stack_underflow();

	tmp = contents;
	contents = contents->next;
	free(tmp);

	return contents;
}
