#include <stdio.h>

int main(void)
{
	float radius = 10.0f, volume;

	volume = (4.0f / 3.0f) * 3.14159f * radius * radius * radius;

	printf("The volume of a sphere with a 10-meter radius:\n");
	printf("%.3f cubic meters\n", volume);

	return 0;
}
