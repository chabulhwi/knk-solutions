/* Checks planet names */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
	char *planets[] = { "mercury", "venus", "earth", "mars", "jupiter",
		"saturn", "uranus", "neptune", "pluto"
	};

	int i, j, len;

	for (i = 1; i < argc; i++) {
		len = (int)strlen(argv[i]);
		char str[len + 1];

		strncpy(str, argv[i], len);
		str[len] = '\0';

		for (j = 0; j < len; j++)
			str[j] = tolower(str[j]);

		for (j = 0; j < NUM_PLANETS; j++) {
			if (strcmp(str, planets[j]) == 0) {
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			}
		}
		if (j == NUM_PLANETS)
			printf("%s is not a planet\n", argv[i]);
	}

	return 0;
}
