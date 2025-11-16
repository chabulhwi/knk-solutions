#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };

struct rectangle { struct point upper_left, lower_right; };

bool rectangle_valid(struct rectangle r);

int rectangle_area(struct rectangle r);

int main(void)
{
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
	printf("Area: %d\n", rectangle_area(r));

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

int rectangle_area(struct rectangle r)
{
	int width = r.lower_right.x - r.upper_left.x;
	int height = r.upper_left.y - r.lower_right.y;
	int area = width * height;

	if (area < 0)
		area *= -1;

	return area;
}
