#include <stdio.h>

int main(void)
{
	float error, current_term, sum;

	do {
		printf("Enter a small (floating-point) number: ");
		scanf("%f", &error);
	} while (error <= .0f);

	current_term = 1.0f;
	sum = 1.0f;

	for (int i = 1; current_term >= error; i++) {
		current_term /= i;
		sum += current_term;
	}

	printf("The partial sum where the last term is less than %f is %f\n",
	       error, sum);

	return 0;
}
