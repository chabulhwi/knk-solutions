#include <stdio.h>

int main(void)
{
	char checker_board[8][8];

	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			if ((row + column) % 2 == 0)
				checker_board[row][column] = 'B';
			else
				checker_board[row][column] = 'R';

			printf("%c", checker_board[row][column]);

			if (column % 8 == 7)
				putchar('\n');
			else
				putchar(' ');
		}
	}

	return 0;
}
