/*
 * The local variable n should be declared static so that it retains its value
 * when the print_error function returns.
 */
#include <stdio.h>

#define MAX_LEN 2000

void print_error(const char *message)
{
	static int n = 1; // should be declared static
	printf("Error %d: %s\n", n++, message);
}

int main(void)
{
	int num_calls = 0;
	char message[MAX_LEN + 2];

	printf("Enter a message: ");
	fgets(message, MAX_LEN + 2, stdin);

	do {
		printf("Enter the number of the error message: ");
		scanf("%d", &num_calls);
	} while (num_calls < 0);

	if (num_calls != 0)
		putchar('\n');
	for (int i = 1; i <= num_calls; i++)
		print_error(message);

	return 0;
}
