/*
 * (c) float *(*x(void))(int);
 */

typedef float *Fcn(int);
typedef Fcn *Fcn_ptr;
Fcn_ptr x(void);

extern float *(*x(void))(int);
