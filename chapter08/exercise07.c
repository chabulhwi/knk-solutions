#include <stdio.h>

int main(void)
{
	const int segments[10][7] = {
		{1, 1, 1, 1, 1, 1},
		{0, 1, 1},
		{1, 1, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 0, 1},
		{0, 1, 1, 0, 0, 1, 1},
		{1, 0, 1, 1, 0, 1, 1},
		{1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1}
	};

	for (int digit = 0; digit < 10; digit++) {
		if (segments[digit][0] == 1)
			printf(" _ ");
		else
			printf("   ");

		if (digit == 9)
			putchar('\n');
		else
			putchar(' ');
	}

	for (int digit = 0; digit < 10; digit++) {
		if (segments[digit][5] == 1)
			printf("|");
		else
			printf(" ");

		if (segments[digit][6] == 1)
			printf("_");
		else
			printf(" ");

		if (segments[digit][1] == 1)
			printf("|");
		else
			printf(" ");

		if (digit == 9)
			putchar('\n');
		else
			putchar(' ');
	}

	for (int digit = 0; digit < 10; digit++) {
		if (segments[digit][4] == 1)
			printf("|");
		else
			printf(" ");

		if (segments[digit][3] == 1)
			printf("_");
		else
			printf(" ");

		if (segments[digit][2] == 1)
			printf("|");
		else
			printf(" ");

		if (digit == 9)
			putchar('\n');
		else
			putchar(' ');
	}

	return 0;
}
