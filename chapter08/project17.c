#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int n, row, col, sum, next_sum;

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");

	do {
		printf("Enter size of magic square: ");
		scanf("%d", &n);
	} while (n < 1 || n >= 100 || n % 2 == 0);

	int magic_sq[n][n];
	bool occupied[n][n];

	row = 0;
	col = (n - 1) / 2;

	magic_sq[row][col] = 1;
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

		magic_sq[row][col] = m;
		occupied[row][col] = true;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", magic_sq[i][j]);

			if ((j + 1) % n == 0)
				putchar('\n');
		}
	}

	sum = 0;
	for (int j = 0; j < n; j++)
		sum += magic_sq[0][j];

	for (int i = 1; i < n; i++) {
		next_sum = 0;
		for (int j = 0; j < n; j++)
			next_sum += magic_sq[i][j];

		if (sum != next_sum)
			goto error;
	}

	for (int j = 0; j < n; j++) {
		next_sum = 0;
		for (int i = 0; i < n; i++)
			next_sum += magic_sq[i][j];

		if (sum != next_sum)
			goto error;
	}

	next_sum = 0;
	for (int i = 0; i < n; i++)
		next_sum += magic_sq[i][i];

	if (sum != next_sum)
		goto error;

	next_sum = 0;
	for (int i = 0; i < n; i++)
		next_sum += magic_sq[i][n - 1 - i];

	if (sum != next_sum)
		goto error;

	printf("The sums of the rows, columns, and diagonals are all %d.\n",
	       sum);

	return 0;

error:
	printf("The program has created an incorrect magic square.\n");
	return 1;
}
