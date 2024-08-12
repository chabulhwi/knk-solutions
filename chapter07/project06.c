#include <stdio.h>

int main(void)
{
	printf("Type\t\tsizeof\n");
	printf("int\t\t%-6zu\n", sizeof(int));
	printf("short\t\t%-6zu\n", sizeof(short));
	printf("long\t\t%-6zu\n", sizeof(long));
	printf("float\t\t%-6zu\n", sizeof(float));
	printf("double\t\t%-6zu\n", sizeof(double));
	printf("long double\t%-6zu\n", sizeof(long double));

	return 0;
}
