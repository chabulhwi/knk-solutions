# Chapter 6, Exercise 14

The call of `printf` is outside of the `if` statement, so it is performed
regardless of the value of the condition. Remove the semicolon after the
parenthesis in the `if` statement as follows:

```diff
-if (n % 2 == 0);
+if (n % 2 == 0)
	printf("n is even\n");
```
