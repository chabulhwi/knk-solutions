#include <stdio.h>

#define NUM_STUDENT 5
#define NUM_QUIZ 5

int main(void)
{
	double score[NUM_STUDENT][NUM_QUIZ] = { {0.0} };
	double student_total_score[NUM_STUDENT] = { 0.0 };
	double quiz_total_score[NUM_QUIZ] = { 0.0 };
	double quiz_max_score[NUM_QUIZ] = { 0.0 };
	double quiz_min_score[NUM_QUIZ] = { 0.0 };

	for (int i = 0; i < NUM_STUDENT; i++) {
		printf("Enter Student #%d's five quiz grades: ", i + 1);
		for (int j = 0; j < NUM_QUIZ; j++) {
			scanf("%lf", &score[i][j]);
			student_total_score[i] += score[i][j];
			quiz_total_score[j] += score[i][j];

			if (i == 0 || quiz_max_score[j] < score[i][j])
				quiz_max_score[j] = score[i][j];

			if (i == 0 || quiz_min_score[j] > score[i][j])
				quiz_min_score[j] = score[i][j];
		}
	}

	printf("\nStudent\tTotal\tAverage\n");
	for (int i = 0; i < NUM_STUDENT; i++) {
		printf("%d\t%.1f\t%.1f\t\n", i + 1, student_total_score[i],
		       student_total_score[i] / 5.0);
	}
	putchar('\n');

	printf("\nQuiz\tAverage\tHigh\tlow\n");
	for (int j = 0; j < NUM_QUIZ; j++) {
		printf("%d\t%.1f\t%.1f\t%.1f\n", j + 1,
		       quiz_total_score[j] / 5.0, quiz_max_score[j],
		       quiz_min_score[j]);
	}
	putchar('\n');

	return 0;
}
