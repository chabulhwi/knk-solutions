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
	for (int i = 0;; i++) {
		if (i >= n || (ch = getchar()) == '\n') {
			msg_len = i;
			break;
		}

		message[i] = ch;
	}

	printf("Reversal is: ");
	for (int i = msg_len - 1; i >= 0; i--)
		putchar(message[i]);
	putchar('\n');

	return 0;
}
