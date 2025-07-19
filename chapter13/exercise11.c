#include <stdio.h>
#include <string.h>

int read_line(int n, char str[n + 1]);
int my_strcmp(char *s, char *t);

int main(void)
{
	int n;

	do {
		printf("Enter the maximum length of the string: ");
		scanf("%d", &n);
	} while (n <= 0);

	// dispose of the previous characters
	while (getchar() != '\n')
		/* empty loop body */ ;

	char s1[n + 1], s2[n + 1];

	printf("\nEnter the first string:\n");
	read_line(n, s1);
	printf("\nEnter the second string:\n");
	read_line(n, s2);

	if (my_strcmp(s1, s2) != strcmp(s1, s2)) {
		printf("The definition of my_strcmp is incorrect.\n");

		return 1;
	}

	if (my_strcmp(s1, s2) < 0)
		printf("The first string comes before the second one.\n");
	else if (my_strcmp(s1, s2) == 0)
		printf("The two strings are the same.\n");
	else if (my_strcmp(s1, s2) > 0)
		printf("The first string comes after the second one.\n");

	return 0;
}

int read_line(int n, char str[n + 1])
{
	int ch, i = 0;

	scanf(" ");
	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
	}

	str[i] = '\0';		// terminate string

	return i;		// number of characters stored
}

int my_strcmp(char *s, char *t)
{
	while (*s == *t) {
		if (*s == '\0')
			return 0;

		s++;
		t++;
	}

	return *s - *t;
}
