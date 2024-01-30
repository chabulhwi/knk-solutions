#include <stdio.h>

#define DEPART1  8 * 60
#define DEPART2  9 * 60 + 43
#define DEPART3 11 * 60 + 19
#define DEPART4 12 * 60 + 47
#define DEPART5 14 * 60
#define DEPART6 15 * 60 + 45
#define DEPART7 19 * 60
#define DEPART8 21 * 60 + 45

int main(void)
{
	int h, min, time;
	int average81 = (DEPART8 + DEPART1 - 24 * 60) / 2;
	int average12 = (DEPART1 + DEPART2) / 2;
	int average23 = (DEPART2 + DEPART3) / 2;
	int average34 = (DEPART3 + DEPART4) / 2;
	int average45 = (DEPART4 + DEPART5) / 2;
	int average56 = (DEPART5 + DEPART6) / 2;
	int average67 = (DEPART6 + DEPART7) / 2;
	int average78 = (DEPART7 + DEPART8) / 2;

	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d", &h, &min);

	if (h < 0 || h >= 24 || min < 0 || min > 60) {
		printf("Illegal time\n");
	} else {
		time = 60 * h + min;

		printf("Closest departure time is ");
		/*
		 * If the time is the average of two adjacent departure times,
		 * the program will select the earlier one.
		 */
		if (average81 < time && time <= average12)
			printf("8:00 a.m., arriving at 10:16 a.m.\n");
		else if (average12 < time && time <= average23)
			printf("9:43 a.m., arriving at 11:52 a.m.\n");
		else if (average23 < time && time <= average34)
			printf("11:19 a.m., arriving at 1:31 p.m.\n");
		else if (average34 < time && time <= average45)
			printf("12:47 p.m., arriving at 3:00 p.m.\n");
		else if (average45 < time && time <= average56)
			printf("2:00 p.m., arriving at 4:08 p.m.\n");
		else if (average56 < time && time <= average67)
			printf("3:45 p.m., arriving at 5:55 p.m.\n");
		else if (average67 < time && time <= average78)
			printf("7:00 p.m., arriving at 9:20 p.m.\n");
		else
			printf("9:45 p.m., arriving at 11:58 p.m.\n");
	}

	return 0;
}
