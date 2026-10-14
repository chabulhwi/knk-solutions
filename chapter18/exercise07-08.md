# Chapter 18, Exercises 7-8

## Exercise 7

\(a\). `const` objects can't be used in constant expressions, and the values of
case labels in a switch statement must be constant expressions.

## Exercise 8

### (a)

The type of arrays of ten pointers to functions, each of which takes an
`int` argument and returns a `char` value.

### (b)

The type of functions, each of which takes an `int` argument and returns a
pointer to an array of five integers.

### (c)

The type of functions, each of which takes no arguments and returns a
pointer to a function that takes an `int` argument and returns a pointer to a
`float` value.

### (d)

The type of functions, each of which takes the following two arguments:

1. An `int` value.
2. A pointer to a function that takes an `int` argument and returns `void`.

Each function of type (d) returns a pointer to a function that takes an `int`
argument and returns `void`.
