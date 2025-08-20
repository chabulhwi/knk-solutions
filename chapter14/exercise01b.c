#include <stdio.h>

#define MOD4(n) ((n) % 4)

int main(void)
{
	printf("43 %% 4 == %d\n", MOD4(43));
	printf("3.14 %% 4 == %d\n", MOD4(3.14));	// this won't work

	return 0;
}
