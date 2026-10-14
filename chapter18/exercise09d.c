/*
 * (d) void (*x(int, void (*y)(int)))(int);
 */

typedef void Fcn(int);
typedef Fcn *Fcn_ptr;
Fcn_ptr x(int, Fcn_ptr y);

extern void (*x(int, void (*y)(int)))(int);
