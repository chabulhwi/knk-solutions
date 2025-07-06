#include <stdio.h>

int main(void)
{
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
	for (char *p = message;; p++) {
		if (p >= message + n || (ch = getchar()) == '\n') {
			msg_len = p - message;
			break;
		}

		*p = ch;
	}

	printf("Reversal is: ");
	for (char *p = message + msg_len - 1; p >= message; p--)
		putchar(*p);
	putchar('\n');

	return 0;
}
