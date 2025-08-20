# Chapter 14, Exercises 12-14

## Exercise 12

\(c\), (e)

## Exercise 13

### (a) Modified C program
```c
void f(void);

int main(void)
{
 f();



 return 0;
}

void f(void)
{



 printf("N is undefined\n");

}
```

### (b) Output of the program

```
N is undefined
```

## Exercise 14

### Modified C program

```c








int main(void)
{
 int a[= 10], i, j, k, m; // error: expected expression before ‘=’ token


 i = j;




 i = 10 * j+1;
 i = (x,y) x-y(j, k); // error: 'x' and 'y' undeclared
 i = ((((j)*(j)))*(((j)*(j))));
 i = (((j)*(j))*(j));
 i = jk; // error: 'jk' undeclared
 puts("i" "j"); // error: implicit declaration of function 'puts'


 i = SQR(j); // error: implicit declaration of function 'SQR'

 i = (j);

 return 0;
}
```
