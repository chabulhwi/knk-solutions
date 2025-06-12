#include <stdio.h>
#include <stdbool.h>

// --- Function Prototypes ---

// Parsing
int parse_value(char c);

// Custom sorting functions
void sort_cards_desc(int values[5], char suits[5]);
void sort_groups_by_count(int groups[][2], int count);

// Hand property checks
bool check_flush(const char suits[5]);
bool check_straight(const int values[5]);

// Core logic
void evaluate_hand(int values[5], char suits[5], int rank_info[6]);
void compare_and_print(const int black_rank_info[6],
		       const int white_rank_info[6]);

// --- Main Function ---

int main()
{
	char v_char, s_char;

	// Loop until scanf fails to read two characters (i.e., end of input)
	while (scanf(" %c%c", &v_char, &s_char) == 2) {
		int black_values[5];
		char black_suits[5];
		int white_values[5];
		char white_suits[5];

		// Parse the first card that was already read
		black_values[0] = parse_value(v_char);
		black_suits[0] = s_char;

		// Read the remaining 4 cards for Black
		for (int i = 1; i < 5; ++i) {
			scanf(" %c%c", &v_char, &s_char);
			black_values[i] = parse_value(v_char);
			black_suits[i] = s_char;
		}

		// Read the 5 cards for White
		for (int i = 0; i < 5; ++i) {
			scanf(" %c%c", &v_char, &s_char);
			white_values[i] = parse_value(v_char);
			white_suits[i] = s_char;
		}

		// rank_info[0] stores the rank (1-9), rank_info[1-5] store tie-breakers.
		int black_rank_info[6] = { 0 };
		int white_rank_info[6] = { 0 };

		evaluate_hand(black_values, black_suits, black_rank_info);
		evaluate_hand(white_values, white_suits, white_rank_info);

		compare_and_print(black_rank_info, white_rank_info);
	}

	return 0;
}

// --- Function Implementations ---

/**
 * @brief Converts a character representation of a card's value to an integer.
 */
int parse_value(char c)
{
	if (c >= '2' && c <= '9')
		return c - '0';
	if (c == 'T')
		return 10;
	if (c == 'J')
		return 11;
	if (c == 'Q')
		return 12;
	if (c == 'K')
		return 13;
	if (c == 'A')
		return 14;
	return 0;		// Should not happen with valid input
}

/**
 * @brief Sorts a hand of 5 cards in descending order of card value.
 */
void sort_cards_desc(int values[5], char suits[5])
{
	for (int i = 0; i < 4; i++) {
		int max_idx = i;
		for (int j = i + 1; j < 5; j++) {
			if (values[j] > values[max_idx]) {
				max_idx = j;
			}
		}
		if (max_idx != i) {
			int temp_val = values[i];
			values[i] = values[max_idx];
			values[max_idx] = temp_val;

			char temp_suit = suits[i];
			suits[i] = suits[max_idx];
			suits[max_idx] = temp_suit;
		}
	}
}

/**
 * @brief Sorts groups of cards by their count (descending). A group is [count, value].
 */
void sort_groups_by_count(int groups[][2], int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			// Sort by count (descending) only
			if (groups[j][0] < groups[j + 1][0]) {
				int temp_count = groups[j][0];
				int temp_value = groups[j][1];
				groups[j][0] = groups[j + 1][0];
				groups[j][1] = groups[j + 1][1];
				groups[j + 1][0] = temp_count;
				groups[j + 1][1] = temp_value;
			}
		}
	}
}

/**
 * @brief Checks if a hand is a flush.
 */
bool check_flush(const char suits[5])
{
	char first_suit = suits[0];
	for (int i = 1; i < 5; ++i) {
		if (suits[i] != first_suit)
			return false;
	}
	return true;
}

/**
 * @brief Checks if a hand is a straight. Assumes values are sorted descending.
 */
bool check_straight(const int values[5])
{
	for (int i = 0; i < 4; i++) {
		if (values[i] != values[i + 1] + 1) {
			return false;
		}
	}
	return true;
}

/**
 * @brief Evaluates a 5-card hand and fills rank_info with its rank
 *        and tie-breaking values.
 */
void evaluate_hand(int values[5], char suits[5], int rank_info[6])
{
	sort_cards_desc(values, suits);

	bool is_flush = check_flush(suits);
	bool is_straight = check_straight(values);

	int counts[15] = { 0 };	// Index 2-14 for card values 2-A
	for (int i = 0; i < 5; ++i) {
		counts[values[i]]++;
	}

	int groups[5][2];
	int group_count = 0;
	for (int v = 14; v >= 2; --v) {
		if (counts[v] > 0) {
			groups[group_count][0] = counts[v];	// count
			groups[group_count][1] = v;	// value
			group_count++;
		}
	}

	sort_groups_by_count(groups, group_count);

	if (is_straight && is_flush) {
		rank_info[0] = 9;	// Straight Flush
		rank_info[1] = values[0];
	} else if (groups[0][0] == 4) {
		rank_info[0] = 8;	// Four of a Kind
		rank_info[1] = groups[0][1];
		rank_info[2] = groups[1][1];
	} else if (groups[0][0] == 3 && groups[1][0] == 2) {
		rank_info[0] = 7;	// Full House
		rank_info[1] = groups[0][1];
		rank_info[2] = groups[1][1];
	} else if (is_flush) {
		rank_info[0] = 6;	// Flush
		for (int i = 0; i < 5; ++i)
			rank_info[i + 1] = values[i];
	} else if (is_straight) {
		rank_info[0] = 5;	// Straight
		rank_info[1] = values[0];
	} else if (groups[0][0] == 3) {
		rank_info[0] = 4;	// Three of a Kind
		rank_info[1] = groups[0][1];
		// Manually order the two kickers as their order in the groups array is not guaranteed
		int kicker1 = groups[1][1];
		int kicker2 = groups[2][1];
		rank_info[2] = (kicker1 > kicker2) ? kicker1 : kicker2;
		rank_info[3] = (kicker1 < kicker2) ? kicker1 : kicker2;
	} else if (groups[0][0] == 2 && groups[1][0] == 2) {
		rank_info[0] = 3;	// Two Pair
		// Manually order the two pair values
		int pair_val1 = groups[0][1];
		int pair_val2 = groups[1][1];
		rank_info[1] = (pair_val1 > pair_val2) ? pair_val1 : pair_val2;
		rank_info[2] = (pair_val1 < pair_val2) ? pair_val1 : pair_val2;
		rank_info[3] = groups[2][1];	// Kicker
	} else if (groups[0][0] == 2) {
		rank_info[0] = 2;	// One Pair
		rank_info[1] = groups[0][1];	// Pair value
		// Manually sort the three kickers
		int k[3] = { groups[1][1], groups[2][1], groups[3][1] };
		if (k[0] < k[1]) {
			int t = k[0];
			k[0] = k[1];
			k[1] = t;
		}
		if (k[1] < k[2]) {
			int t = k[1];
			k[1] = k[2];
			k[2] = t;
		}
		if (k[0] < k[1]) {
			int t = k[0];
			k[0] = k[1];
			k[1] = t;
		}
		rank_info[2] = k[0];
		rank_info[3] = k[1];
		rank_info[4] = k[2];
	} else {
		rank_info[0] = 1;	// High Card
		for (int i = 0; i < 5; ++i)
			rank_info[i + 1] = values[i];
	}
}

/**
 * @brief Compares two evaluated hands and prints the winner or "Tie."
 */
void compare_and_print(const int black_rank_info[6],
		       const int white_rank_info[6])
{
	// Compare main rank first (at index 0)
	if (black_rank_info[0] > white_rank_info[0]) {
		printf("Black wins.\n");
		return;
	}
	if (white_rank_info[0] > black_rank_info[0]) {
		printf("White wins.\n");
		return;
	}
	// Ranks are the same, so use tie-breaking values (at indices 1-5)
	for (int i = 1; i < 6; ++i) {
		if (black_rank_info[i] > white_rank_info[i]) {
			printf("Black wins.\n");
			return;
		}
		if (white_rank_info[i] > black_rank_info[i]) {
			printf("White wins.\n");
			return;
		}
	}

	// If we get through the whole loop, all values are equal.
	printf("Tie.\n");
}
