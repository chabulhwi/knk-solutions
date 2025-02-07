#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define NUM_ALP 26

int main(void)
{
	bool words_are_anagrams = true;
	char ch;
	int letter_count[NUM_ALP] = { 0 };

	printf("Enter first word: ");
	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			switch (tolower(ch)) {
			case 'a':
				letter_count[0]++;
				break;
			case 'b':
				letter_count[1]++;
				break;
			case 'c':
				letter_count[2]++;
				break;
			case 'd':
				letter_count[3]++;
				break;
			case 'e':
				letter_count[4]++;
				break;
			case 'f':
				letter_count[5]++;
				break;
			case 'g':
				letter_count[6]++;
				break;
			case 'h':
				letter_count[7]++;
				break;
			case 'i':
				letter_count[8]++;
				break;
			case 'j':
				letter_count[9]++;
				break;
			case 'k':
				letter_count[10]++;
				break;
			case 'l':
				letter_count[11]++;
				break;
			case 'm':
				letter_count[12]++;
				break;
			case 'n':
				letter_count[13]++;
				break;
			case 'o':
				letter_count[14]++;
				break;
			case 'p':
				letter_count[15]++;
				break;
			case 'q':
				letter_count[16]++;
				break;
			case 'r':
				letter_count[17]++;
				break;
			case 's':
				letter_count[18]++;
				break;
			case 't':
				letter_count[19]++;
				break;
			case 'u':
				letter_count[20]++;
				break;
			case 'v':
				letter_count[21]++;
				break;
			case 'w':
				letter_count[22]++;
				break;
			case 'x':
				letter_count[23]++;
				break;
			case 'y':
				letter_count[24]++;
				break;
			case 'z':
				letter_count[25]++;
				break;
			}
		}
	}

	printf("Enter second word: ");
	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			switch (tolower(ch)) {
			case 'a':
				letter_count[0]--;
				break;
			case 'b':
				letter_count[1]--;
				break;
			case 'c':
				letter_count[2]--;
				break;
			case 'd':
				letter_count[3]--;
				break;
			case 'e':
				letter_count[4]--;
				break;
			case 'f':
				letter_count[5]--;
				break;
			case 'g':
				letter_count[6]--;
				break;
			case 'h':
				letter_count[7]--;
				break;
			case 'i':
				letter_count[8]--;
				break;
			case 'j':
				letter_count[9]--;
				break;
			case 'k':
				letter_count[10]--;
				break;
			case 'l':
				letter_count[11]--;
				break;
			case 'm':
				letter_count[12]--;
				break;
			case 'n':
				letter_count[13]--;
				break;
			case 'o':
				letter_count[14]--;
				break;
			case 'p':
				letter_count[15]--;
				break;
			case 'q':
				letter_count[16]--;
				break;
			case 'r':
				letter_count[17]--;
				break;
			case 's':
				letter_count[18]--;
				break;
			case 't':
				letter_count[19]--;
				break;
			case 'u':
				letter_count[20]--;
				break;
			case 'v':
				letter_count[21]--;
				break;
			case 'w':
				letter_count[22]--;
				break;
			case 'x':
				letter_count[23]--;
				break;
			case 'y':
				letter_count[24]--;
				break;
			case 'z':
				letter_count[25]--;
				break;
			}
		}
	}

	for (int i = 0; i < NUM_ALP; i++) {
		if (letter_count[i] != 0)
			words_are_anagrams = false;
	}

	if (words_are_anagrams)
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");

	return 0;
}
