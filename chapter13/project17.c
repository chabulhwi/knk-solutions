#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 2000

bool is_palindrome(const char *message);

int main(void)
{
	char message[MAX_LEN + 2];

	printf("Enter a message: ");
	fgets(message, MAX_LEN + 2, stdin);

	if (is_palindrome(message))
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}

bool is_palindrome(const char *message)
{
	const char *low = message, *high = message + strlen(message) - 2;

	while (low < high) {
		if (isalpha(*low) && isalpha(*high)) {
			if (tolower(*low) != tolower(*high)) {
				return false;
			} else {
				low++;
				high--;
			}
		} else {
			if (!isalpha(*low))
				low++;

			if (!isalpha(*high))
				high--;
		}
	}

	return true;
}
