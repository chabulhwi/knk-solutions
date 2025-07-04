#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 7
#define HOURS 24

bool search(int n, int *a, int key);

int main(void)
{
	int i, temp[DAYS][HOURS];

	srand((unsigned)time(NULL));

	do {
		printf("Enter an integer ranging from 0 to 6: ");
		scanf("%d", &i);
	} while (i < 0 || i >= DAYS);

	printf("Hour  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23\n");
	printf("---------------------------------------------------------------------------------------------------\n");
	for (int *p = temp[i]; p < temp[i] + HOURS; p++) {
		switch (p - temp[0]) {
		case 0:
			printf("Mon ");
			break;
		case HOURS:
			printf("Tue ");
			break;
		case 2 * HOURS:
			printf("Wed ");
			break;
		case 3 * HOURS:
			printf("Thu ");
			break;
		case 4 * HOURS:
			printf("Fri ");
			break;
		case 5 * HOURS:
			printf("Sat ");
			break;
		case 6 * HOURS:
			printf("Sun ");
			break;
		}

		*p = rand() % 80 - 40;
		printf("%3d", *p);

		if ((p - temp[0]) % HOURS == HOURS - 1)
			putchar('\n');
		else
			putchar(' ');
	}

	return 0;
}

/*
 * I removed the const qualifier because assigning to int * from const int *
 * discards qualifiers.
 */
bool search(int n, int *a, int key)
{
	for (int *p = a; p < a + n; p++) {
		if (*p == key)
			return true;
	}

	return false;
}
