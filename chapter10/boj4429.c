/*
 * My solution to Problem 4429 from Baekjoon:
 * https://www.acmicpc.net/problem/4429.
 *
 * Compare several pairs of poker hands and to indicate which, if either, has a
 * higher rank.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_RANKS 14
#define NUM_SUITS 4
#define NUM_CARDS 5
#define NUM_HANDS 9
#define NUM_PLAYERS 2
#define BLACK 0
#define WHITE 1

bool read_cards(int black_rank[static NUM_CARDS],
		int black_suit[static NUM_CARDS],
		int white_rank[static NUM_CARDS],
		int white_suit[static NUM_CARDS]);
void count_num(int property_of_card[static NUM_CARDS], int num_property,
	       int num_in_property[num_property]);
void analyze_hand(int rank_of_card[static NUM_CARDS],
		  int num_in_rank[static NUM_RANKS],
		  int num_in_suit[static NUM_SUITS], int hand[NUM_PLAYERS],
		  int player);
void sort_cards(int rank_of_card[static NUM_CARDS],
		int suit_of_card[static NUM_CARDS],
		int num_in_rank[static NUM_RANKS]);
void compare_hands(int hand[NUM_PLAYERS], int black_rank[NUM_CARDS],
		   int white_rank[NUM_CARDS]);

int main(void)
{
	int black_rank[NUM_CARDS];
	int black_suit[NUM_CARDS];
	int white_rank[NUM_CARDS];
	int white_suit[NUM_CARDS];

	int num_in_black_rank[NUM_RANKS];
	int num_in_black_suit[NUM_SUITS];
	int num_in_white_rank[NUM_RANKS];
	int num_in_white_suit[NUM_SUITS];

	int hand[NUM_PLAYERS];

	while (1) {
		while (!read_cards(black_rank, black_suit, white_rank,
				   white_suit))
			/* empty loop body */ ;

		count_num(black_rank, NUM_RANKS, num_in_black_rank);
		count_num(black_suit, NUM_SUITS, num_in_black_suit);
		analyze_hand(black_rank, num_in_black_rank, num_in_black_suit,
			     hand, BLACK);
		sort_cards(black_rank, black_suit, num_in_black_rank);

		count_num(white_rank, NUM_RANKS, num_in_white_rank);
		count_num(white_suit, NUM_SUITS, num_in_white_suit);
		analyze_hand(white_rank, num_in_white_rank, num_in_white_suit,
			     hand, WHITE);
		sort_cards(white_rank, white_suit, num_in_white_rank);

		compare_hands(hand, black_rank, white_rank);
		putchar('\n');
	}

	return 0;
}

/*
 * Reads the cards into the arrays rank and suit for each player; checks for bad
 * cards and duplicate cards.
 *
 * Returns true when the function successfully reads the cards; otherwise,
 * returns false.
 */
bool read_cards(int black_rank[static NUM_CARDS],
		int black_suit[static NUM_CARDS],
		int white_rank[static NUM_CARDS],
		int white_suit[static NUM_CARDS])
{
	bool bad_card, duplicate_cards_exist;
	char rank_ch, suit_ch;
	int ch, rank, suit;
	int card = 0;

	while (card < 2 * NUM_CARDS) {
		bad_card = false;
		duplicate_cards_exist = false;

		rank_ch = getchar();
		switch (toupper(rank_ch)) {
		case '0':
			exit(EXIT_SUCCESS);
		case '2':
			rank = 1;
			break;
		case '3':
			rank = 2;
			break;
		case '4':
			rank = 3;
			break;
		case '5':
			rank = 4;
			break;
		case '6':
			rank = 5;
			break;
		case '7':
			rank = 6;
			break;
		case '8':
			rank = 7;
			break;
		case '9':
			rank = 8;
			break;
		case 'T':
			rank = 9;
			break;
		case 'J':
			rank = 10;
			break;
		case 'Q':
			rank = 11;
			break;
		case 'K':
			rank = 12;
			break;
		case 'A':
			rank = 13;
			break;
		default:
			bad_card = true;
		}

		suit_ch = getchar();
		switch (toupper(suit_ch)) {
		case 'C':
			suit = 0;
			break;
		case 'D':
			suit = 1;
			break;
		case 'H':
			suit = 2;
			break;
		case 'S':
			suit = 3;
			break;
		default:
			bad_card = true;
		}

		ch = getchar();
		if (ch != '\n' && ch != EOF) {
			if (!isspace(ch)) {
				bad_card = true;
			} else if (card == 2 * NUM_CARDS - 1) {
				while (getchar() != '\n')
					/* empty loop body */ ;
			}
		} else if (card < 2 * NUM_CARDS - 1) {
			printf("Few cards; ignored.\n");

			return false;
		}

		if (bad_card) {
			printf("Bad card; ignored.\n");
			if (card < 2 * NUM_CARDS - 1) {
				while (getchar() != '\n')
					/* empty loop body */ ;
			}

			return false;
		}

		if (card / NUM_CARDS == 0) {
			black_rank[card] = rank;
			black_suit[card] = suit;

			for (int i = 0; i < card; i++) {
				if (black_rank[i] == rank &&
				    black_suit[i] == suit) {
					duplicate_cards_exist = true;
					break;
				}
			}
		} else {
			white_rank[card % NUM_CARDS] = rank;
			white_suit[card % NUM_CARDS] = suit;

			for (int i = 0; i < card % NUM_CARDS; i++) {
				if (white_rank[i] == rank &&
				    white_suit[i] == suit) {
					duplicate_cards_exist = true;
					break;
				}
			}
		}

		if (duplicate_cards_exist) {
			printf("Duplicate card; ignored.\n");
			if (card < 2 * NUM_CARDS - 1) {
				while (getchar() != '\n')
					/* empty loop body */ ;
			}

			return false;
		} else {
			card++;
		}
	}

	return true;
}

/* Count the number of the cards that share the same property. */
void count_num(int property_of_card[static NUM_CARDS], int num_property,
	       int num_in_property[num_property])
{
	for (int property = 0; property < num_property; property++) {
		num_in_property[property] = 0;

		for (int card = 0; card < NUM_CARDS; card++) {
			if (property_of_card[card] == property)
				num_in_property[property]++;
		}
	}
}

/*
 * Determines whether the hand contains a straight, a flush, four-of-a-kind,
 * and/or three-of-a-kind; determines the number of pairs; stores the results
 * into the external variables straight, flush, four, three, and pairs.
 */
void analyze_hand(int rank_of_card[static NUM_CARDS],
		  int num_in_rank[static NUM_RANKS],
		  int num_in_suit[static NUM_SUITS], int hand[NUM_PLAYERS],
		  int player)
{
	int num_consec = 0;
	int rank, suit;

	bool straight = false;
	bool flush = false;
	bool four = false;
	bool three = false;
	int pairs = 0;

	/* check for flush */
	for (suit = 0; suit < NUM_SUITS; suit++)
		if (num_in_suit[suit] == NUM_CARDS)
			flush = true;

	/* check for straight */
	rank = 0;
	while (num_in_rank[rank] == 0)
		rank++;
	for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
		num_consec++;
	if (num_consec == NUM_CARDS) {
		straight = true;
	} else if (num_consec == NUM_CARDS - 1 &&
		   num_in_rank[NUM_RANKS - 1] > 0) {
		straight = true;	// ace-low straight

		/* ace should be low */
		for (int card = 0; card < NUM_CARDS; card++) {
			if (rank_of_card[card] == NUM_RANKS - 1) {
				rank_of_card[card] = 0;
				num_in_rank[NUM_RANKS - 1] = 0;
				num_in_rank[0] = 1;
			}
		}
	}

	if (straight) {
		if (flush) {
			hand[player] = 8;

			return;
		}
		hand[player] = 4;

		return;
	}

	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	for (rank = 0; rank < NUM_RANKS; rank++) {
		if (num_in_rank[rank] == 4)
			four = true;
		else if (num_in_rank[rank] == 3)
			three = true;
		else if (num_in_rank[rank] == 2)
			pairs++;
	}

	if (four)
		hand[player] = 7;
	else if (three && pairs == 1)
		hand[player] = 6;
	else if (flush)
		hand[player] = 5;
	else if (three)
		hand[player] = 3;
	else if (pairs == 2)
		hand[player] = 2;
	else if (pairs == 1)
		hand[player] = 1;
	else
		hand[player] = 0;	// high card
}

/* Sort the cards in descending order. */
void sort_cards(int rank_of_card[static NUM_CARDS],
		int suit_of_card[static NUM_CARDS],
		int num_in_rank[static NUM_RANKS])
{
	int num = NUM_SUITS, rank = NUM_RANKS - 1, suit, card,
		cards_left = NUM_CARDS, start;

	while (num > 0) {
		while (rank >= 0) {
			if (num_in_rank[rank] == num)
				break;
			rank--;
		}

		if (rank < 0) {
			rank = NUM_RANKS - 1;
			num--;
			continue;
		}

		for (int count = 0; count < num; count++) {
			start = NUM_CARDS - cards_left + count;
			card = start;
			while (card < NUM_CARDS) {
				if (rank_of_card[card] == rank)
					break;
				card++;
			}

			suit = suit_of_card[card];
			for (int i = card - 1; i >= start; i--) {
				rank_of_card[i + 1] = rank_of_card[i];
				suit_of_card[i + 1] = suit_of_card[i];
			}
			rank_of_card[start] = rank;
			suit_of_card[start] = suit;
		}

		cards_left -= num;
		if (cards_left < num) {
			num = cards_left;
			rank = NUM_RANKS - 1;
		} else {
			rank--;
		}
	}
}

void compare_hands(int hand[NUM_PLAYERS], int black_rank[NUM_CARDS],
		   int white_rank[NUM_CARDS])
{
	bool black_wins = false, white_wins = false, tie = false;
	int card, rank;

	if (hand[BLACK] > hand[WHITE]) {
		black_wins = true;
	} else if (hand[BLACK] < hand[WHITE]) {
		white_wins = true;
	} else {
		for (card = 0; card < NUM_CARDS; card++) {
			if (card > 0) {
				while (black_rank[card] == rank)
					card++;
			}

			if (black_rank[card] > white_rank[card]) {
				black_wins = true;
				break;
			} else if (black_rank[card] < white_rank[card]) {
				white_wins = true;
				break;
			} else {
				rank = black_rank[card];
			}
		}

		if (card == NUM_CARDS)
			tie = true;
	}

	if (black_wins)
		printf("Black wins.");
	else if (white_wins)
		printf("White wins.");
	else if (tie)
		printf("Tie.");
	else
		printf("Error.");
}
