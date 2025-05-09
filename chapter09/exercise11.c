#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

float compute_GPA(int n, char grades[n])
{
	int sum = 0;

	for (int i = 0; i < n; i++) {
		switch (toupper(grades[i])) {
		case 'A':
			sum += 4;
			break;
		case 'B':
			sum += 3;
			break;
		case 'C':
			sum += 2;
			break;
		case 'D':
			sum += 1;
			break;
		case 'F':
			break;
		}
	}

	return (float)sum / n;
}

int main(void)
{
	bool letter_correct;
	int n;

	do {
		printf("Enter the number of letter grades: ");
		scanf("%d", &n);
	} while (n <= 0);

	char grades[n];

	for (int i = 0; i < n; i++) {
		do {
			printf("Enter the letter for the grades[%d]: ", i);
			scanf(" %c", &grades[i]);

			switch (toupper(grades[i])) {
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'F':
				letter_correct = true;
				break;
			default:
				letter_correct = false;
				printf("There's a wrong letter in the array.\n");
			}
		} while (!letter_correct);
	}

	printf("GPA: %.2f\n", compute_GPA(n, grades));

	return 0;
}
