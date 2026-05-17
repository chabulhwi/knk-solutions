#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int odd(int n);

int main(void)
{
	int start, end;

	printf("Enter the value for start: ");
	scanf("%d", &start);
	printf("Enter the value for end: ");
	scanf("%d", &end);
	printf("Result: %d\n", sum(odd, start, end));

	return 0;
}

int sum(int (*f)(int), int start, int end)
{
	int result = 0;

	for (int n = start; n <= end; n++)
		result += (*f) (n);

	return result;
}

int odd(int n)
{
	return 2 * n - 1;
}
