#include <stdio.h>

#define CHECK(x, y, n) (0 <= (x) && (x) <= (n) - 1 && 0 <= (y) && \
			(y) <= (n) - 1 ? 1 : 0)

int main(void)
{
	double x, y, n;

	printf("Enter three double values: ");
	scanf("%lf%lf%lf", &x, &y, &n);

	if (CHECK(x, y, n))
		printf("Both %.2f and %.2f fall between 0 and %.2f - 1, inclusive.\n", x, y, n);
	else
		printf("CHECK FAILED\n");

	return 0;
}
