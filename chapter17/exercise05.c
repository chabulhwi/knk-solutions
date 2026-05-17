/* Only (b) and (c) are legal. */

int main(void)
{
	struct {
		union {
			char a, b;
			int c;
		} d;
		int e[5];
	} f, *p = &f;

	p->d.b = ' ';		// (a) is illegal
	p->e[3] = 10;		// (b) is legal
	(*p).d.a = '*';		// (c) is legal
	p->d.c = 20;		// (d) is illegal

	return 0;
}
