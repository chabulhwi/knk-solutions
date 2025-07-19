#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);
bool test_extension(const char *file_name, const char *extension);

int main(int argc, char *argv[argc])
{
	if (argc == 3) {
		if (test_extension(argv[1], argv[2]))
			printf("The file's extension is correct.\n");
		else
			printf("The file's extension is incorrect.\n");

		return 0;
	} else {
		printf("You should enter exactly two strings.\n");

		return 1;
	}
}

void get_extension(const char *file_name, char *extension)
{
	bool period_exists = false;
	int start;

	for (int i = 0; i < strlen(file_name); i++) {
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

bool test_extension(const char *file_name, const char *extension)
{
	char file_ext[strlen(file_name) + 1];

	get_extension(file_name, file_ext);

	if (strlen(file_ext) == strlen(extension)) {
		for (int i = 0; i < strlen(file_ext); i++) {
			if (toupper(file_ext[i]) != toupper(extension[i]))
				return false;
		}

		return true;
	} else {
		return false;
	}
}
