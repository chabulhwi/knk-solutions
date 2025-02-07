#include <stdio.h>

#define LENGTH 20

int main(void)
{
	char initial, ch, last_name[LENGTH];

	printf("Enter a first and last name: ");
	scanf(" %c", &initial);
	do
		ch = getchar();
	while (ch != ' ' && ch != '\n');

	scanf(" ");

	last_name[0] = getchar();
	for (int i = 0; last_name[i] != ' ' && last_name[i] != '\n'; i++)
		last_name[i + 1] = getchar();

	printf("You entered the name: ");
	for (int i = 0; last_name[i] != ' ' && last_name[i] != '\n'; i++)
		putchar(last_name[i]);

	printf(", %c.\n", initial);

	return 0;
}
