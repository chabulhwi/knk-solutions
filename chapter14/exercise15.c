/* Use of a '#elifdef' directive is a C23 extension. */
#include <stdio.h>

#define ENGLISH

int main(void)
{
#ifdef ENGLISH
	puts("Insert Disk 1");
#elifdef FRENCH
	puts("Inserez Le Disque 1");
#elifdef SPANISH
	puts("Inserte El Disco 1");
#endif
	return 0;
}
