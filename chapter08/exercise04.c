#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	bool weekend[7] = { true,[6] = true };

	printf("In most of the world, the weekend is Saturday and Sunday:\n\n");
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	for (int i = 0; i < 7; i++) {
		if (weekend[i])
			printf(" O  ");
		else
			printf(" X  ");
	}
	printf("\n");

	return 0;
}
