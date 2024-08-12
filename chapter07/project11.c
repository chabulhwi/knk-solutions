#include <stdio.h>

int main(void)
{
	char initial, ch;

	printf("Enter a first and last name: ");
	scanf(" %c", &initial);
	do
		ch = getchar();
	while (ch != ' ' && ch != '\n');

	scanf(" ");

	ch = getchar();
	while (ch != ' ' && ch != '\n') {
		putchar(ch);
		ch = getchar();
	}
	printf(", %c.\n", initial);

	return 0;
}
