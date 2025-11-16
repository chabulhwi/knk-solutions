#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 9
#define RECTANGLE 4
#define CIRCLE 0

struct point {
	int x;
	int y;
};

struct shape {
	int shape_kind;		/* RECTANGLE or CIRCLE */
	struct point center;	/* coordinates of center */
	union {
		struct {
			int height, width;
		} rectangle;
		struct {
			int radius;
		} circle;
	} u;
} s;

struct shape shape_move(struct shape s, int x, int y);

int main(void)
{
	int x, y;
	char shape_kind_str[MAX_LEN + 1];
	struct shape s;

	printf("Enter the coordinates of the center of the shape: ");
	scanf("%d, %d", &s.center.x, &s.center.y);

	printf("Enter the kind of the shape: ");
	scanf("%s", shape_kind_str);

	for (int i = 0; i < MAX_LEN; i++)
		shape_kind_str[i] = toupper(shape_kind_str[i]);

	if (strcmp(shape_kind_str, "RECTANGLE") == 0) {
		s.shape_kind = RECTANGLE;
		printf("Enter the height and width of the rectangle (height x width): ");
		scanf("%d x %d", &s.u.rectangle.height, &s.u.rectangle.width);
	} else if (strcmp(shape_kind_str, "CIRCLE") == 0) {
		s.shape_kind = CIRCLE;
		printf("Enter the radius of the circle: ");
		scanf("%d", &s.u.circle.radius);
	} else {
		printf("Error: invalid tag field\n");
		exit(EXIT_FAILURE);
	}

	printf("How much do you want to move it in the x direction? ");
	scanf("%d", &x);
	printf("How much do you want to move it in the y direction? ");
	scanf("%d", &y);

	printf("Original center: (%d, %d)\n", s.center.x, s.center.y);
	s = shape_move(s, x, y);
	printf("Moved center: (%d, %d)\n", s.center.x, s.center.y);

	return 0;
}

struct shape shape_move(struct shape s, int x, int y)
{
	s.center.x += x;
	s.center.y += y;

	return s;
}
