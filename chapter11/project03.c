#include <stdio.h>
#include <stdlib.h>

void reduce(int numerator, int denominator, int *reduced_numerator,
	    int *reduced_denominator);

int main(void)
{
	int numerator, denominator, reduced_numerator, reduced_denominator;

	do {
		printf("Enter a fraction: ");
		scanf("%d / %d", &numerator, &denominator);
	} while (denominator == 0);

	reduce(numerator, denominator, &reduced_numerator,
	       &reduced_denominator);

	printf("In lowest terms: %d/%d\n", reduced_numerator,
	       reduced_denominator);

	return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator,
	    int *reduced_denominator)
{
	int fst, snd, r, gcd;

	fst = numerator;
	snd = denominator;
	while (snd != 0) {
		r = fst % snd;
		fst = snd;
		snd = r;
	}

	gcd = abs(fst);
	printf("GCD: %d\n", gcd);

	if (denominator < 0) {
		*reduced_numerator = numerator / -gcd;
		*reduced_denominator = denominator / -gcd;
	} else {
		*reduced_numerator = numerator / gcd;
		*reduced_denominator = denominator / gcd;
	}
}
