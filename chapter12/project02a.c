#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
	bool palindrome = true;
	char ch;
	int n, msg_len;

	do {
		printf("Enter the maximum length of the message: ");
		scanf("%d", &n);
	} while (n <= 0);

	// dispose of the previous characters
	while (getchar() != '\n')
		/* empty loop body */ ;

	char message[n];

	printf("Enter a message: ");
	for (int i = 0;;) {
		if (i >= n || (ch = getchar()) == '\n') {
			msg_len = i;
			break;
		}

		if (isalpha(ch)) {
			message[i] = tolower(ch);
			i++;
		}
	}

	for (int i = 0; i <= (msg_len - 1) / 2; i++) {
		if (message[i] != message[msg_len - 1 - i]) {
			palindrome = false;
			break;
		}
	}

	if (palindrome)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}
