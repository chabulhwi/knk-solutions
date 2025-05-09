#include <stdio.h>

int check(int x, int y, int n)
{
	if (0 <= x && x <= n - 1 && 0 <= y && y <= n - 1)
		return 1;
	else
		return 0;
}

int main(void)
{
	int x, y, n;

	printf("Enter the value of the integer x: ");
	scanf("%d", &x);
	printf("Enter the value of the integer y: ");
	scanf("%d", &y);
	printf("Enter the value of the integer n: ");
	scanf("%d", &n);

	printf("The value of check(x, y, n): %d\n", check(x, y, n));

	return 0;
}
