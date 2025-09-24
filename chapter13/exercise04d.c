#include <stdio.h>

int read_line(int n, char str[n + 1]);

int main(void)
{
	char ch;
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

	if ((ch = getchar()) != '\n' && ch != EOF) {
		printf("\nLeft-behind characters:\n");
		putchar(ch);
		while ((ch = getchar()) != '\n' && ch != EOF)
			putchar(ch);
		putchar('\n');
	}

	return 0;
}

int read_line(int n, char str[n + 1])
{
	int ch, i = 0;

	while (i < n) {
		if ((ch = getchar()) != '\n' && ch != EOF)
			str[i++] = ch;
		else
			break;
	}

	str[i] = '\0';		// terminate string

	return i;		// number of characters stored
}
