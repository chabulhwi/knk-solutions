#include <stdio.h>

#define ERROR(fmtstr, ...) fprintf(stderr, fmtstr, __VA_ARGS__)

int main(void)
{
	int index = -1;

	ERROR("Range error: index = %d\n", index);
	ERROR("Error: %d + %d != %d\n", 1, 2, 0);

	return 0;
}
