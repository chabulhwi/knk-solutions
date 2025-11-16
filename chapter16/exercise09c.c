#include <stdio.h>
#include <stdbool.h>

struct color {
	int red;
	int green;
	int blue;
};

struct color make_color(int red, int green, int blue);

bool equal_color(struct color color1, struct color color2);

int main(void)
{
	int red1, green1, blue1, red2, green2, blue2;
	struct color color1, color2;

	printf("Enter the RGB values for the first color (R, G, B): ");
	scanf("%d, %d, %d", &red1, &green1, &blue1);
	printf("Enter the RGB values for the second color (R, G, B): ");
	scanf("%d, %d, %d", &red2, &green2, &blue2);

	color1 = make_color(red1, green1, blue1);
	color2 = make_color(red2, green2, blue2);
	if (equal_color(color1, color2))
		printf("The two colors are the same.\n");
	else
		printf("The two colors are different.\n");

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

bool equal_color(struct color color1, struct color color2)
{
	if (color1.red == color2.red && color1.green == color2.green &&
	    color1.blue == color2.blue)
		return true;
	else
		return false;
}
