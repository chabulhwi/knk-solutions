/*
 * (b) int (*x(int))[5];
 */

typedef int Arr[5];
typedef Arr *Arr_ptr;
Arr_ptr x(int);

extern int (*x(int))[5];
