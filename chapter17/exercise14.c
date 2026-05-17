#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;		// data stored in the node
	struct node *next;	// pointer to the next node
};

struct node *add_to_list(struct node *list, int n);
void delete_from_list(struct node **list, int n);
void print_list(struct node *list);

int main(void)
{
	int n = 0, value;
	struct node *list = NULL, *tmp = NULL;

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

	printf("Enter the value of the node you want to delete: ");
	scanf("%d", &value);
	delete_from_list(&list, value);

	putchar('\n');
	print_list(list);
	for (struct node *p = list; p != NULL;) {
		tmp = p;
		p = p->next;
		free(tmp);
	}

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

void delete_from_list(struct node **list, int n)
{
	struct node *cur, *prev;

	if (list == NULL) {
		printf("Error: The first argument to the delete_from_list function is a null pointer.\n");
		exit(EXIT_FAILURE);
	} else if (*list == NULL) {
		return;		// n was not found
	} else if ((*list)->value == n) {
		prev = *list;	// n is in the first node
		*list = (*list)->next;
		free(prev);
		return;
	}

	cur = (*list)->next;
	prev = *list;
	while (cur != NULL && cur->value != n) {
		cur = cur->next;
		prev = prev->next;
	}

	if (cur == NULL) {
		return;		// n was not found
	} else {
		prev->next = cur->next;	// n is in some other node
		free(cur);
		return;
	}
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
