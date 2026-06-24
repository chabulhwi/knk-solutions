/*
 * 1. Either of the two parameters to the function, list and new_node, might be
 *    a null pointer. The function has to handle these cases.
 * 2. The pointer prev in the function body could remain as a null
 *    pointer when new_node should be the first node in the modified list. In
 *    this case, the program must not try to access prev->next.
 * 3. The pointer cur in the function body would be a null pointer when new_node
 *    should be the last node in the modified list. The iteration of the loop
 *    must stop before the program tries to access cur->value.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;		// data stored in the node
	struct node *next;	// pointer to the next node
};

struct node *insert_into_ordered_list(struct node *list, struct node *new_node);
void print_list(struct node *list);
void clear_list(struct node *list);

int main(void)
{
	int n = 0, value;
	struct node *list = NULL, *new_node;

	do {
		printf("Enter the length of the linked list: ");
		scanf("%d", &n);
	} while (n <= 0);

	for (int i = 0; i < n; i++) {
		printf("Enter the value of the node #%d: ", n - i);
		scanf("%d", &value);

		new_node = malloc(sizeof(struct node));
		if (new_node == NULL) {
			printf("Error: memory allocation failed\n");
			clear_list(list);
			exit(EXIT_FAILURE);
		}
		*new_node = (struct node) { value, NULL };

		list = insert_into_ordered_list(list, new_node);
		print_list(list);
	}

	putchar('\n');
	print_list(list);

	clear_list(list);

	return 0;
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
	struct node *cur = list, *prev = NULL;

	if (new_node == NULL) {
		return list;
	} else if (list == NULL) {
		return new_node;
	} else if (list->value > new_node->value) {
		new_node->next = list;
		return new_node;
	}

	do {
		prev = cur;
		cur = cur->next;
	} while (cur != NULL && cur->value <= new_node->value);

	prev->next = new_node;
	new_node->next = cur;

	return list;
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
