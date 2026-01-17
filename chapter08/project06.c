#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main(void)
{
	char message[MAX_SIZE] = { 0 };

	printf("Enter message: ");
	for (int i = 0; i < MAX_SIZE; i++) {
		message[i] = getchar();
		if (message[i] == '\n')
			break;
	}

	printf("In B1FF-speak: ");
	for (int i = 0; i < MAX_SIZE; i++) {
		if (i == MAX_SIZE - 1 || message[i + 1] == '\n') {
			if (message[i] == '.')
				message[i] = '!';
			putchar(message[i]);
			break;
		}

		message[i] = toupper(message[i]);
		switch (message[i]) {
		case 'A':
			message[i] = '4';
			break;
		case 'B':
			message[i] = '8';
			break;
		case 'E':
			message[i] = '3';
			break;
		case 'I':
			message[i] = '1';
			break;
		case 'O':
			message[i] = '0';
			break;
		case 'S':
			message[i] = '5';
			break;
		default:
			break;
		}

		putchar(message[i]);
	}
	for (int i = 1; i <= 10; i++)
		putchar('!');
	putchar('\n');

	return 0;
}
