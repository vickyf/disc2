/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sin.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

/* Include Files */
#include "sin.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
void b_sin(creal_T *x)
{
  double d;
  double d1;
  if (x->im == 0.0) {
    x->re = sin(x->re);
    x->im = 0.0;
  } else if (x->re == 0.0) {
    d = x->im;
    x->re = 0.0;
    x->im = sinh(d);
  } else {
    d = x->re;
    d1 = x->im;
    x->re = sin(x->re) * cosh(x->im);
    x->im = cos(d) * sinh(d1);
  }
}

/*
 * File trailer for sin.c
 *
 * [EOF]
 */
