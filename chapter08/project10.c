#include <stdio.h>
#include <stdbool.h>

#define NUM_DEP_TIME 8

int main(void)
{
	int h, min, time;

	const int depart_time[NUM_DEP_TIME] = {
		8 * 60,
		9 * 60 + 43,
		11 * 60 + 19,
		12 * 60 + 47,
		14 * 60,
		15 * 60 + 45,
		19 * 60,
		21 * 60 + 45
	};

	int depart_h[NUM_DEP_TIME];
	for (int i = 0; i < NUM_DEP_TIME; i++)
		depart_h[i] = depart_time[i] / 60;

	int depart_min[NUM_DEP_TIME];
	for (int i = 0; i < NUM_DEP_TIME; i++)
		depart_min[i] = depart_time[i] % 60;

	const int arrive_time[NUM_DEP_TIME] = {
		10 * 60 + 16,
		11 * 60 + 52,
		1 * 60 + 31,
		3 * 60,
		4 * 60 + 8,
		5 * 60 + 55,
		9 * 60 + 20,
		11 * 60 + 58
	};

	int arrive_h[NUM_DEP_TIME];
	for (int i = 0; i < NUM_DEP_TIME; i++)
		arrive_h[i] = arrive_time[i] / 60;

	int arrive_min[NUM_DEP_TIME];
	for (int i = 0; i < NUM_DEP_TIME; i++)
		arrive_min[i] = arrive_time[i] % 60;

	int average_time[NUM_DEP_TIME] = {
		(depart_time[7] + depart_time[0] - 24 * 60) / 2,
		(depart_time[0] + depart_time[1]) / 2,
		(depart_time[1] + depart_time[2]) / 2,
		(depart_time[2] + depart_time[3]) / 2,
		(depart_time[3] + depart_time[4]) / 2,
		(depart_time[4] + depart_time[5]) / 2,
		(depart_time[5] + depart_time[6]) / 2,
		(depart_time[6] + depart_time[7]) / 2
	};

	while (1) {
		printf("Enter a 24-hour time: ");
		scanf("%2d:%2d", &h, &min);

		if (0 <= h && h < 24 && 0 <= min && min < 60)
			break;
		else
			printf("Illegal time\n");
	}

	time = 60 * h + min;

	printf("Closest departure time is ");

	/*
	 * If the time is the average of two adjacent departure times,
	 * the program will select the earlier one.
	 */
	for (int i = 0; i < NUM_DEP_TIME; i++) {
		if (average_time[i] < time && time <= average_time[i + 1]) {
			if (depart_h[i] == 0)
				printf("12:%.2d a.m.", depart_min[i]);
			else if (depart_h[i] < 12)
				printf("%d:%.2d a.m.", depart_h[i],
				       depart_min[i]);
			else if (depart_h[i] == 12)
				printf("%d:%.2d p.m.", depart_h[i],
				       depart_min[i]);
			else
				printf("%d:%.2d p.m.", depart_h[i] - 12,
				       depart_min[i]);

			printf(", arriving at ");

			if (arrive_h[i] == 0)
				printf("12:%.2d a.m.", arrive_min[i]);
			else if (arrive_h[i] < 12)
				printf("%d:%.2d a.m.", arrive_h[i],
				       arrive_min[i]);
			else if (arrive_h[i] == 12)
				printf("%d:%.2d p.m.", arrive_h[i],
				       arrive_min[i]);
			else
				printf("%d:%.2d p.m.", arrive_h[i] - 12,
				       arrive_min[i]);

			break;
		}
	}

	if (average_time[NUM_DEP_TIME - 1] < time || time <= average_time[0]) {
		if (depart_h[NUM_DEP_TIME - 1] == 0)
			printf("12:%.2d a.m.", depart_min[NUM_DEP_TIME - 1]);
		else if (depart_h[NUM_DEP_TIME - 1] < 12)
			printf("%d:%.2d a.m.", depart_h[NUM_DEP_TIME - 1],
			       depart_min[NUM_DEP_TIME - 1]);
		else if (depart_h[NUM_DEP_TIME - 1] == 12)
			printf("%d:%.2d p.m.", depart_h[NUM_DEP_TIME - 1],
			       depart_min[NUM_DEP_TIME - 1]);
		else
			printf("%d:%.2d p.m.", depart_h[NUM_DEP_TIME - 1] - 12,
			       depart_min[NUM_DEP_TIME - 1]);

		printf(", arriving at ");

		if (arrive_h[NUM_DEP_TIME - 1] == 0)
			printf("12:%.2d a.m.", arrive_min[NUM_DEP_TIME - 1]);
		else if (arrive_h[NUM_DEP_TIME - 1] < 12)
			printf("%d:%.2d a.m.", arrive_h[NUM_DEP_TIME - 1],
			       arrive_min[NUM_DEP_TIME - 1]);
		else if (arrive_h[NUM_DEP_TIME - 1] == 12)
			printf("%d:%.2d p.m.", arrive_h[NUM_DEP_TIME - 1],
			       arrive_min[NUM_DEP_TIME - 1]);
		else
			printf("%d:%.2d p.m.", arrive_h[NUM_DEP_TIME - 1] - 12,
			       arrive_min[NUM_DEP_TIME - 1]);
	}

	putchar('\n');

	return 0;
}
