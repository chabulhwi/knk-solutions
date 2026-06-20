#ifndef COMPARE_H
#define COMPARE_H

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

int compare_parts(const void *p, const void *q);

#endif
