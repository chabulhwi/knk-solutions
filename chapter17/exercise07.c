/*
 * The assignment `p = p->next` occurs after the memory block that `p` points to
 * is deallocated; this causes undefined behavior.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;		// data stored in the node
	struct node *next;	// pointer to the next node
};

struct node *add_to_list(struct node *list, int n);
struct node *delete_all_from_list(struct node *list);
void print_list(struct node *list);

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

	list = delete_all_from_list(list);
	print_list(list);

	return 0;
}

struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;

	return new_node;
}

struct node *delete_all_from_list(struct node *list)
{
	struct node *first;

	while (1) {
		first = list;
		if (first == NULL)
			break;
		list = list->next;
		free(first);
	}

	return list;
}

void print_list(struct node *list)
{
	if (list == NULL) {
		printf("All nodes from the list have been deleted.\n");
		return;
	}

	printf("Result:\n");
	for (struct node *p = list; p != NULL; p = p->next) {
		printf("%d", p->value);
		if (p->next == NULL)
			putchar('\n');
		else
			putchar(' ');
	}
}
