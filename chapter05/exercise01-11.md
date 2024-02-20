# Chapter 5, Exercises 1-11

## Exercise 1

\(a\) `1`\
\(b\) `1`\
\(c\) `1`\
\(d\) `0`

## Exercise 2

\(a\) `1`\
\(b\) `1`\
\(c\) `1`\
\(d\) `1`

## Exercise 3

\(a\) `1 3 4 5`\
\(b\) `0 7 8 9`\
\(c\) `1 8 8 9`\
\(d\) `1 2 1 1`

## Exercise 4

```c
(i > j) - (i < j)
```

## Exercise 5

Yes, but it always prints the string regardless of the value of `n`, including
when `n` is equal to 0.

## Exercise 6

Yes, but it prints the string only when `n` is equal to -9. It does nothing when
`n` is equal to 5.

## Exercise 7

If the value of `i` is either 17 or -17, it prints the following string:

```c
17
```

## Exercise 8

```c
teenager = 13 <= age && age <= 19 ? true : false;
```

## Exercise 9

They are equivalent.

## Exercise 10

```c
onetwo
```

## Exercise 11

```c
switch (area_code) {
case 229:
	printf("Albany\n");
	break;
case 404:
case 470:
case 678:
case 770:
	printf("Atlanta\n");
	break;
case 478:
	printf("Macon\n");
	break;
case 706:
case 762:
	printf("Columbus\n");
	break;
case 912:
	printf("Savannah\n");
	break;
default:
	printf("Area code not recognized\n");
	break;
}
```
