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

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define NUM_PLAYERS 2

#define RANK 0
#define SUIT 1
#define RANK_SUIT 2

#define BLACK 0
#define WHITE 1

bool straight[NUM_PLAYERS], flush[NUM_PLAYERS], four[NUM_PLAYERS],
	three[NUM_PLAYERS];
int pairs[NUM_PLAYERS];		// can be 0, 1, or 2

int read_line(int num_players, int num_cards, int num_ranks, int num_suits,
	      int hand[num_players][num_cards][RANK_SUIT],
	      int num_in_rank[num_players][num_ranks],
	      int num_in_suit[num_players][num_suits]);
void analyze_hands(int num_players, int num_cards, int num_ranks, int num_suits,
		   int hand[num_players][num_cards][RANK_SUIT],
		   int num_in_rank[num_players][num_ranks],
		   int num_in_suit[num_players][num_suits]);
void print_result(int num_players, int num_cards, int num_ranks, int num_suits,
		  int hand[num_players][num_cards][RANK_SUIT],
		  int num_in_rank[num_players][num_ranks],
		  int num_in_suit[num_players][num_suits]);

int main(void)
{
	int hand[NUM_PLAYERS][NUM_CARDS][RANK_SUIT];
	int num_in_rank[NUM_PLAYERS][NUM_RANKS];
	int num_in_suit[NUM_PLAYERS][NUM_SUITS];

	while (1) {
		switch (read_line
			(NUM_PLAYERS, NUM_CARDS, NUM_RANKS, NUM_SUITS, hand,
			 num_in_rank, num_in_suit)) {
		case 1:
			analyze_hands(NUM_PLAYERS, NUM_CARDS, NUM_RANKS,
				      NUM_SUITS, hand, num_in_rank,
				      num_in_suit);
			print_result(NUM_PLAYERS, NUM_CARDS, NUM_RANKS,
				     NUM_SUITS, hand, num_in_rank, num_in_suit);
			break;
		case 2:
			analyze_hands(NUM_PLAYERS, NUM_CARDS, NUM_RANKS,
				      NUM_SUITS, hand, num_in_rank,
				      num_in_suit);
			print_result(NUM_PLAYERS, NUM_CARDS, NUM_RANKS,
				     NUM_SUITS, hand, num_in_rank, num_in_suit);
			return 0;
		}
	}
}

/*
 * Reads a line containing the designation of 10 cards: the first 5 cards are
 * the hand for the player named "Black" and the next 5 cards are the hand for
 * the player named "White."
 *
 * Checks for bad cards and duplicate cards.
 *
 * (a) If the line has a bad card, too few cards, or duplicate cards, the
 *     function returns 0.
 * (b) If the line isn't the last one, it returns 1.
 * (c) If the line is the last one, it returns 2.
 */
int read_line(int num_players, int num_cards, int num_ranks, int num_suits,
	      int hand[num_players][num_cards][RANK_SUIT],
	      int num_in_rank[num_players][num_ranks],
	      int num_in_suit[num_players][num_suits])
{
	bool bad_card, duplicate_cards_exist;
	char ch, rank_ch, suit_ch;
	int rank, suit;

	for (int player = 0; player < num_players; player++) {
		for (rank = 0; rank < NUM_RANKS; rank++)
			num_in_rank[player][rank] = 0;

		for (suit = 0; suit < NUM_SUITS; suit++)
			num_in_suit[player][suit] = 0;

		int cards_read = 0;
		while (cards_read < num_cards) {
			bad_card = false;
			duplicate_cards_exist = false;

			scanf(" %c", &rank_ch);
			switch (toupper(rank_ch)) {
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
			case 'T':
				rank = 8;
				break;
			case 'J':
				rank = 9;
				break;
			case 'Q':
				rank = 10;
				break;
			case 'K':
				rank = 11;
				break;
			case 'A':
				rank = 12;
				break;
			default:
				bad_card = true;
			}

			scanf(" %c", &suit_ch);
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

			if (bad_card) {
				printf("Bad card; ignored.\n");
				return 0;
			}

			ch = getchar();
			if (ch != '\n' && ch != EOF) {
				if (isspace(ch))
					scanf(" ");
				else
					bad_card = true;
			} else if (player < num_players - 1 ||
				   cards_read < num_cards - 1) {
				printf("Few cards; ignored.\n");
				return 0;
			} else if (ch == EOF) {
				return 2;
			}

			hand[player][cards_read][RANK] = rank;
			hand[player][cards_read][SUIT] = suit;

			for (int card = 0; card < cards_read; card++) {
				if (hand[player][card][RANK] == rank &&
				    hand[player][card][SUIT] == suit)
					duplicate_cards_exist = true;
			}

			if (duplicate_cards_exist) {
				printf("Duplicate card; ignored.\n");
				return 0;
			} else {
				num_in_rank[player][rank]++;
				num_in_suit[player][suit]++;
				cards_read++;
			}
		}
	}

	return 1;
}

/*
 * Determines whether each player's hand contains a straight, a flush,
 * four-of-a-kind, and/or three-of-a-kind; determines the number of pairs;
 * stores the results into the external variables straight, flush, four, three,
 * and pairs.
 */
void analyze_hands(int num_players, int num_cards, int num_ranks, int num_suits,
		   int hand[num_players][num_cards][RANK_SUIT],
		   int num_in_rank[num_players][num_ranks],
		   int num_in_suit[num_players][num_suits])
{
	bool card_exists;
	int min_rank;

	for (int player = 0; player < num_players; player++) {
		/* sort cards by rank */
		for (int pass = 1; pass < NUM_CARDS; pass++) {
			for (int card = 0; card < NUM_CARDS - pass; card++) {
				int rank = hand[player][card][RANK];
				int suit = hand[player][card][SUIT];

				if (hand[player][card + 1][RANK] > rank) {
					hand[player][card][RANK] =
						hand[player][card + 1][RANK];
					hand[player][card][SUIT] =
						hand[player][card + 1][SUIT];
					hand[player][card + 1][RANK] = rank;
					hand[player][card + 1][SUIT] = suit;
				}
			}
		}

		straight[player] = true;
		flush[player] = true;
		four[player] = false;
		three[player] = false;
		pairs[player] = 0;

		/* check for flush */
		for (int card = 0; card < num_cards; card++) {
			if (hand[player][card][SUIT] != hand[player][0][SUIT])
				flush[player] = false;
		}

		/* check for straight */
		for (int rank = 0; rank < NUM_RANKS; rank++) {
			card_exists = false;

			for (int card = 0; card < num_cards; card++) {
				if (hand[player][card][RANK] == rank)
					card_exists = true;
			}

			if (card_exists) {
				min_rank = rank;
				break;
			}
		}

		for (int rank = min_rank + 1; rank < min_rank + num_cards - 1;
		     rank++) {
			card_exists = false;

			for (int card = 0; card < num_cards; card++) {
				if (hand[player][card][RANK] == rank)
					card_exists = true;
			}

			if (!card_exists)
				straight[player] = false;
		}

		/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
		for (int rank = 0; rank < NUM_RANKS; rank++) {
			switch (num_in_rank[player][rank]) {
			case 2:
				pairs[player]++;
				break;
			case 3:
				three[player] = true;
				break;
			case 4:
				four[player] = true;
				break;
			}
		}
	}
}

/*
 * Prints the classification of the hand, based on the values of the external
 * variables straight, flush, four, three, and pairs.
 */
void print_result(int num_players, int num_cards, int num_ranks, int num_suits,
		  int hand[num_players][num_cards][RANK_SUIT],
		  int num_in_rank[num_players][num_ranks],
		  int num_in_suit[num_players][num_suits])
{
	/*
	 * (a) Black wins if the value of black_wins is 1.
	 * (b) Black ties with White if the value of black_wins is 0.
	 * (c) White wins if the value of black_wins is -1.
	 */
	int black_wins = 0;
	int rank_black, rank_white, highest_rank_black, highest_rank_white,
		card_black = 0, card_white = 0;
	int ranking[num_players];

	for (int player = 0; player < num_players; player++) {
		switch (player) {
		case 0:
			printf("Black: ");
			break;
		case 1:
			printf("White: ");
			break;
		}

		if (straight[player] && flush[player]) {
			ranking[player] = 8;
			printf("Straight flush");
		} else if (four[player]) {
			ranking[player] = 7;
			printf("Four of a kind");
		} else if (three[player] && pairs[player] == 1) {
			ranking[player] = 6;
			printf("Full house");
		} else if (flush[player]) {
			ranking[player] = 5;
			printf("Flush");
		} else if (straight[player]) {
			ranking[player] = 4;
			printf("Straight");
		} else if (three[player]) {
			ranking[player] = 3;
			printf("Three of a kind");
		} else if (pairs[player] == 2) {
			ranking[player] = 2;
			printf("Two pairs");
		} else if (pairs[player] == 1) {
			ranking[player] = 1;
			printf("Pair");
		} else {
			ranking[player] = 0;
			printf("High card");
		}

		putchar('\n');
	}

	if (ranking[BLACK] > ranking[WHITE]) {
		black_wins = 1;
	} else if (ranking[BLACK] < ranking[WHITE]) {
		black_wins = -1;
	} else {
		switch (ranking[BLACK]) {
		case 8:
		case 4:
			if (hand[BLACK][0][RANK] > hand[WHITE][0][RANK])
				black_wins = 1;
			else if (hand[BLACK][0][RANK] < hand[WHITE][0][RANK])
				black_wins = -1;

			break;
		case 5:
		case 0:
			for (int card = 0; card < NUM_CARDS; card++) {
				if (hand[BLACK][card][RANK] >
				    hand[WHITE][card][RANK]) {
					black_wins = 1;
					break;
				} else if (hand[BLACK][card][RANK] <
					   hand[WHITE][card][RANK]) {
					black_wins = -1;
					break;
				}
			}

			break;
		case 7:
			for (int rank = 0; rank < NUM_RANKS; rank++) {
				if (num_in_rank[BLACK][rank] == 4)
					rank_black = rank;

				if (num_in_rank[WHITE][rank] == 4)
					rank_white = rank;
			}

			if (rank_black > rank_white) {
				black_wins = 1;
			} else if (rank_black < rank_white) {
				black_wins = -1;
			} else {
				for (int rank = 0; rank < NUM_RANKS; rank++) {
					if (num_in_rank[BLACK][rank] == 1)
						rank_black = rank;

					if (num_in_rank[WHITE][rank] == 1)
						rank_white = rank;
				}

				if (rank_black > rank_white)
					black_wins = 1;
				else if (rank_black < rank_white)
					black_wins = -1;
			}

			break;
		case 6:
			for (int rank = 0; rank < NUM_RANKS; rank++) {
				if (num_in_rank[BLACK][rank] == 3)
					rank_black = rank;

				if (num_in_rank[WHITE][rank] == 3)
					rank_white = rank;
			}

			if (rank_black > rank_white) {
				black_wins = 1;
			} else if (rank_black < rank_white) {
				black_wins = -1;
			} else {
				for (int rank = 0; rank < NUM_RANKS; rank++) {
					if (num_in_rank[BLACK][rank] == 2)
						rank_black = rank;

					if (num_in_rank[WHITE][rank] == 2)
						rank_white = rank;
				}

				if (rank_black > rank_white)
					black_wins = 1;
				else if (rank_black < rank_white)
					black_wins = -1;
			}

			break;
		case 3:
			for (int rank = 0; rank < NUM_RANKS; rank++) {
				if (num_in_rank[BLACK][rank] == 3)
					rank_black = rank;

				if (num_in_rank[WHITE][rank] == 3)
					rank_white = rank;
			}

			if (rank_black > rank_white) {
				black_wins = 1;
			} else if (rank_black < rank_white) {
				black_wins = -1;
			} else {
				while (1) {
					if (hand[BLACK][card_black][RANK] ==
					    rank_black)
						card_black += 3;

					if (hand[WHITE][card_white][RANK] ==
					    rank_white)
						card_white += 3;

					if (card_black >= NUM_CARDS ||
					    card_white >= NUM_CARDS) {
						break;
					} else if (hand[BLACK][card_black][RANK]
						   > hand[WHITE][card_white]
						   [RANK]) {
						black_wins = 1;
						break;
					} else if (hand[BLACK][card_black][RANK]
						   < hand[WHITE][card_white]
						   [RANK]) {
						black_wins = -1;
						break;
					}

					card_black++;
					card_white++;
				}
			}

			break;
		case 2:
			for (int rank = NUM_RANKS - 1; rank >= 0; rank--) {
				if (num_in_rank[BLACK][rank] == 2) {
					rank_black = rank;
					highest_rank_black = rank;
					break;
				}
			}

			for (int rank = NUM_RANKS - 1; rank >= 0; rank--) {
				if (num_in_rank[WHITE][rank] == 2) {
					rank_white = rank;
					highest_rank_white = rank;
					break;
				}
			}

			if (rank_black > rank_white) {
				black_wins = 1;
			} else if (rank_black < rank_white) {
				black_wins = -1;
			} else {
				for (int rank = highest_rank_black - 1;
				     rank >= 0; rank--) {
					if (num_in_rank[BLACK][rank] == 2) {
						rank_black = rank;
					}
				}

				for (int rank = highest_rank_white - 1;
				     rank >= 0; rank--) {
					if (num_in_rank[WHITE][rank] == 2) {
						rank_white = rank;
					}
				}

				if (rank_black > rank_white) {
					black_wins = 1;
				} else if (rank_black < rank_white) {
					black_wins = -1;
				} else {
					for (int rank = 0; rank < NUM_RANKS;
					     rank++) {
						if (num_in_rank[BLACK][rank] ==
						    1)
							rank_black = rank;

						if (num_in_rank[WHITE][rank] ==
						    1)
							rank_white = rank;
					}

					if (rank_black > rank_white)
						black_wins = 1;
					else if (rank_black < rank_white)
						black_wins = -1;
				}
			}

			break;
		case 1:
			for (int rank = 0; rank < NUM_RANKS; rank++) {
				if (num_in_rank[BLACK][rank] == 2)
					rank_black = rank;

				if (num_in_rank[WHITE][rank] == 2)
					rank_white = rank;
			}

			if (rank_black > rank_white) {
				black_wins = 1;
			} else if (rank_black < rank_white) {
				black_wins = -1;
			} else {
				while (1) {
					if (hand[BLACK][card_black][RANK] ==
					    rank_black)
						card_black += 2;

					if (hand[WHITE][card_white][RANK] ==
					    rank_white)
						card_white += 2;

					if (card_black >= NUM_CARDS ||
					    card_white >= NUM_CARDS) {
						break;
					} else if (hand[BLACK][card_black][RANK]
						   > hand[WHITE][card_white]
						   [RANK]) {
						black_wins = 1;
						break;
					} else if (hand[BLACK][card_black][RANK]
						   < hand[WHITE][card_white]
						   [RANK]) {
						black_wins = -1;
						break;
					}

					card_black++;
					card_white++;
				}
			}

			break;
		}
	}

	switch (black_wins) {
	case 1:
		printf("Black wins.");
		break;
	case 0:
		printf("Tie.");
		break;
	case -1:
		printf("White wins.");
		break;
	}

	printf("\n\n");
}
