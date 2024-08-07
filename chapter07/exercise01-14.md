# Chapter 7, Exercises 1-14

## Exercise 1

\(a\) 63 \
\(b\) 119 \
\(c\) 2748

## Exercise 2

\(a\) Floating-point \
\(b\) Floating-point \
\(c\) Illegal ('9' is an invalid digit in octal constants) \
\(d\) Illegal ('_' is invalid in integer constants) \
\(e\) Floating-point

## Exercise 3

\(b\)

## Exercise 4

\(d\)

## Exercise 5

Binary constants have not been a feature of the C standards until C23.
Therefore, (b) is also legal if you use C23.

## Exercise 6

\(a\) `char` \
\(b\) `short` \
\(c\) `short` \
\(d\) `long`

## Exercise 7

\(a\) `\10` \
\(b\) `\12` \
\(c\) `\15` \
\(d\) `\11`

## Exercise 8

\(a\) `\x08` \
\(b\) `\x0a` \
\(c\) `\x0d` \
\(d\) `\x09`

## Exercise 9

`int`

## Exercise 10

`unsigned int`. The compiler interprets `(int) j * k` as `((int) j) * k`.

## Exercise 11

`double`

## Exercise 12

* `i` is converted to `float`.
* `i + f` is converted to `double`.

## Exercise 13

`c` has the value 1.

\(a\) `-3`, `int` \
\(b\) `7`, `long` \
\(c\) `6.5`, `float` \
\(d\) `3.75`, `double` \
\(e\) `-1.0`, `double` \
\(f\) `6`, `int` \

## Exercise 14

No. The computed result will be incorrect if the value of `f` is too large or
too small for the `int` type to represent the integer part of `f`.
