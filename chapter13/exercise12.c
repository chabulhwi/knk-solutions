#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);

int main(int argc, char *argv[argc])
{
	if (argc == 2) {
		char extension[strlen(argv[1]) + 1];

		get_extension(argv[1], extension);
		printf("Extension: %s\n", extension);

		return 0;
	} else {
		printf("You should enter exactly one argument.\n");

		return 1;
	}
}

void get_extension(const char *file_name, char *extension)
{
	bool period_exists = false;
	int start;

	for (size_t i = 0; i < strlen(file_name); i++) {
		if (file_name[i] == '.') {
			if (!period_exists)
				period_exists = true;

			start = i + 1;
		}
	}

	if (period_exists) {
		strcpy(extension, &file_name[start]);
	} else {
		printf("The file name has no extension.\n");
		exit(2);
	}
}
