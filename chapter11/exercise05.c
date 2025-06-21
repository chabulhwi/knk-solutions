#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void)
{
	long total_sec;
	int hr, min, sec;

	do {
		printf("Enter a time represented as the number of seconds since midnight: ");
		scanf("%ld", &total_sec);
	} while (total_sec < 0);

	split_time(total_sec, &hr, &min, &sec);

	printf("Time: %.2d:%.2d:%.2d\n", hr, min, sec);

	return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
	*sec = total_sec % 60;
	*min = (total_sec / 60) % 60;
	*hr = (total_sec / 60) / 60;
}
