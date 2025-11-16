#include <stdio.h>

struct color {
	int red;
	int green;
	int blue;
};

struct color make_color(int red, int green, int blue);

struct color darker(struct color c);

int main(void)
{
	int red, green, blue;
	struct color c;

	printf("Enter the RGB values (R, G, B): ");
	scanf("%d, %d, %d", &red, &green, &blue);

	c = make_color(red, green, blue);
	printf("Original RGB values: %d, %d, %d\n", c.red, c.green, c.blue);
	c = darker(c);
	printf("Darker RGB values: %d, %d, %d\n", c.red, c.green, c.blue);

	return 0;
}

struct color make_color(int red, int green, int blue)
{
	if (red < 0)
		red = 0;
	else if (red > 255)
		red = 255;

	if (green < 0)
		green = 0;
	else if (green > 255)
		green = 255;

	if (blue < 0)
		blue = 0;
	else if (blue > 255)
		blue = 255;

	return (struct color) { red, green, blue };
}

struct color darker(struct color c)
{
	return (struct color) { c.red * 0.7, c.green * 0.7, c.blue * 0.7 };
}
