#ifndef COMPARE_H
#define COMPARE_H

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	int price;
};

int compare_parts(const void *p, const void *q);

#endif
