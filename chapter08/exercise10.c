#include <stdio.h>

#define SIZE 8

int main(void)
{
	char chess_board[SIZE][SIZE] = {
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{' ', '.', ' ', '.', ' ', '.', ' ', '.'},
		{'.', ' ', '.', ' ', '.', ' ', '.', ' '},
		{' ', '.', ' ', '.', ' ', '.', ' ', '.'},
		{'.', ' ', '.', ' ', '.', ' ', '.', ' '},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
	};

	for (int rank = 0; rank < SIZE; rank++) {
		for (int file = 0; file < SIZE; file++) {
			printf("%c", chess_board[rank][file]);

			if (file == SIZE - 1)
				putchar('\n');
			else
				putchar(' ');
		}
	}

	return 0;
}
