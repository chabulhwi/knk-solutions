#include <stdio.h>

int read_line(int n, char str[n + 1]);
int count_spaces(const char *s);

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

	char str[n + 1];

	printf("\nEnter the string:\n");
	read_line(n, str);

	printf("\nThe string has %d spaces.\n", count_spaces(str));

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

int count_spaces(const char *s)
{
	int count = 0;

	while (*s) {
		if (*s++ == ' ')
			count++;
	}

	return count;
}
