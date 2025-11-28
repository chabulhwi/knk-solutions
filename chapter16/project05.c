#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct daily_flights {
	int departure_time;
	int arrival_time;
};

const struct daily_flights table[] = {
	{8 * 60, 10 * 60 + 16},
	{9 * 60 + 43, 11 * 60 + 52},
	{11 * 60 + 19, 13 * 60 + 31},
	{12 * 60 + 47, 15 * 60},
	{14 * 60, 16 * 60 + 8},
	{15 * 60 + 45, 17 * 60 + 55},
	{19 * 60, 21 * 60 + 20},
	{21 * 60 + 45, 23 * 60 + 58},
};

const size_t length = sizeof(table) / sizeof(table[0]);

const int average[] = {
	(table[7].departure_time + table[0].departure_time - 24 * 60) / 2,
	(table[0].departure_time + table[1].departure_time) / 2,
	(table[1].departure_time + table[2].departure_time) / 2,
	(table[2].departure_time + table[3].departure_time) / 2,
	(table[3].departure_time + table[4].departure_time) / 2,
	(table[4].departure_time + table[5].departure_time) / 2,
	(table[5].departure_time + table[6].departure_time) / 2,
	(table[6].departure_time + table[7].departure_time) / 2,
};

bool size_eq = length == sizeof(average) / sizeof(average[0]);

void print_twelve_hour_time(int h, int min);

int main(void)
{
	int h, min, time;

	if (!size_eq) {
		printf("Error: invalid array length\n");

		return 1;
	}

	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d", &h, &min);

	if (h < 0 || h >= 24 || min < 0 || min >= 60) {
		printf("Invalid time\n");
	} else {
		time = 60 * h + min;

		printf("Closest departure time is ");
		/*
		 * If the time is the average of two adjacent departure times,
		 * the program will select the earlier one.
		 */
		for (size_t i = 0; i < length; i++) {
			if (i == length - 1 || (average[i] < time && time <=
						average[i + 1])) {
				h = table[i].departure_time / 60;
				min = table[i].departure_time % 60;
				print_twelve_hour_time(h, min);
				printf(", arriving at ");
				h = table[i].arrival_time / 60;
				min = table[i].arrival_time % 60;
				print_twelve_hour_time(h, min);
				putchar('\n');
				break;
			}
		}
	}

	return 0;
}

void print_twelve_hour_time(int h, int min)
{
	if (h < 0 || h >= 24 || min < 0 || min >= 60) {
		printf("Invalid time\n");
		exit(2);
	} else if (h == 0) {
		printf("12:%.2d a.m.", min);
	} else if (h < 12) {
		printf("%d:%.2d a.m.", h, min);
	} else if (h == 12) {
		printf("%d:%.2d p.m.", h, min);
	} else {
		printf("%d:%.2d p.m.", h - 12, min);
	}
}
