#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define HEIGHT 3

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

const int segments[10][7] = {
	{1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1}
};

char digits[HEIGHT][MAX_DIGITS * 4];
int last_position = 0;

int main(void)
{
	char ch;
	int position = 0;

	clear_digits_array();

	printf("Enter a number: ");
	scanf(" ");

	for (; position < MAX_DIGITS;) {
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		else if (ch == '0')
			process_digit(0, position);
		else if (ch == '1')
			process_digit(1, position);
		else if (ch == '2')
			process_digit(2, position);
		else if (ch == '3')
			process_digit(3, position);
		else if (ch == '4')
			process_digit(4, position);
		else if (ch == '5')
			process_digit(5, position);
		else if (ch == '6')
			process_digit(6, position);
		else if (ch == '7')
			process_digit(7, position);
		else if (ch == '8')
			process_digit(8, position);
		else if (ch == '9')
			process_digit(9, position);

		if (isdigit(ch))
			position++;
	}

	last_position = position - 1;
	print_digits_array();

	return 0;
}

void clear_digits_array(void)
{
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < 4 * MAX_DIGITS; col++)
			digits[row][col] = ' ';
	}
}

void process_digit(int digit, int position)
{
	/* Row 0 */
	if (segments[digit][0] == 1)
		digits[0][4 * position + 1] = '_';

	/* Row 1 */
	if (segments[digit][5] == 1)
		digits[1][4 * position] = '|';

	if (segments[digit][6] == 1)
		digits[1][4 * position + 1] = '_';

	if (segments[digit][1] == 1)
		digits[1][4 * position + 2] = '|';

	/* Row 2 */
	if (segments[digit][4] == 1)
		digits[2][4 * position] = '|';

	if (segments[digit][3] == 1)
		digits[2][4 * position + 1] = '_';

	if (segments[digit][2] == 1)
		digits[2][4 * position + 2] = '|';
}

void print_digits_array(void)
{
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < 4 * last_position + 3; col++)
			printf("%c", digits[row][col]);

		putchar('\n');
	}
}
