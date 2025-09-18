# Chapter 15, Exercise 4

## (c)

In part (a), the `testdebug.c` file defined the `DEBUG` macro before including
the `debug.h` header file. On the other hand, in part (b), the `DEBUG` macro
isn't defined.

## (d)

Yes. The `debug.h` header file tests whether the `DEBUG` macro is defined, so
the `DEBUG` macro should be defined first.
