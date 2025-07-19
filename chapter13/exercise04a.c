#include <stdio.h>

int read_line(int n, char str[n + 1]);

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
	printf("\nYou entered:\n");
	puts(str);

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
