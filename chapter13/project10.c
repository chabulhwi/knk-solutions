#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

void reverse_name(char *name);
void get_name(const char *str, int *begin, int *end);

int main(void)
{
	char name[MAX_LEN + 2];

	printf("Enter a first and last name: ");
	fgets(name, MAX_LEN + 2, stdin);
	reverse_name(name);
	printf("%s\n", name);

	return 0;
}

void get_name(const char *str, int *begin, int *end)
{
	while (isspace(str[*begin]) && str[*begin] != '\n')
		(*begin)++;

	if (str[*begin] == '\n') {
		printf("Invalid name\n");
		exit(EXIT_FAILURE);
	}

	*end = *begin + 1;
	while (!isspace(str[*end]))
		(*end)++;
}

void reverse_name(char *name)
{
	int begin = 0, end = 0;

	get_name(name, &begin, &end);

	char first_name[end - begin + 1];
	for (int i = begin; i < end; i++)
		first_name[i - begin] = name[i];
	first_name[end - begin] = '\0';

	begin = end;
	get_name(name, &begin, &end);

	char last_name[end - begin + 1];
	for (int i = begin; i < end; i++)
		last_name[i - begin] = name[i];
	last_name[end - begin] = '\0';

	strcat(strcat(strcat(strcpy(name, last_name), ", "), first_name), ".");
}
