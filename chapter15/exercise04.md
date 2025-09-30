# Chapter 15, Exercise 4

## (a)

```
Output if DEBUG is defined:
Value of i: 1
Value of j: 2
Value of k: 3
Value of i + j: 3
Value of 2 * i + j - k: 1
```

## (b)

```
Output if DEBUG is not defined:
```

## (c)

In part (a), the `testdebug.c` file defined the `DEBUG` macro before including
the `debug.h` header file. On the other hand, in part (b), the `DEBUG` macro
isn't defined.

## (d)

Yes. The `debug.h` header file tests whether the `DEBUG` macro is defined, so
the `DEBUG` macro should be defined first.
