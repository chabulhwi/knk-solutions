/* Computes the Scrabble value of a word */

#include <stdio.h>
#include <ctype.h>

#define NUM_ALP 26

int main(void)
{
	const char value[NUM_ALP] = {
		1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
		1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
	};

	char ch;
	int num, sum = 0;

	printf("Enter a word: ");
	while ((ch = getchar()) != '\n') {
		ch = toupper(ch);
		switch (ch) {
		case 'A':
			num = 0;
			break;
		case 'B':
			num = 1;
			break;
		case 'C':
			num = 2;
			break;
		case 'D':
			num = 3;
			break;
		case 'E':
			num = 4;
			break;
		case 'F':
			num = 5;
			break;
		case 'G':
			num = 6;
			break;
		case 'H':
			num = 7;
			break;
		case 'I':
			num = 8;
			break;
		case 'J':
			num = 9;
			break;
		case 'K':
			num = 10;
			break;
		case 'L':
			num = 11;
			break;
		case 'M':
			num = 12;
			break;
		case 'N':
			num = 13;
			break;
		case 'O':
			num = 14;
			break;
		case 'P':
			num = 15;
			break;
		case 'Q':
			num = 16;
			break;
		case 'R':
			num = 17;
			break;
		case 'S':
			num = 18;
			break;
		case 'T':
			num = 19;
			break;
		case 'U':
			num = 20;
			break;
		case 'V':
			num = 21;
			break;
		case 'W':
			num = 22;
			break;
		case 'X':
			num = 23;
			break;
		case 'Y':
			num = 24;
			break;
		case 'Z':
			num = 25;
			break;
		default:
			break;
		}

		switch (ch) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			sum += value[num];
		default:
			break;
		}
	}

	printf("Scrabble value: %d\n", sum);

	return 0;
}
