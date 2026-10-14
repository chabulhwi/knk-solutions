/*
 * (a) char (*x[10])(int);
 */

typedef char Fcn(int);
typedef Fcn *Fcn_ptr;
typedef Fcn_ptr Fcn_ptr_array[10];
Fcn_ptr_array x;

extern char (*x[10])(int);
