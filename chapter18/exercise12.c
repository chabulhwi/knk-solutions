/*
 * (a) f is a function with two arguments. The first one is a pointer to a
 *     function with a long integer argument that returns a float value, and the
 *     second one is a character pointer. The function f returns a pointer to a
 *     function with a double argument that returns an integer.
 */
int (*f(float (*)(long), char *))(double);

/* (b) Example: f(g, s) */
float (*g)(long);
char s[] = "Bulhwi";
double x;

int main(void)
{
	int (*h)(double) = f(g, s);
	int i = (*h)(x);

	return i;
}
