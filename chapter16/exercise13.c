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

int main(void)
{
	s.shape_kind = RECTANGLE;	// (a)
	s.center.x = 10;	// (b)
	s.u.rectangle.height = 25;	// (c)
	s.u.rectangle.width = 8;	// (d)
	s.u.circle.radius = 5;	// (e)
	s.u.circle.radius = 5;	// (f)

	return 0;
}
