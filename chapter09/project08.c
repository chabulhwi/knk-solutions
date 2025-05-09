#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
	int wins = 0, losses = 0;
	char response;

	srand((unsigned)time(NULL));

	do {
		if (play_game()) {
			wins++;
			printf("You win!\n");
		} else {
			losses++;
			printf("You lose!\n");
		}

		printf("\nPlay again? ");
		scanf(" %c", &response);

		putchar('\n');
	} while (toupper(response) == 'Y');

	printf("Wins: %d  Losses: %d\n", wins, losses);

	return 0;
}

int roll_dice(void)
{
	int dice1, dice2;

	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;

	return dice1 + dice2;
}

bool play_game(void)
{
	int sum, point;

	sum = roll_dice();

	printf("You rolled: %d\n", sum);

	switch (sum) {
	case 7:
	case 11:
		return true;
	case 2:
	case 3:
	case 12:
		return false;
	default:
		point = sum;
		printf("Your point is %d\n", point);

		while (1) {
			sum = roll_dice();
			printf("You rolled: %d\n", sum);

			if (sum == point)
				return true;
			else if (sum == 7)
				return false;
		}
	}
}
