#include <stdio.h>

#define MAX_LEN 2000

int compute_vowel_count(const char *sentence);

int main(void)
{
	char sentence[MAX_LEN + 2];

	printf("Enter a sentence: ");
	fgets(sentence, MAX_LEN + 2, stdin);

	printf("Your sentence contains %d vowels.\n",
	       compute_vowel_count(sentence));

	return 0;
}

int compute_vowel_count(const char *sentence)
{
	int vowel = 0;
	for (int i = 0; sentence[i] != '\0'; i++) {
		switch (sentence[i]) {
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

	return vowel;
}
