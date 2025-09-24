#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void remove_filename(char *url);

int main(int argc, char *argv[argc])
{
	if (argc == 2) {
		remove_filename(argv[1]);
		printf("Result: %s\n", argv[1]);

		return 0;
	} else {
		printf("You should enter exactly one argument.\n");

		return 1;
	}
}

void remove_filename(char *url)
{
	bool slash_exists = false;
	int last_slash;

	for (size_t i = 0; i < strlen(url); i++) {
		if (url[i] == '/') {
			if (!slash_exists)
				slash_exists = true;

			last_slash = i;
		}
	}

	if (slash_exists) {
		url[last_slash] = '\0';
	} else {
		printf("The URL has no slash.\n");
		exit(2);
	}
}
