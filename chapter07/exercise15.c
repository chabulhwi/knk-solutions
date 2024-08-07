#include <stdio.h>

int main(void)
{
	printf("Type\t\tsizeof\n");
	printf("signed char\t%-6zu\n", sizeof(signed char));
	printf("short\t\t%-6zu\n", sizeof(short));
	printf("int\t\t%-6zu\n", sizeof(int));
	printf("long\t\t%-6zu\n", sizeof(long));
	printf("long long\t%-6zu\n", sizeof(long long));
	printf("float\t\t%-6zu\n", sizeof(float));
	printf("double\t\t%-6zu\n", sizeof(double));
	printf("long double\t%-6zu\n", sizeof(long double));

	/*
	 * Below is the output generated by the calls of printf on my computer:
	 *
	 * Type            sizeof
	 * signed char     1
	 * short           2
	 * int             4
	 * long            8
	 * long long       8
	 * float           4
	 * double          8
	 * long double     16
	 */

	typedef signed char Int8;
	typedef short Int16;
	typedef int Int32;

	return 0;
}
