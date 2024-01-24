#include <stdio.h>

int main(void) {
	int n;

	printf("Enter a three-digit number: ");
	scanf("%3d", &n);

	printf("The reversal is: %d%d%d\n", n % 10, (n / 10) % 10,
	       (n / 10) / 10);

	return 0;
}
