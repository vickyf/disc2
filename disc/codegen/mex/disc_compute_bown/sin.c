/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sin.c
 *
 * Code generation for function 'sin'
 *
 */

/* Include files */
#include "sin.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void b_sin(creal_T *x)
{
  real_T d;
  real_T d1;
  if (x->im == 0.0) {
    x->re = muDoubleScalarSin(x->re);
    x->im = 0.0;
  } else if (x->re == 0.0) {
    d = x->im;
    x->re = 0.0;
    x->im = muDoubleScalarSinh(d);
  } else {
    d = x->re;
    d1 = x->im;
    x->re = muDoubleScalarSin(x->re) * muDoubleScalarCosh(x->im);
    x->im = muDoubleScalarCos(d) * muDoubleScalarSinh(d1);
  }
}

/* End of code generation (sin.c) */
