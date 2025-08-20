#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int main(void)
{
	char s[5];
	int i;

	printf("(a) ");
	strcpy(s, "abcd");
	i = 0;
	putchar(TOUPPER(s[++i]));	// (a) D
	putchar('\n');

	printf("(b) ");
	strcpy(s, "0123");
	i = 0;
	putchar(TOUPPER(s[++i]));	// (b) 2
	putchar('\n');

	return 0;
}
