/* Deals a random hand of cards */

#include <stdbool.h>		/* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
	bool in_hand[NUM_SUITS][NUM_RANKS] = { false };
	int num_cards, rank, suit;
	const char *rank_str[] = { "Two", "Three", "Four", "Five", "Six",
		"Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
		"Fourteen"
	};
	const char *suit_str[] = { "clubs", "diamonds", "hearts", "spades" };

	srand((unsigned)time(NULL));

	printf("Enter number of cards in hand: ");
	scanf("%d", &num_cards);

	printf("Your hand:\n");
	while (num_cards > 0) {
		suit = rand() % NUM_SUITS;	/* picks a random suit */
		rank = rand() % NUM_RANKS;	/* picks a random rank */
		if (!in_hand[suit][rank]) {
			in_hand[suit][rank] = true;
			num_cards--;
			printf("%s of %s\n", rank_str[rank], suit_str[suit]);
		}
	}
	printf("\n");

	return 0;
}
