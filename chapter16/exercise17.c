enum { FALSE, TRUE } b;
int i;

int main(void)
{
	b = FALSE;		// (a)
	b = i;			// (b)
	b++;			// (c)
	i = b;			// (d)
	i = 2 * b + 1;		// (e)

	return 0;
}
