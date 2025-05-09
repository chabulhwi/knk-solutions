/* Output: i = 1, j = 2
 *
 * Note that any changes made to a function's parameter during the execution of
 * the function don’t affect the corresponding argument.
 */

#include <stdio.h>

void swap(int a, int b);

int main(void)
{
	int i = 1, j = 2;

	swap(i, j);
	printf("i = %d, j = %d\n", i, j);
	return 0;
}

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
