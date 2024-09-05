#include <stdio.h>

int main(void)
{
	int fib_numbers[40];
	fib_numbers[0] = 0;
	fib_numbers[1] = 1;

	printf("The Fibonacci numbers:\n");
	for (int i = 0; i < 40; i++) {
		if (i >= 2)
			fib_numbers[i] = fib_numbers[i - 2] +
				fib_numbers[i - 1];

		printf("%8d", fib_numbers[i]);

		if (i % 10 == 9)
			putchar('\n');
		else
			putchar(' ');
	}

	return 0;
}
