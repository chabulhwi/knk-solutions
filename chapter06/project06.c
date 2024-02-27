#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter a positive number: ");
	scanf("%d", &n);

	printf("All even squares between 1 and %d:\n", n);
	for (int i = 2; i * i <= n; i += 2)
		printf("%d\n", i * i);

	return 0;
}
