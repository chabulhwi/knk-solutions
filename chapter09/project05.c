/*
 * NOTE: I changed the type of the parameter magic_square from char to int.
 *
 * There's an error in page 217. In Programming Project 5, the element type of
 * the magic_square parameter in the prototypes for create_magic_square and
 * print_magic_square should be int rather than char. This error occurs in four
 * places. (Found by Bryan Krofchok.)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);
int sum_of_line(int n, int magic_square[n][n]);

int main(void)
{
	int n;

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");

	do {
		printf("Enter size of magic square: ");
		scanf("%d", &n);
	} while (n < 1 || n >= 100 || n % 2 == 0);

	int magic_square[n][n];

	create_magic_square(n, magic_square);
	print_magic_square(n, magic_square);

	printf("The sums of the rows, columns, and diagonals are all %d.\n",
	       sum_of_line(n, magic_square));
	return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
	bool occupied[n][n];
	int row = 0, col = (n - 1) / 2;

	magic_square[row][col] = 1;
	occupied[row][col] = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != row || j != col)
				occupied[i][j] = false;
		}
	}

	for (int m = 2; m <= n * n; m++) {
		if (occupied[(row + n - 1) % n][(col + 1) % n]) {
			row = (row + 1) % n;
		} else {
			row = (row + n - 1) % n;
			col = (col + 1) % n;
		}

		magic_square[row][col] = m;
		occupied[row][col] = true;
	}
}

void print_magic_square(int n, int magic_square[n][n])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", magic_square[i][j]);

			if ((j + 1) % n == 0)
				putchar('\n');
		}
	}
}

int sum_of_line(int n, int magic_square[n][n])
{
	int sum, next_sum;

	sum = 0;
	for (int j = 0; j < n; j++)
		sum += magic_square[0][j];

	for (int i = 1; i < n; i++) {
		next_sum = 0;
		for (int j = 0; j < n; j++)
			next_sum += magic_square[i][j];

		if (sum != next_sum)
			goto error;
	}

	for (int j = 0; j < n; j++) {
		next_sum = 0;
		for (int i = 0; i < n; i++)
			next_sum += magic_square[i][j];

		if (sum != next_sum)
			goto error;
	}

	next_sum = 0;
	for (int i = 0; i < n; i++)
		next_sum += magic_square[i][i];

	if (sum != next_sum)
		goto error;

	next_sum = 0;
	for (int i = 0; i < n; i++)
		next_sum += magic_square[i][n - 1 - i];

	if (sum != next_sum)
		goto error;

	return sum;

error:
	printf("The program has created an incorrect magic square.\n");
	exit(1);
}
