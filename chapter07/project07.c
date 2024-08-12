#include <stdio.h>

int main(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;
	char op;

	printf("Enter two fractions separated by either +, -, *, or /: ");
	scanf("%d / %d %c %d / %d", &num1, &denom1, &op, &num2, &denom2);

	switch (op) {
	case '+':
		result_num = num1 * denom2 + num2 * denom1;
		result_denom = denom1 * denom2;
		printf("The sum is %d/%d.\n", result_num, result_denom);
		break;
	case '-':
		result_num = num1 * denom2 - num2 * denom1;
		result_denom = denom1 * denom2;
		printf("The difference is %d/%d.\n", result_num, result_denom);
		break;
	case '*':
		result_num = num1 * num2;
		result_denom = denom1 * denom2;
		printf("The product is %d/%d.\n", result_num, result_denom);
		break;
	case '/':
		result_num = num1;
		result_denom = denom1 * num2 * denom2;
		printf("The result of division is %d/%d.\n", result_num,
		       result_denom);
		printf("Note that the operator / is left-associative.\n");
		break;
	default:
		printf("You didn't enter the correct operator.\n");
		break;
	}

	return 0;
}
