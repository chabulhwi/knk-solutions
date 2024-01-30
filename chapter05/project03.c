/* Calculates the commissions of a broker and their rival */

#include <stdio.h>

int main(void)
{
	/* share is also a float variable since its value can be fractional */
	float commission, rival_commission, value, share, price;

	printf("Enter the number of share: ");
	scanf("%f", &share);

	printf("Enter the price per share: ");
	scanf("%f", &price);

	value = share * price;

	if (value < 2500.00f)
		commission = 30.00f + .017f * value;
	else if (value < 6250.00f)
		commission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		commission = 76.00f + .0034f * value;
	else if (value < 50000.00f)
		commission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		commission = 155.00f + .0011f * value;
	else
		commission = 255.00f + .0009f * value;

	if (commission < 39.00f)
		commission = 39.00f;

	printf("The original broker's commission: $%.2f\n", commission);

	if (share < 2000)
		rival_commission = 33.00f + .03f * share;
	else
		rival_commission = 33.00f + .02f * share;

	printf("The rival's commission: $%.2f\n", rival_commission);

	return 0;
}
