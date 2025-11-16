#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };

struct rectangle { struct point upper_left, lower_right; };

bool rectangle_valid(struct rectangle r);

bool rectangle_contains_point(struct rectangle r, struct point p);

int main(void)
{
	struct point p;
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
	printf("Enter the coordinates of a point: ");
	scanf("%d, %d", &p.x, &p.y);

	if (rectangle_contains_point(r, p))
		printf("The rectangle contains the point.\n");
	else
		printf("The rectangle doesn't contain the point.\n");

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

bool rectangle_contains_point(struct rectangle r, struct point p)
{
	if (r.upper_left.x < p.x && p.x < r.lower_right.x &&
	    r.lower_right.y < p.y && p.y < r.upper_left.y)
		return true;
	else
		return false;
}
