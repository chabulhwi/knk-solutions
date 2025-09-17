#include <stdio.h>

int main(void)
{
	int array[5][5] = { 0 };
	int row_total[5] = { 0 };
	int column_total[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		printf("Enter row %d: ", i + 1);
		for (int j = 0; j < 5; j++) {
			scanf("%d", &array[i][j]);
			row_total[i] += array[i][j];
			column_total[j] += array[i][j];
		}
	}

	printf("\nRow totals:");
	for (int i = 0; i < 5; i++) {
		printf(" %d", row_total[i]);
	}
	printf("\nColumn totals:");
	for (int j = 0; j < 5; j++) {
		printf(" %d", column_total[j]);
	}
	putchar('\n');

	return 0;
}
