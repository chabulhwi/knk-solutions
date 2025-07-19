#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *capitalize(int n, char str[n]);

int main(int argc, char *argv[argc])
{
	for (int i = 1; i < argc; i++) {
		printf("%s", capitalize(strlen(argv[i]), argv[i]));

		if (i < argc - 1)
			putchar(' ');
		else
			putchar('\n');
	}

	return 0;
}

char *capitalize(int n, char str[n])
{
	for (char *p = str; p < str + n; p++)
		*p = toupper(*p);

	return str;
}
