/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50		/* maximum number of reminders */
#define MSG_LEN 60		/* max length of reminder message */
#define MONTH_DAY_STR_LEN 5	/* length of month_day_str */

int read_line(char str[], int n);

int main(void)
{
	char reminders[MAX_REMIND][MONTH_DAY_STR_LEN + MSG_LEN + 1];
	char month_day_str[MONTH_DAY_STR_LEN + 1], msg_str[MSG_LEN + 1];
	int month, day, i, j, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day in the form mm/dd and reminder: ");
		scanf("%2d", &month);
		if (month == 0)
			break;
		scanf(" / %2d", &day);

		if (month < 1 || month > 12) {
			printf("-- Invalid month --\n");

			// dispose of the previous characters
			while (getchar() != '\n')
				/* empty loop body */ ;
		} else if (day < 0 || day > 31) {
			printf("-- Invalid day --\n");

			// dispose of the previous characters
			while (getchar() != '\n')
				/* empty loop body */ ;
		} else {
			sprintf(month_day_str, "%2d/%2.2d", month, day);
			read_line(msg_str, MSG_LEN);

			for (i = 0; i < num_remind; i++) {
				if (strcmp(month_day_str, reminders[i]) < 0)
					break;
			}
			for (j = num_remind; j > i; j--)
				strcpy(reminders[j], reminders[j - 1]);

			strcpy(reminders[i], month_day_str);
			strcat(reminders[i], msg_str);

			num_remind++;
		}
	}

	printf("\n  Day Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf("%s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}
