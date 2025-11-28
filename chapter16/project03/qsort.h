#ifndef QSORT_H
#define QSORT_H

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

void quicksort(struct part inventory[MAX_PARTS], int low, int high);

int split(struct part inventory[MAX_PARTS], int low, int high);

#endif
