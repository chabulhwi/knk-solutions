#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;		// data stored in the node
	struct node *next;	// pointer to the next node
};

struct node *add_to_list(struct node *list, int n);
int count_occurrences(struct node *list, int n);
void print_list(struct node *list);
void clear_list(struct node *list);

int main(void)
{
	int n = 0, value;
	struct node *list = NULL;

	do {
		printf("Enter the length of the linked list: ");
		scanf("%d", &n);
	} while (n <= 0);

	for (int i = 0; i < n; i++) {
		printf("Enter the value of the node #%d: ", n - i);
		scanf("%d", &value);
		list = add_to_list(list, value);
	}

	putchar('\n');
	print_list(list);
	putchar('\n');

	printf("Enter an integer: ");
	scanf("%d", &value);
	printf("Occurrences of %d: %d\n", value,
	       count_occurrences(list, value));

	clear_list(list);

	return 0;
}

struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: memory allocation failed\n");
		clear_list(list);
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;

	return new_node;
}

int count_occurrences(struct node *list, int n)
{
	int count = 0;

	for (struct node *p = list; p != NULL; p = p->next) {
		if (p->value == n)
			count++;
	}

	return count;
}

void print_list(struct node *list)
{
	printf("Result:\n");
	for (struct node *p = list; p != NULL; p = p->next) {
		printf("%d", p->value);
		if (p->next == NULL)
			putchar('\n');
		else
			putchar(' ');
	}
}

void clear_list(struct node *list)
{
	while (list != NULL) {
		struct node *next = list->next;
		free(list);
		list = next;
	}
}
