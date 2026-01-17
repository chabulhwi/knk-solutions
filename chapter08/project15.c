#include <stdio.h>
#include <ctype.h>

#define NUM_ALP 26
#define LENGTH 81

int main(void)
{
	int actual_length = 0, shift = 0, index;
	char ch, message[LENGTH];
	const char letter[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
	};

	printf("Enter message to be encrypted:\n\n");
	while (1) {
		if (actual_length > LENGTH) {
			printf("\nError: the message is too long.\n");

			return 1;
		}

		if ((ch = getchar()) != '\n' && actual_length < LENGTH) {
			message[actual_length] = ch;
			actual_length++;
		} else {
			break;
		}
	}

	do {
		printf("\nEnter shift amount (0-25): ");
		scanf("%d", &shift);
	} while (shift < 0 || shift >= NUM_ALP);

	printf("\nEncrypted message:\n\n");
	for (int i = 0; i < actual_length; i++) {
		switch (message[i]) {
		case 'A':
			index = 0;
			break;
		case 'B':
			index = 1;
			break;
		case 'C':
			index = 2;
			break;
		case 'D':
			index = 3;
			break;
		case 'E':
			index = 4;
			break;
		case 'F':
			index = 5;
			break;
		case 'G':
			index = 6;
			break;
		case 'H':
			index = 7;
			break;
		case 'I':
			index = 8;
			break;
		case 'J':
			index = 9;
			break;
		case 'K':
			index = 10;
			break;
		case 'L':
			index = 11;
			break;
		case 'M':
			index = 12;
			break;
		case 'N':
			index = 13;
			break;
		case 'O':
			index = 14;
			break;
		case 'P':
			index = 15;
			break;
		case 'Q':
			index = 16;
			break;
		case 'R':
			index = 17;
			break;
		case 'S':
			index = 18;
			break;
		case 'T':
			index = 19;
			break;
		case 'U':
			index = 20;
			break;
		case 'V':
			index = 21;
			break;
		case 'W':
			index = 22;
			break;
		case 'X':
			index = 23;
			break;
		case 'Y':
			index = 24;
			break;
		case 'Z':
			index = 25;
			break;
		case 'a':
			index = 26 + 0;
			break;
		case 'b':
			index = 26 + 1;
			break;
		case 'c':
			index = 26 + 2;
			break;
		case 'd':
			index = 26 + 3;
			break;
		case 'e':
			index = 26 + 4;
			break;
		case 'f':
			index = 26 + 5;
			break;
		case 'g':
			index = 26 + 6;
			break;
		case 'h':
			index = 26 + 7;
			break;
		case 'i':
			index = 26 + 8;
			break;
		case 'j':
			index = 26 + 9;
			break;
		case 'k':
			index = 26 + 10;
			break;
		case 'l':
			index = 26 + 11;
			break;
		case 'm':
			index = 26 + 12;
			break;
		case 'n':
			index = 26 + 13;
			break;
		case 'o':
			index = 26 + 14;
			break;
		case 'p':
			index = 26 + 15;
			break;
		case 'q':
			index = 26 + 16;
			break;
		case 'r':
			index = 26 + 17;
			break;
		case 's':
			index = 26 + 18;
			break;
		case 't':
			index = 26 + 19;
			break;
		case 'u':
			index = 26 + 20;
			break;
		case 'v':
			index = 26 + 21;
			break;
		case 'w':
			index = 26 + 22;
			break;
		case 'x':
			index = 26 + 23;
			break;
		case 'y':
			index = 26 + 24;
			break;
		case 'z':
			index = 26 + 25;
			break;
		default:
			break;
		}

		if (isalpha(message[i])) {
			if (isupper(message[i]))
				index = (index + shift) % NUM_ALP;
			else if (islower(message[i]))
				index = NUM_ALP + (index + shift) % NUM_ALP;

			putchar(letter[index]);
		} else {
			putchar(message[i]);
		}
	}

	putchar('\n');

	return 0;
}
