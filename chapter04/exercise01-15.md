# Exercises 1-15

## Exercise 1

\(a\) `1 2`\
\(b\) `0`\
\(c\) `1`\
\(d\) `0`

## Exercise 2

In C89, they may not have the same value. For example, `(-9)/7` may be `-2`, so
it may not be equal to `-(9/7)`, which is `-1`.

In C99, however, they have the same value since the standard makes the result of
division truncated toward zero.

## Exercise 3

\(a\) 1\
\(b\) -1 or -2\
\(c\) -1 or -2\
\(d\) 1 or 2

## Exercise 4

\(a\) 1\
\(b\) -1\
\(c\) -1\
\(d\) 1

## Exercise 5

\(a\) 3\
\(b\) -3 or 2\
\(c\) 3 or -2\
\(d\) -3 or 2

## Exercise 6

\(a\) 3\
\(b\) -3\
\(c\) 3\
\(d\) -3

## Exercise 7

Let `total` be an `int` variable representing the total. When `total` is a
multiple of 10, the value of `10 - (total % 10)` is 10, but the check digit is
0.

When `total` is 0, however, the value of `9 - ((total - 1) % 10)` also may be
10.

## Exercise 8

For the `upc.c` program to work correctly, we should replace `9 - ((total - 1) %
10)` with `(10 - (total % 10)) % 10`, since the former may give the wrong value
of the check digit when `total` is 0.

## Exercise 9

\(a\) `63 8`\
\(b\) `3 2 1`\
\(c\) `2 -1 3`\
\(d\) `0 0 0`

## Exercise 10

\(a\) `12 12`\
\(b\) `3 4`\
\(c\) `2 8`\
\(d\) `6 9`

## Exercise 11

\(a\) `0 2`\
\(b\) `4 11 6`\
\(c\) `0 8 7`\
\(d\) `3 4 5 4`

## Exercise 12

\(a\) `6 16`\
\(b\) `6 -7`\
\(c\) `6 23`\
\(d\) `6 15`

## Exercise 13

Assuming `i` is an `int` variable, both `++i` and `(i += 1)` have the
incremented value of `i`, whereas `i++` has the value of `i` before the
increment has happened.

## Exercise 14

\(a\) `((a * b) - (c * d)) + e`\
\(b\) `((a / b) % c) / d`\
\(c\) `(((- a) - b) + c) - (+ d)`\
\(d\) `((a * (- b)) / c) - d`

## Exercise 15

In the following answers, the first and second integers are the values of `i`
and `j`, respectively.

\(a\) 3, 2\
\(b\) 0, 2\
\(c\) 1, 2\
\(d\) 1, 3
