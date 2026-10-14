/*
 * The value of f(10) if f has never been called before: 0
 * The value of f(10) if f has been called 5 times previously: 50
 */
#include <stdio.h>
#include <stdlib.h>

#define NUM_PREVIOUS_CALLS 5

int f(int i)
{
	static int j = 0;
	return i * j++;
}

int main(void)
{
	int answer;

	if ((answer = f(10)) == 0) {
		printf("The value of f(10) if f has never been called before: %d\n",
		       answer);
		printf("The number of times f has been called: 1\n");
	} else {
		printf("Error: Bulhwi's solution is incorrect\n");
		exit(EXIT_FAILURE);
	}
	putchar('\n');

	for (int i = 2; i <= NUM_PREVIOUS_CALLS; i++) {
		printf("The value of f(10): %d\n", f(10));
		printf("The number of times f has been called: %d\n", i);
		putchar('\n');
	}

	if ((answer = f(10)) == NUM_PREVIOUS_CALLS * 10) {
		printf("The value of f(10) if f has been called %d times previously: %d\n",
		       NUM_PREVIOUS_CALLS, answer);
	} else {
		printf("Error: Bulhwi's solution is incorrect\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
