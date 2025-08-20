/*
 * (a) The preprocessor's expansion of GENERIC_MAX(long) is as follows:
 *
 * long long_max(long x, long y)
 * {
 *     return x > y ? x : y;
 * }
 *
 * (b) The names of some basic types include one or more whitespace characters.
 *     So, type##_max may be replaced with an invalid function name that
 *     contains whitespace characters.
 * (c) Use typedef to make an alias for a basic type like unsigned long.
 */
#include <stdio.h>

#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}

GENERIC_MAX(long)
typedef unsigned long ULONG;
GENERIC_MAX(ULONG)
// linter keeps deleting this line
int main(void)
{
	printf("long_max(3L, -4L) = %ld\n", long_max(3L, -4L));	// 3
	printf("ULONG_max(3LU, 4LU) = %lu\n", ULONG_max(3LU, 4LU));	// 4

	return 0;
}
