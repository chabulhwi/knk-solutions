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

Let `n` be the number of the blocks that (a) are inside the `main` function and
(b) include a declaration of a local variable `i`.

Let `m` be the number of the declarations of an external variable `i`.

Then, the program could contain `m + n` different variables named `i`.

For example, the following C program contains three external variables and five
local variables, all of which are named `i`.

```c
int i;
int i;
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


