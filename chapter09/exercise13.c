#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BOOL 2
#define NUM_ROW 8
#define NUM_COL 8
#define NUM_TYPE_PCE 12

int evaluate_position(char board[NUM_ROW][NUM_COL]);

int main(void)
{
	bool has_piece[NUM_ROW][NUM_COL], skip;
	int row, col;
	char board[NUM_ROW][NUM_COL];
	const char piece[] = {
		'K', 'Q', 'R', 'B', 'N', 'P', 'k', 'q', 'r', 'b', 'n', 'p'
	};
	const int num_each_piece[NUM_TYPE_PCE] = {
		1, 1, 2, 2, 2, 8, 1, 1, 2, 2, 2, 8
	};

	for (int i = 0; i < NUM_ROW; i++) {
		for (int j = 0; j < NUM_COL; j++)
			has_piece[i][j] = false;
	}
	for (int i = 0; i < NUM_ROW; i++) {
		for (int j = 0; j < NUM_COL; j++)
			board[i][j] = '.';
	}

	srand((unsigned)time(NULL));

	for (int type = 0; type < NUM_TYPE_PCE; type++) {
		for (int count = 0; count < num_each_piece[type]; count++) {
			skip = rand() % NUM_BOOL;

			if (skip) {
				continue;
			} else {
				do {
					row = rand() % NUM_ROW;
					col = rand() % NUM_COL;
				} while (has_piece[row][col]);

				has_piece[row][col] = true;
				board[row][col] = piece[type];
			}
		}
	}

	for (int i = 0; i < NUM_ROW; i++) {
		for (int j = 0; j < NUM_COL; j++) {
			putchar(board[i][j]);

			if (j == NUM_COL - 1)
				putchar('\n');
			else
				putchar(' ');
		}
	}

	printf("\nThe value of the function: %d\n", evaluate_position(board));

	return 0;
}

int evaluate_position(char board[NUM_ROW][NUM_COL])
{
	int sum_value_white = 0, sum_value_black = 0;

	for (int i = 0; i < NUM_ROW; i++) {
		for (int j = 0; j < NUM_COL; j++) {
			switch (board[i][j]) {
			case 'Q':
				sum_value_white += 9;
				break;
			case 'R':
				sum_value_white += 5;
				break;
			case 'B':
				sum_value_white += 3;
				break;
			case 'N':
				sum_value_white += 3;
				break;
			case 'P':
				sum_value_white += 1;
				break;
			case 'q':
				sum_value_black += 9;
				break;
			case 'r':
				sum_value_black += 5;
				break;
			case 'b':
				sum_value_black += 3;
				break;
			case 'n':
				sum_value_black += 3;
				break;
			case 'p':
				sum_value_black += 1;
				break;
			default:
				break;
			}
		}
	}

	return sum_value_white - sum_value_black;
}
