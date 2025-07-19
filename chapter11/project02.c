#include <stdio.h>
#include <stdlib.h>

#define DEPART1  8 * 60
#define DEPART2  9 * 60 + 43
#define DEPART3 11 * 60 + 19
#define DEPART4 12 * 60 + 47
#define DEPART5 14 * 60
#define DEPART6 15 * 60 + 45
#define DEPART7 19 * 60
#define DEPART8 21 * 60 + 45

void find_closest_flight(int desired_time, int *departure_time,
			 int *arrival_time);
void print_twelve_hour_time(int time);

int main(void)
{
	int h, min, desired_time, departure_time, arrival_time;

	while (1) {
		printf("Enter a 24-hour time: ");
		scanf("%2d:%2d", &h, &min);

		if (0 <= h && h < 24 && 0 <= min && min < 60)
			break;
		else
			printf("Invalid time\n");
	}

	desired_time = 60 * h + min;
	find_closest_flight(desired_time, &departure_time, &arrival_time);

	printf("Closest departure time is ");
	print_twelve_hour_time(departure_time);
	printf(", arriving at ");
	print_twelve_hour_time(arrival_time);
	putchar('\n');

	return 0;
}

void find_closest_flight(int desired_time, int *departure_time,
			 int *arrival_time)
{
	int average81 = (DEPART8 + DEPART1 - 24 * 60) / 2;
	int average12 = (DEPART1 + DEPART2) / 2;
	int average23 = (DEPART2 + DEPART3) / 2;
	int average34 = (DEPART3 + DEPART4) / 2;
	int average45 = (DEPART4 + DEPART5) / 2;
	int average56 = (DEPART5 + DEPART6) / 2;
	int average67 = (DEPART6 + DEPART7) / 2;
	int average78 = (DEPART7 + DEPART8) / 2;

	/*
	 * If the time is the average of two adjacent departure times, the
	 * program will select the earlier one.
	 */
	if (average81 < desired_time && desired_time <= average12) {
		*departure_time = DEPART1;
		*arrival_time = 10 * 60 + 16;
	} else if (average12 < desired_time && desired_time <= average23) {
		*departure_time = DEPART2;
		*arrival_time = 11 * 60 + 52;
	} else if (average23 < desired_time && desired_time <= average34) {
		*departure_time = DEPART3;
		*arrival_time = (1 + 12) * 60 + 31;
	} else if (average34 < desired_time && desired_time <= average45) {
		*departure_time = DEPART4;
		*arrival_time = (3 + 12) * 60;
	} else if (average45 < desired_time && desired_time <= average56) {
		*departure_time = DEPART5;
		*arrival_time = (4 + 12) * 60 + 8;
	} else if (average56 < desired_time && desired_time <= average67) {
		*departure_time = DEPART6;
		*arrival_time = (5 + 12) * 60 + 55;
	} else if (average67 < desired_time && desired_time <= average78) {
		*departure_time = DEPART7;
		*arrival_time = (9 + 12) * 60 + 20;
	} else {
		*departure_time = DEPART8;
		*arrival_time = (11 + 12) * 60 + 58;
	}
}

void print_twelve_hour_time(int time)
{
	if (time < 0 || time >= 24 * 60) {
		printf("Invalid time\n");
		exit(1);
	}

	int h = time / 60;
	int min = time % 60;

	if (h == 0)
		printf("12:%.2d a.m.", min);
	else if (h < 12)
		printf("%d:%.2d a.m.", h, min);
	else if (h == 12)
		printf("%d:%.2d p.m.", h, min);
	else
		printf("%d:%.2d p.m.", h - 12, min);
}
