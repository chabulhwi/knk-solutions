#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

int compare_ints(const void *p, const void *q);

int main(void)
{
	int a[LENGTH];

	for (int i = 0; i < LENGTH; i++)
		a[i] = LENGTH - i;

	qsort(&a[LENGTH / 2], LENGTH / 2, sizeof(a[0]), compare_ints);

	printf("Result:\n\n");
	for (int i = 0; i < LENGTH; i++) {
		if (i % 10 == 0)
			printf("  ");

		printf("%3d", a[i]);

		if (i % 10 == 9)
			putchar('\n');
		else
			putchar(' ');
	}
	printf("\n");

	return 0;
}

int compare_ints(const void *p, const void *q)
{
	if (*(int *)p < *(int *)q)
		return -1;
	else if (*(int *)p == *(int *)q)
		return 0;
	else
		return 1;
}
