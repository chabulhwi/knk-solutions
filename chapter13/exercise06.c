#include <stdio.h>
#include <string.h>

char *censor(int n, char str[n]);

int main(int argc, char *argv[argc])
{
	for (int i = 1; i < argc; i++) {
		printf("%s", censor(strlen(argv[i]), argv[i]));

		if (i < argc - 1)
			putchar(' ');
		else
			putchar('\n');
	}

	return 0;
}

char *censor(int n, char str[n])
{
	char substr[4];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			substr[j] = str[i + j];

		substr[3] = '\0';

		if (strcmp(substr, "foo") == 0) {
			for (int j = 0; j < 3; j++)
				str[i + j] = 'x';
		}
	}

	return str;
}
