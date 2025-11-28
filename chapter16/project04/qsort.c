/* Sorts an array of integers using Quicksort algorithm */

#include "qsort.h"

void quicksort(struct part inventory[MAX_PARTS], int low, int high)
{
	int middle;

	if (low >= high)
		return;
	middle = split(inventory, low, high);
	quicksort(inventory, low, middle - 1);
	quicksort(inventory, middle + 1, high);
}

int split(struct part inventory[MAX_PARTS], int low, int high)
{
	struct part pivot = inventory[low];

	for (;;) {
		while (low < high && pivot.number <= inventory[high].number)
			high--;
		if (low >= high)
			break;
		inventory[low++] = inventory[high];

		while (low < high && inventory[low].number <= pivot.number)
			low++;
		if (low >= high)
			break;
		inventory[high--] = inventory[low];
	}

	inventory[high] = pivot;
	return high;
}
