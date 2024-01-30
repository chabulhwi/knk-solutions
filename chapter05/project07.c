#include <stdio.h>

int main(void)
{
	int i1, i2, i3, i4, max12, min12, max34, min34, max, min;

	printf("Enter four integers: ");
	scanf("%d%d%d%d", &i1, &i2, &i3, &i4);

	if (i1 <= i2) {
		max12 = i2;
		min12 = i1;
	} else {
		max12 = i1;
		min12 = i2;
	}

	if (i3 <= i4) {
		max34 = i4;
		min34 = i3;
	} else {
		max34 = i3;
		min34 = i4;
	}

	if (max12 <= max34)
		max = max34;
	else
		max = max12;

	if (min12 <= min34)
		min = min12;
	else
		min = min34;

	printf("Largest: %d\n", max);
	printf("Smallest: %d\n", min);

	return 0;
}
