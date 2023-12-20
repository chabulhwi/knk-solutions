#include <stdio.h>

int main(void) {
	float radius, volume;

	printf("Enter a radius in meters: ");
	scanf("%f", &radius);

	volume = (4.0f / 3.0f) * 3.14159f * radius * radius * radius;

	printf("The volume of a sphere with a radius of %.3f meters:\n",
	       radius);
	printf("%.3f cubic meters\n", volume);

	return 0;
}
