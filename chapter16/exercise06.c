#include <stdio.h>

struct time {
	int hours;
	int minutes;
	int seconds;
};

struct time split_time(long total_seconds);

int main(void)
{
	long total_seconds;

	do {
		printf("Enter a time represented as the number of seconds since midnight: ");
		scanf("%ld", &total_seconds);
	} while (total_seconds < 0);

	struct time t = split_time(total_seconds);
	printf("Time: %.2d:%.2d:%.2d\n", t.hours, t.minutes, t.seconds);

	return 0;
}

struct time split_time(long total_seconds)
{
	int hours, minutes, seconds;

	seconds = total_seconds % 60;
	minutes = (total_seconds / 60) % 60;
	hours = (total_seconds / 60) / 60;

	return (struct time) { hours, minutes, seconds };
}
