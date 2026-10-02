# Chapter 10, Exercises 1-3

## Exercise 1

### (a)

* Variables: `a`, `c`
* Parameter: `b`

### (b)

* Variables: `a`, `d`

### (c)

* Variables: `a`, `d`, `e`

### (d)

* Variables: `a`, `f`

## Exercise 2

### (a)

* `b` (the one declared in the body of the function `f`)
* `c` (one of the external variables)
* `d` (the one declared in the body of the function `f`)

### (b)

* `a` (the parameter of the function `g`)
* `b` (one of the external variables)
* `c` (the one declared in the body of the function `g`)

### (c)

* `a` (the one declared in the block)
* `b` (one of the external variables)
* `c` (the one declared in the body of the function `g`)
* `d` (the one declared in the block)

### (d)

* `b` (one of the external variables)
* `c` (the one declared in the body of the `main` function)
* `d` (the one declared in the body of the `main` function)

## Exercise 3

* There can be at most one external variable `i`.
* There can be at most one local variable `i` declared inside (a) the body of
  the `main` function or (b) a nested block within `main`.

Let `n` be the number of the local variables named `i`, which are declared
inside (a) the body of the `main` function or (b) a nested block within `main`.
Then, the program could contain at most `n + 1` different variables named `i`.

For example, the following C program contains one external variable and five
local variables, all of which are named `i`.

```c
int i;

int main(void)
{
	int i;
	{
		int i;
		{
			int i;
		}
	}

	{
		int i;
	}

	{
		int i;
	}

	return 0;
}
```

Since `n` is unbounded, there's no limit to the number of different variables
named `i` that the program could contain.
