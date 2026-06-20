/* Compares two part structures */

#include "compare.h"

int compare_parts(const void *p, const void *q)
{
	if (((struct part *)p)->number < ((struct part *)q)->number)
		return -1;
	else if (((struct part *)p)->number == ((struct part *)q)->number)
		return 0;
	else
		return 1;

}
