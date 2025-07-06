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
	for (char *p = message;;) {
		if (p >= message + n || (ch = getchar()) == '\n') {
			msg_len = p - message;
			break;
		}

		if (isalpha(ch)) {
			*p = tolower(ch);
			p++;
		}
	}

	for (char *p = message; p <= message + (msg_len - 1) / 2; p++) {
		if (*p != *(message + (message + msg_len - 1 - p))) {
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
