/* Output: `9384 938 93 9 ` */

#include <stdio.h>

int main(void)
{
	for (int i = 9384;;) {
		printf("%d ", i);
		i /= 10;
		if (i == 0)
			break;
	}

	return 0;
}
