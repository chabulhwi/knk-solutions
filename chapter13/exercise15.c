/*
 * (a) 3
 * (b) 0
 * (c) The function returns the distance between the initial character in the
 *     first string and its first character that doesn't occur in the second
 *     string.
 */

#include <stdio.h>

int f(char *s, char *t);

int main(int argc, char *argv[argc])
{
	if (argc == 3) {
		printf("%d\n", f(argv[1], argv[2]));

		return 0;
	} else {
		printf("You should enter exactly two strings.\n");

		return 1;
	}
}

int f(char *s, char *t)
{
	char *p1, *p2;

	for (p1 = s; *p1; p1++) {
		for (p2 = t; *p2; p2++)
			if (*p1 == *p2)
				break;
		if (*p2 == '\0')
			break;
	}
	return p1 - s;
}
