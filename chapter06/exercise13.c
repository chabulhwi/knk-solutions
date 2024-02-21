/* Output: `n = 4, m = 0` */

#include <stdio.h>

int main(void)
{
	int n, m;

	m = 10;
	for (n = 0; m > 0; m /= 2, n++)
		/* empty loop body */ ;

	printf("n = %d, m = %d\n", n, m);

	return 0;
}
