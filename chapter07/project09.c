#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int h, min, time;
	char ch1, ch2;

	printf("Enter a 12-hour time: ");
	scanf("%2d:%2d %c%c", &h, &min, &ch1, &ch2);
	ch1 = toupper(ch1);
	ch2 = toupper(ch2);

	if (h < 0 || h > 12 || min < 0 || min > 60 ||
	    (ch1 != 'A' && ch1 != 'P') || (ch2 != '\n' && ch2 != 'M')) {
		printf("Illegal time\n");
	} else {
		if (h == 12 && ch1 == 'A')
			time = min;
		else if (h == 12 && ch1 == 'P')
			time = 60 * 12 + min;
		else if (ch1 == 'A')	// 0 <= h && h < 12
			time = 60 * h + min;
		else		// ch1 == 'P' && 0 <= h && h < 12
			time = 60 * (h + 12) + min;

		printf("24-hour time: %.2d:%.2d\n", time / 60, time % 60);
	}

	return 0;
}
