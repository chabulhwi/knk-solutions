/*
 * Here's the output:
 *
 * Answer: 3
 *
 * The program declares a local variable, n, initializing it as 0. Then, it
 * increments the value of n until the value of the function call, f2(n),
 * becomes zero. After the loop stops, it returns the value of n, which is 3, as
 * shown in the table below.
 *
 * n f2(n)
 * -------
 * 0   -12
 * 1   -10
 * 2    -6
 * 3     0
 */

#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
	printf("Answer: %d\n", f1(&f2));
	return 0;
}

int f1(int (*f)(int))
{
	int n = 0;

	while ((*f) (n))
		n++;
	return n;
}

int f2(int i)
{
	return i * i + i - 12;
}
