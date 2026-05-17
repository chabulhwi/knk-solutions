/*
 * True. (&x)->a is the same as (*&x).a, which is equivalent to x.a.
 */

#include <stdio.h>

int main(void)
{
	struct {
		int a;
	} x;

	printf("Enter an integer: ");
	scanf("%d", &(&x)->a);

	printf("The value of (&x)->a is %d.\n", (&x)->a);
	if ((&x)->a == x.a)
		printf("It's the same as x.a.\n");
	else
		printf("It's different from x.a.\n");

	putchar('\n');
	printf("Enter an integer: ");
	scanf("%d", &x.a);

	printf("The value of x.a is %d.\n", x.a);
	if ((&x)->a == x.a)
		printf("It's the same as (&x)->a.\n");
	else
		printf("It's different from (&x)->a.\n");

	return 0;
}
