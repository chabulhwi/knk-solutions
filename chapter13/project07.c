#include <stdio.h>

int main(void)
{
	char *ten_to_nineteen[10] = { "ten", "eleven", "twelve", "thirteen",
		"fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
		"nineteen"
	};
	char *multiples_of_ten[8] = { "twenty", "thirty", "forty", "fifty",
		"sixty", "seventy", "eighty", "ninety"
	};
	char *one_to_nine[10] = { "one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine"
	};
	int n;

	printf("Enter a positive two-digit number: ");
	scanf("%d", &n);

	if (n < 10 || n >= 100) {
		printf("This number is invalid.\n");
	} else if (n < 20) {
		printf("You entered the number %s.\n", ten_to_nineteen[n - 10]);
	} else {
		printf("You entered the number %s",
		       multiples_of_ten[n / 10 - 2]);
		if (n % 10 != 0)
			printf("-%s", one_to_nine[n % 10 - 1]);
		printf(".\n");
	}

	return 0;
}
