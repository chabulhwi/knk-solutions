#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool weekend[7] = { true, false, false, false, false, false, true };
	int i;

	printf("In most of the world, the weekend is Saturday and Sunday:\n\n");
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	for (i = 0; i < 7; i++) {
		if (weekend[i])
			printf(" O  ");
		else
			printf(" X  ");
	}
	printf("\n");

	return 0;
}
