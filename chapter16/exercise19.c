#include <stdio.h>

#define MAX_LEN 40

struct pinball_machine {
	char name[MAX_LEN + 1];
	int year;
	enum { EM, SS } type;
	int players;
};

int main(void)
{
	struct pinball_machine bulhwi_pinball = {
		.name = "Bulhwi's pinball machine",
		.year = 2025,
		.type = SS,
		.players = 8,
	};

	printf("Name: %s\n", bulhwi_pinball.name);
	printf("Year: %d\n", bulhwi_pinball.year);
	printf("Type: ");
	switch (bulhwi_pinball.type) {
	case EM:
		printf("electromechanical");
		break;
	case SS:
		printf("solid state");
		break;
	}
	putchar('\n');
	printf("Maximum number of players: %d\n", bulhwi_pinball.players);

	return 0;
}
