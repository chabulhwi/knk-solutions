#include <stdio.h>
#include <stdlib.h>

struct point {
	int x, y;
};
struct rectangle {
	struct point upper_left, lower_right;
} *p;

int main(void)
{
	p = malloc(sizeof(struct rectangle));

	if (p == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	p->upper_left = (struct point) { 10, 25 };
	p->lower_right = (struct point) { 20, 15 };

	printf("- Upper left:  (%d, %d)\n", p->upper_left.x, p->upper_left.y);
	printf("- Lower right: (%d, %d)\n", p->lower_right.x, p->lower_right.y);
	free(p);

	return 0;
}
