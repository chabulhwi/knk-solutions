#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 5

int main(void)
{
	int x, y;
	char dir_str[MAX_LEN + 1];
	enum { NORTH, SOUTH, EAST, WEST } direction;

	printf("Enter the value for the variable x: ");
	scanf("%d", &x);
	printf("Enter the value for the variable y: ");
	scanf("%d", &y);
	printf("Enter the direction: ");
	scanf("%s", dir_str);

	for (int i = 0; i < MAX_LEN; i++)
		dir_str[i] = toupper(dir_str[i]);

	if (strcmp(dir_str, "NORTH") == 0) {
		direction = NORTH;
	} else if (strcmp(dir_str, "SOUTH") == 0) {
		direction = SOUTH;
	} else if (strcmp(dir_str, "EAST") == 0) {
		direction = EAST;
	} else if (strcmp(dir_str, "WEST") == 0) {
		direction = WEST;
	} else {
		printf("Error: invalid direction\n");
		exit(EXIT_FAILURE);
	}

	printf("Original coordinates: (%d, %d)\n", x, y);

	switch (direction) {
	case NORTH:
		y--;
		break;
	case SOUTH:
		y++;
		break;
	case EAST:
		x++;
		break;
	case WEST:
		x--;
		break;
	default:
		printf("Error: invalid direction\n");
		exit(EXIT_FAILURE);
	}

	printf("Current coordinates: (%d, %d)\n", x, y);

	return 0;
}
