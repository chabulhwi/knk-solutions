#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };

struct rectangle { struct point upper_left, lower_right; };

bool rectangle_valid(struct rectangle r);

struct point rectangle_center(struct rectangle r);

int main(void)
{
	struct point center;
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

	center = rectangle_center(r);
	printf("Center: (%d, %d)\n", center.x, center.y);

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

struct point rectangle_center(struct rectangle r)
{
	int x = (r.lower_right.x + r.upper_left.x) / 2;
	int y = (r.upper_left.y + r.lower_right.y) / 2;

	return (struct point) { x, y };
}
