#include <stdio.h>

int main(void)
{
	char ch;
	int vowel = 0;

	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n') {
		switch (ch) {
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			vowel++;
			break;
		default:
			break;
		}
	}

	printf("Your sentence contains %d vowels.\n", vowel);

	return 0;
}
