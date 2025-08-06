#include <stdio.h>

int main(int argc, char *argv[argc])
{
	for (int i = argc - 1; i > 0; i--) {
		printf("%s", argv[i]);

		if (i == 1)
			putchar('\n');
		else
			putchar(' ');
	}

	return 0;
}
