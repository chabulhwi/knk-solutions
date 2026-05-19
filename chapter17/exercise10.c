#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

int read_line(char str[], int n);
void print_part(struct part *p);

int main(void)
{
	struct part *p = malloc(sizeof(struct part));

	if (p == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter part number: ");
	scanf("%d", &p->number);

	printf("Enter part name: ");
	read_line(p->name, NAME_LEN);

	printf("Enter quantity on hand: ");
	scanf("%d", &p->on_hand);

	putchar('\n');
	print_part(p);
	free(p);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	while (isspace(ch = getchar()))
		/* empty loop body */ ;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

void print_part(struct part *p)
{
	printf("Part number: %d\n", p->number);
	printf("Part name: %s\n", p->name);
	printf("Quantity on hand: %d\n", p->on_hand);
}
