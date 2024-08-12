/* Prints a table of squares using a for statement */

#include <stdio.h>

int main(void)
{
	int i, n;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	// dispose of the characters following number of entries
	while (getchar() != '\n')
		/* empty loop body */ ;

	for (i = 1; i <= n; i++) {
		printf("%10d%10d\n", i, i * i);
		if (i % 24 == 0) {
			printf("Press Enter to continue...");

			// wait until the user presses the Enter key
			while (getchar() != '\n')
				/* empty loop body */ ;
		}
	}

	return 0;
}
