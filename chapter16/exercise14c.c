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

struct shape shape_scale(struct shape s, double factor);

int main(void)
{
	double c;
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

	printf("Enter the scale factor: ");
	scanf("%lf", &c);

	switch (s.shape_kind) {
	case RECTANGLE:
		printf("Original rectangle\n");
		printf("- Center: (%d, %d)\n", s.center.x, s.center.y);
		printf("- Height: %d\n", s.u.rectangle.height);
		printf("- Width: %d\n", s.u.rectangle.width);
		s = shape_scale(s, c);
		printf("Scaled rectangle\n");
		printf("- Center: (%d, %d)\n", s.center.x, s.center.y);
		printf("- Height: %d\n", s.u.rectangle.height);
		printf("- Width: %d\n", s.u.rectangle.width);
		break;
	case CIRCLE:
		printf("Original circle\n");
		printf("- Center: (%d, %d)\n", s.center.x, s.center.y);
		printf("- Radius: %d\n", s.u.circle.radius);
		s = shape_scale(s, c);
		printf("Scaled circle\n");
		printf("- Center: (%d, %d)\n", s.center.x, s.center.y);
		printf("- Radius: %d\n", s.u.circle.radius);
		break;
	}

	return 0;
}

struct shape shape_scale(struct shape s, double c)
{
	switch (s.shape_kind) {
	case RECTANGLE:
		s.u.rectangle.height *= c;
		s.u.rectangle.width *= c;
		break;
	case CIRCLE:
		s.u.circle.radius *= c;
		break;
	default:
		printf("Error: invalid tag field\n");
		exit(EXIT_FAILURE);
	}

	return s;
}
