# Chapter 6, Exercises 8-10

## Exercise 8

The output is `10 5 3 2 ` followed by the infinite sequence of `1 `s.

## Exercise 9

```c
i = 10;
while (i >= 1) {
	printf("%d ", i++);
	i /= 2;
}
```

## Exercise 10

1. Replace the `continue` statement with `goto loop_end;`.
1. Put a null statement on the line just before the end of the loop.
1. Place the label `loop_end` at the beginning of the null statement.
