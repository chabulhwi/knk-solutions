#include <stdio.h>

int main(void)
{
	int h, min;

	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d", &h, &min);

	if (h < 0 || h >= 24 || min < 0 || min > 60) {
		printf("Illegal time\n");
	} else {
		printf("Equivalent 12-hour time: ");
		if (h == 0)
			printf("12:%.2d AM\n", min);
		else if (h < 12)
			printf("%d:%.2d AM\n", h, min);
		else if (h == 12)
			printf("%d:%.2d PM\n", h, min);
		else
			printf("%d:%.2d PM\n", h - 12, min);
	}

	return 0;
}
