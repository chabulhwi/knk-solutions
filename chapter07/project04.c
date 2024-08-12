/* Translates an alphabetic phone number into numeric form */

#include <stdio.h>

int main(void)
{
	char ch;

	printf("Enter phone number: ");
	do {
		ch = getchar();
		switch (ch) {
		case 'A':
		case 'a':
		case 'B':
		case 'b':
		case 'C':
		case 'c':
			putchar('2');
			break;
		case 'D':
		case 'd':
		case 'E':
		case 'e':
		case 'F':
		case 'f':
			putchar('3');
			break;
		case 'G':
		case 'g':
		case 'H':
		case 'h':
		case 'I':
		case 'i':
			putchar('4');
			break;
		case 'J':
		case 'j':
		case 'K':
		case 'k':
		case 'L':
		case 'l':
			putchar('5');
			break;
		case 'M':
		case 'm':
		case 'N':
		case 'n':
		case 'O':
		case 'o':
			putchar('6');
			break;
		case 'P':
		case 'p':
		case 'R':
		case 'r':
		case 'S':
		case 's':
			putchar('7');
			break;
		case 'T':
		case 't':
		case 'U':
		case 'u':
		case 'V':
		case 'v':
			putchar('8');
			break;
		case 'W':
		case 'w':
		case 'X':
		case 'x':
		case 'Y':
		case 'y':
			putchar('9');
			break;
		default:
			putchar(ch);
			break;
		}
	} while (ch != '\n');

	return 0;
}
