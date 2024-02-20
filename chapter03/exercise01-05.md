# Chapter 3, Exercises 1-5

## Exercise 1

\(a\) `    86,1040`\
\(b\) ` 3.02530e+01`\
\(c\) `83.1620`\
\(d\) `1e-06 `

## Exercise 2

\(a\) `printf("%-8.1e", x);`\
\(b\) `printf("%10.6e", x);`\
\(c\) `printf("%-8.3f", x);`\
\(d\) `printf("%6.0f", x);`

## Exercise 3

### (a)

Equivalent.

### (b)

Not equivalent.

Suppose the input is ` 10 -20-30`. `scanf` will match only the first `%d` in the
former format string with an integer from the input. On the other hand, `scanf`
will match each `%d` in the latter format string with an integer from the input.

### (c)

Not equivalent.

Unlike the former, the latter can cause an interactive program to hang until the
user enters a non-blank character.

### (d)

Equivalent.

## Exercise 4

* `i`: 10
* `x`: 0.3
* `j`: 5

## Exercise 5

* `x`: 12.3
* `i`: 45
* `y`: 0.6
