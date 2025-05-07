#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DIR 4
#define NUM_ALP 26
#define NUM_ROW 10
#define NUM_COL 10

int main(void)
{
	bool dir_blocked[NUM_DIR], all_dir_blocked;
	int count, dir, row, col;
	char array[NUM_ROW][NUM_COL];
	const char label[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};

	for (int i = 0; i < NUM_ROW; i++) {
		for (int j = 0; j < NUM_COL; j++)
			array[i][j] = '.';
	}

	srand((unsigned)time(NULL));

	for (count = 0, row = 0, col = 0;; count++) {
		array[row][col] = label[count];

		if (count == NUM_ALP - 1)
			break;

		for (int d = 0; d < NUM_DIR; d++)
			dir_blocked[d] = false;

		if (row == 0 || array[row - 1][col] != '.')
			dir_blocked[0] = true;	// upward direction blocked

		if (row == NUM_ROW || array[row + 1][col] != '.')
			dir_blocked[1] = true;	// downward direction blocked

		if (col == 0 || array[row][col - 1] != '.')
			dir_blocked[2] = true;	// leftward direction blocked

		if (col == NUM_COL || array[row][col + 1] != '.')
			dir_blocked[3] = true;	// rightward direction blocked

		all_dir_blocked = true;

		for (int d = 0; d < NUM_DIR; d++) {
			if (dir_blocked[d] == false)
				all_dir_blocked = false;
		}

		if (all_dir_blocked)
			break;

		do {
			dir = rand() % NUM_DIR;
		} while (dir_blocked[dir]);

		switch (dir) {
		case 0:	// move upward
			row--;
			break;
		case 1:	// move downward
			row++;
			break;
		case 2:	// move leftward
			col--;
			break;
		case 3:	// move rightward
			col++;
			break;
		}
	}

	for (int i = 0; i < NUM_ROW; i++) {
		for (int j = 0; j < NUM_COL; j++) {
			putchar(array[i][j]);

			if (j == NUM_COL - 1)
				putchar('\n');
			else
				putchar(' ');
		}
	}

	return 0;
}
