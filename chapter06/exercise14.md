# Chapter 6, Exercise 14

The call of `printf` is performed regardless of the value of the condition since
it is outside of the `if` statement. Remove the semicolon right after the
parenthesis in the `if` statement as follows:

```diff
-if (n % 2 == 0);
+if (n % 2 == 0)
	printf("n is even\n");
```
