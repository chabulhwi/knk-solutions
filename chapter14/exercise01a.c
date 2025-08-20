#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))

int main(void)
{
	printf("2 ^ 3 == %d\n", CUBE(2));
	printf("3.14 ^ 3 == %.2lf\n", CUBE(3.14));
	printf("'A' ^ 3 == %c\n", CUBE('A'));	// this won't work

	return 0;
}
