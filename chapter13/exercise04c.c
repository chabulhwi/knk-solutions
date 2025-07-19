#include <stdio.h>

int read_line(int n, char str[n + 2]);

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

	char str[n + 2];

	printf("\nEnter the string:\n");
	read_line(n, str);
	printf("\nYou entered:\n");
	printf("%s", str);

	return 0;
}

int read_line(int n, char str[n + 2])
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
	}

	str[i] = '\n';		// store new-line character
	str[i + 1] = '\0';	// terminate string

	return i;		// number of characters stored
}
