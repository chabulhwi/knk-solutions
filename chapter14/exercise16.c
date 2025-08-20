#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

IDENT(foo)			// #pragma ident "foo"
int main(void)
{
	return 0;
}
