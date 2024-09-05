# Chapter 8, Exercises 1-2

## Exercise 1

The expression `sizeof(a) / sizeof(𝑡)` does not make it clear that `𝑡` is the
type of `a`'s elements; you have to search for the declaration of the array `a`
and check the type of its elements.

## Exercise 2

Let's say that we want the `digit_count` array to keep track of a count for each
digit. The array will need 10 elements, so we'd declare it in the following way:

```c
int digit_count[10];
```

However, we can't use digits in character form to subscript `digit_count`
directly, because their integer values don't fall between 0 and 9. To scale a
digit to the proper range, we can simply subtract `'0'`. For example, if `ch`
contains a digit in character form, we'd write

```c
digit_count[ch - '0'] = 0;
```

to clear the count that corresponds to `ch`. A minor caveat: this technique
isn't completely portable, because it assumes that digits have consecutive
codes. However, it works with most character sets, including ASCII.
