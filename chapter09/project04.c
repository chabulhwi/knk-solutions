#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define NUM_ALP 26

void read_word(int counts[NUM_ALP]);
bool equal_array(int counts1[NUM_ALP], int counts2[NUM_ALP]);

int main(void)
{
	int counts1[NUM_ALP] = { 0 }, counts2[NUM_ALP] = { 0 };

	printf("Enter first word: ");
	read_word(counts1);

	printf("Enter second word: ");
	read_word(counts2);

	if (equal_array(counts1, counts2))
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");

	return 0;
}

void read_word(int counts[NUM_ALP])
{
	char ch;

	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			switch (tolower(ch)) {
			case 'a':
				counts[0]++;
				break;
			case 'b':
				counts[1]++;
				break;
			case 'c':
				counts[2]++;
				break;
			case 'd':
				counts[3]++;
				break;
			case 'e':
				counts[4]++;
				break;
			case 'f':
				counts[5]++;
				break;
			case 'g':
				counts[6]++;
				break;
			case 'h':
				counts[7]++;
				break;
			case 'i':
				counts[8]++;
				break;
			case 'j':
				counts[9]++;
				break;
			case 'k':
				counts[10]++;
				break;
			case 'l':
				counts[11]++;
				break;
			case 'm':
				counts[12]++;
				break;
			case 'n':
				counts[13]++;
				break;
			case 'o':
				counts[14]++;
				break;
			case 'p':
				counts[15]++;
				break;
			case 'q':
				counts[16]++;
				break;
			case 'r':
				counts[17]++;
				break;
			case 's':
				counts[18]++;
				break;
			case 't':
				counts[19]++;
				break;
			case 'u':
				counts[20]++;
				break;
			case 'v':
				counts[21]++;
				break;
			case 'w':
				counts[22]++;
				break;
			case 'x':
				counts[23]++;
				break;
			case 'y':
				counts[24]++;
				break;
			case 'z':
				counts[25]++;
				break;
			}
		}
	}
}

bool equal_array(int counts1[NUM_ALP], int counts2[NUM_ALP])
{
	for (int i = 0; i < NUM_ALP; i++) {
		if (counts1[i] != counts2[i])
			return false;
	}

	return true;
}
