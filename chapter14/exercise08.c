#include <stdio.h>

#define STRINGIZE(x) #x
#define STRINGIZE2(x) STRINGIZE(x)
#define LINE_FILE "Line " STRINGIZE2(__LINE__) " of file " __FILE__

int main(void)
{
	const char *str = LINE_FILE;
	puts(str);

	return 0;
}
