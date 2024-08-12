#include <stdio.h>

int main(void)
{
	float num, val;
	char op;

	printf("Enter an expression: ");
	scanf("%f", &num);
	val = num;

	op = getchar();
	while (op == '+' || op == '-' || op == '*' || op == '/' || op == ' ') {
		if (op != ' ') {
			scanf("%f", &num);
			switch (op) {
			case '+':
				val += num;
				break;
			case '-':
				val -= num;
				break;
			case '*':
				val *= num;
				break;
			case '/':
				val /= num;
				break;
			}
		}

		op = getchar();
	}

	if (op == '\n')
		printf("Value of expression: %f\n", val);
	else
		printf("There's an incorrect operator in the expression.\n");

	return 0;
}
