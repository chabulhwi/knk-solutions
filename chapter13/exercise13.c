#include <stdio.h>
#include <string.h>

#define MORE_LEN 22

void build_index_url(const char *domain, char *index_url);

int main(int argc, char *argv[argc])
{
	if (argc == 2) {
		char index_url[strlen(argv[1]) + MORE_LEN + 1];

		build_index_url(argv[1], index_url);
		printf("Index URL: %s\n", index_url);

		return 0;
	} else {
		printf("You should enter exactly one argument.\n");

		return 1;
	}
}

void build_index_url(const char *domain, char *index_url)
{
	strcpy(index_url, "http://www.");
	strcat(index_url, domain);
	strcat(index_url, "/index.html");

	return;
}
