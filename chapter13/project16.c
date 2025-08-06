#include <stdio.h>
#include <string.h>

#define MAX_LEN 2000

void reverse(char *message);

int main(void)
{
	char message[MAX_LEN + 2];

	printf("Enter a message: ");
	fgets(message, MAX_LEN + 2, stdin);

	reverse(message);
	printf("Reversal is: %s", message);

	return 0;
}

void reverse(char *message)
{
	char *low = message, *high = message + strlen(message) - 2, tmp;

	while (low < high) {
		tmp = *low;
		*low = *high;
		*high = tmp;
		low++;
		high--;
	}
}
