#include <stdio.h>

int main(void)
{
	int a[] = { 5, 15, 34, 54, 14, 2, 52, 72 };
	int *p = &a[1], *q = &a[5];

	printf("(a) %d\n", *(p + 3));	// 14
	printf("(b) %d\n", *(q - 3));	// 34
	printf("(c) %d\n", (int)(q - p));	// 4

	printf("(d) ");		// true
	if (p < q)
		printf("true\n");
	else
		printf("false\n");

	printf("(e) ");		// false
	if (*p < *q)
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
