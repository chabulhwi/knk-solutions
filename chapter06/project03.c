#include <stdio.h>

int main(void)
{
	int num, denom, fst, snd, r, gcd;

	do {
		printf("Enter a fraction: ");
		scanf("%d / %d", &num, &denom);
	} while (denom == 0);

	fst = num;
	snd = denom;
	while (snd != 0) {
		r = fst % snd;
		fst = snd;
		snd = r;
	}

	if (fst < 0)
		gcd = -fst;
	else
		gcd = fst;

	printf("GCD: %d\n", gcd);

	printf("In lowest terms: ");
	if (denom < 0)
		printf("%d/%d\n", num / -gcd, denom / -gcd);
	else
		printf("%d/%d\n", num / gcd, denom / gcd);

	return 0;
}
