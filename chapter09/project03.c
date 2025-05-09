#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DIR 4
#define NUM_ALP 26
#define NUM_ROW 10
#define NUM_COL 10

void generate_random_walk(char walk[NUM_ROW][NUM_COL]);
void print_array(char walk[NUM_ROW][NUM_COL]);

int main(void)
{
	bool dir_blocked[NUM_DIR], all_dir_blocked;
	int count, dir, row, col;
	char walk[NUM_ROW][NUM_COL];
	const char label[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};

	generate_random_walk(walk);
	print_array(walk);

	return 0;
}

void generate_random_walk(char walk[NUM_ROW][NUM_COL])
{
	bool dir_blocked[NUM_DIR], all_dir_blocked;
	int count, dir, row, col;
	const char label[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};

	for (int i = 0; i < NUM_ROW; i++) {
		for (int j = 0; j < NUM_COL; j++)
			walk[i][j] = '.';
	}

	srand((unsigned)time(NULL));

	for (count = 0, row = 0, col = 0;; count++) {
		walk[row][col] = label[count];

		if (count == NUM_ALP - 1)
			break;

		for (int d = 0; d < NUM_DIR; d++)
			dir_blocked[d] = false;

		if (row == 0 || walk[row - 1][col] != '.')
			dir_blocked[0] = true;	// upward direction blocked

		if (row == NUM_ROW || walk[row + 1][col] != '.')
			dir_blocked[1] = true;	// downward direction blocked

		if (col == 0 || walk[row][col - 1] != '.')
			dir_blocked[2] = true;	// leftward direction blocked

		if (col == NUM_COL || walk[row][col + 1] != '.')
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
}

void print_array(char walk[NUM_ROW][NUM_COL])
{
	for (int i = 0; i < NUM_ROW; i++) {
		for (int j = 0; j < NUM_COL; j++) {
			putchar(walk[i][j]);

			if (j == NUM_COL - 1)
				putchar('\n');
			else
				putchar(' ');
		}
	}
}
