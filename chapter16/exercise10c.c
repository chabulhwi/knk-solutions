#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };

struct rectangle { struct point upper_left, lower_right; };

bool rectangle_valid(struct rectangle r);

struct rectangle rectangle_move(struct rectangle r, int x, int y);

int main(void)
{
	int x, y;
	struct rectangle r;

	while (1) {
		printf("Enter the coordinates of the upper left corner of the rectangle: ");
		scanf("%d, %d", &r.upper_left.x, &r.upper_left.y);
		printf("Enter the coordinates of the lower right corner of the rectangle: ");
		scanf("%d, %d", &r.lower_right.x, &r.lower_right.y);

		if (rectangle_valid(r))
			break;
		else
			printf("Some coordinates are invalid.\n\n");
	}
	printf("How much do you want to move it in the x direction? ");
	scanf("%d", &x);
	printf("How much do you want to move it in the y direction? ");
	scanf("%d", &y);

	printf("Original rectangle\n");
	printf("- Upper left: (%d, %d)\n", r.upper_left.x, r.upper_left.y);
	printf("- Lower right: (%d, %d)\n", r.lower_right.x, r.lower_right.y);

	r = rectangle_move(r, x, y);
	printf("Moved rectangle\n");
	printf("- Upper left: (%d, %d)\n", r.upper_left.x, r.upper_left.y);
	printf("- Lower right: (%d, %d)\n", r.lower_right.x, r.lower_right.y);

	return 0;
}

bool rectangle_valid(struct rectangle r)
{
	if (r.upper_left.x < r.lower_right.x &&
	    r.lower_right.y < r.upper_left.y)
		return true;
	else
		return false;
}

struct rectangle rectangle_move(struct rectangle r, int x, int y)
{
	return (struct rectangle) {
		.upper_left = { r.upper_left.x + x, r.upper_left.y + y },
		.lower_right = { r.lower_right.x + x, r.lower_right.y + y },
	};
}
