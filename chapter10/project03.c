/* Classifies a poker hand */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_CARDS 5
#define NUM_RANKS 13
#define RANK 0
#define SUIT 1

bool straight, flush, four, three;
int pairs;			// can be 0, 1, or 2

void read_cards(int num_cards, int hand[static num_cards][2]);
void analyze_hand(int num_cards, int hand[static num_cards][2]);
void print_result(int num_cards, int hand[static num_cards][2]);

int main(void)
{
	int hand[NUM_CARDS][2];

	while (1) {
		read_cards(NUM_CARDS, hand);
		analyze_hand(NUM_CARDS, hand);
		print_result(NUM_CARDS, hand);
	}
}

/*
 * Reads the cards into the variable hand; checks for bad cards and duplicate
 * cards.
 */
void read_cards(int num_cards, int hand[static num_cards][2])
{
	bool bad_card, duplicate_cards_exist;
	char ch, rank_ch, suit_ch;
	int rank, suit;
	int cards_read = 0;

	while (cards_read < NUM_CARDS) {
		bad_card = false;
		duplicate_cards_exist = false;

		printf("Enter a card: ");

		scanf(" %c", &rank_ch);
		switch (rank_ch) {
		case '0':
			exit(EXIT_SUCCESS);
		case '2':
			rank = 0;
			break;
		case '3':
			rank = 1;
			break;
		case '4':
			rank = 2;
			break;
		case '5':
			rank = 3;
			break;
		case '6':
			rank = 4;
			break;
		case '7':
			rank = 5;
			break;
		case '8':
			rank = 6;
			break;
		case '9':
			rank = 7;
			break;
		case 't':
		case 'T':
			rank = 8;
			break;
		case 'j':
		case 'J':
			rank = 9;
			break;
		case 'q':
		case 'Q':
			rank = 10;
			break;
		case 'k':
		case 'K':
			rank = 11;
			break;
		case 'a':
		case 'A':
			rank = 12;
			break;
		default:
			bad_card = true;
		}

		scanf(" %c", &suit_ch);
		switch (suit_ch) {
		case 'c':
		case 'C':
			suit = 0;
			break;
		case 'd':
		case 'D':
			suit = 1;
			break;
		case 'h':
		case 'H':
			suit = 2;
			break;
		case 's':
		case 'S':
			suit = 3;
			break;
		default:
			bad_card = true;
		}

		if ((ch = getchar()) != '\n') {
			if (!isspace(ch))
				bad_card = true;

			while (getchar() != '\n')
				/* empty loop body */ ;
		}

		hand[cards_read][RANK] = rank;
		hand[cards_read][SUIT] = suit;

		for (int card = 0; card < cards_read; card++) {
			if (hand[card][RANK] == rank &&
			    hand[card][SUIT] == suit)
				duplicate_cards_exist = true;
		}

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (duplicate_cards_exist)
			printf("Duplicate card; ignored.\n");
		else
			cards_read++;
	}
}

/*
 * Determines whether the hand contains a straight, a flush, four-of-a-kind,
 * and/or three-of-a-kind; determines the number of pairs; stores the results
 * into the external variables straight, flush, four, three, and pairs.
 */
void analyze_hand(int num_cards, int hand[static num_cards][2])
{
	bool card_exists;
	int min_rank, num_in_rank;

	straight = true;
	flush = true;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	for (int card = 1; card < NUM_CARDS; card++) {
		if (hand[card][SUIT] != hand[0][SUIT])
			flush = false;
	}

	/* check for straight */
	for (int rank = 0; rank < NUM_RANKS; rank++) {
		card_exists = false;

		for (int card = 0; card < NUM_CARDS; card++) {
			if (hand[card][RANK] == rank)
				card_exists = true;
		}

		if (card_exists) {
			min_rank = rank;
			break;
		}
	}

	for (int rank = min_rank + 1; rank < min_rank + NUM_CARDS - 1; rank++) {
		card_exists = false;

		for (int card = 0; card < NUM_CARDS; card++) {
			if (hand[card][RANK] == rank)
				card_exists = true;
		}

		if (!card_exists)
			straight = false;
	}

	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	for (int rank = 0; rank < NUM_RANKS; rank++) {
		num_in_rank = 0;
		for (int card = 0; card < NUM_CARDS; card++) {
			if (hand[card][RANK] == rank)
				num_in_rank++;
		}

		switch (num_in_rank) {
		case 2:
			pairs++;
			break;
		case 3:
			three = true;
			break;
		case 4:
			four = true;
			break;
		}
	}
}

/*
 * Prints the classification of the hand, based on the values of the external
 * variables straight, flush, four, three, and pairs.
 */
void print_result(int num_cards, int hand[static num_cards][2])
{
	if (straight && flush)
		printf("Straight flush");
	else if (four)
		printf("Four of a kind");
	else if (three && pairs == 1)
		printf("Full house");
	else if (flush)
		printf("Flush");
	else if (straight)
		printf("Straight");
	else if (three)
		printf("Three of a kind");
	else if (pairs == 2)
		printf("Two pairs");
	else if (pairs == 1)
		printf("Pair");
	else
		printf("High card");

	printf("\n\n");
}
