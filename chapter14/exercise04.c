#include <stdio.h>

#define AVG(x,y) (x+y)/2
#define AREA(x,y) (x) * (y)
#define AVG_FIXED(x, y) (((x) + (y))/2)
#define AREA_FIXED(x, y) ((x) * (y))

int main(void)
{
	printf("6/AVG(2,4) == %d\n", 6 / AVG(2, 4));	// 0
	printf("4/AREA(2,2) == %d\n", 4 / AREA(2, 2));	// 4
	putchar('\n');
	printf("6 / AVG_FIXED(2, 4) == %d\n", 6 / AVG_FIXED(2, 4));	// 2
	printf("4 / AREA_FIXED(2, 2) == %d\n", 4 / AREA_FIXED(2, 2));	// 1

	return 0;
}
