/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * acos.c
 *
 * Code generation for function 'acos'
 *
 */

/* Include files */
#include "acos.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "mwmathutil.h"

/* Function Definitions */
void b_acos(creal_T *x)
{
  creal_T u;
  creal_T v;
  real_T absim;
  real_T absre;
  real_T b_absre;
  real_T ci;
  real_T sai;
  real_T sar;
  real_T sbi;
  real_T sbr;
  real_T t3;
  real_T t4;
  boolean_T xneg;
  if ((x->im == 0.0) && (!(muDoubleScalarAbs(x->re) > 1.0))) {
    x->re = muDoubleScalarAcos(x->re);
    x->im = 0.0;
  } else {
    v.re = x->re + 1.0;
    v.im = x->im;
    b_sqrt(&v);
    u.re = 1.0 - x->re;
    u.im = 0.0 - x->im;
    b_sqrt(&u);
    if ((-v.im == 0.0) && (u.im == 0.0)) {
      ci = 0.0;
    } else {
      t3 = v.re * u.im;
      t4 = -v.im * u.re;
      ci = t3 + t4;
      if ((muDoubleScalarIsInf(ci) || muDoubleScalarIsNaN(ci)) &&
          (!muDoubleScalarIsNaN(v.re)) && (!muDoubleScalarIsNaN(-v.im)) &&
          (!muDoubleScalarIsNaN(u.re)) && (!muDoubleScalarIsNaN(u.im))) {
        absre = muDoubleScalarAbs(v.re);
        absim = muDoubleScalarAbs(-v.im);
        if (absre > absim) {
          if (v.re < 0.0) {
            sar = -1.0;
          } else {
            sar = 1.0;
          }

          sai = -v.im / absre;
        } else if (absim > absre) {
          sar = v.re / absim;
          if (-v.im < 0.0) {
            sai = -1.0;
          } else {
            sai = 1.0;
          }

          absre = absim;
        } else {
          if (v.re < 0.0) {
            sar = -1.0;
          } else {
            sar = 1.0;
          }

          if (-v.im < 0.0) {
            sai = -1.0;
          } else {
            sai = 1.0;
          }
        }

        b_absre = muDoubleScalarAbs(u.re);
        absim = muDoubleScalarAbs(u.im);
        if (b_absre > absim) {
          if (u.re < 0.0) {
            sbr = -1.0;
          } else {
            sbr = 1.0;
          }

          sbi = u.im / b_absre;
        } else if (absim > b_absre) {
          sbr = u.re / absim;
          if (u.im < 0.0) {
            sbi = -1.0;
          } else {
            sbi = 1.0;
          }

          b_absre = absim;
        } else {
          if (u.re < 0.0) {
            sbr = -1.0;
          } else {
            sbr = 1.0;
          }

          if (u.im < 0.0) {
            sbi = -1.0;
          } else {
            sbi = 1.0;
          }
        }

        if ((!muDoubleScalarIsInf(absre)) && (!muDoubleScalarIsNaN(absre)) && ((
              !muDoubleScalarIsInf(b_absre)) && (!muDoubleScalarIsNaN(b_absre))))
        {
          xneg = true;
        } else {
          xneg = false;
        }

        if (muDoubleScalarIsNaN(ci) || (muDoubleScalarIsInf(ci) && xneg)) {
          ci = sar * sbi + sai * sbr;
          if (ci != 0.0) {
            ci = ci * absre * b_absre;
          } else {
            if ((muDoubleScalarIsInf(absre) && ((u.re == 0.0) || (u.im == 0.0)))
                || (muDoubleScalarIsInf(b_absre) && ((v.re == 0.0) || (-v.im ==
                   0.0)))) {
              if (muDoubleScalarIsNaN(t3)) {
                t3 = 0.0;
              }

              if (muDoubleScalarIsNaN(t4)) {
                t4 = 0.0;
              }

              ci = t3 + t4;
            }
          }
        }
      }
    }

    xneg = (ci < 0.0);
    if (xneg) {
      ci = -ci;
    }

    if (ci >= 2.68435456E+8) {
      ci = muDoubleScalarLog(ci) + 0.69314718055994529;
    } else if (ci > 2.0) {
      ci = muDoubleScalarLog(2.0 * ci + 1.0 / (muDoubleScalarSqrt(ci * ci + 1.0)
        + ci));
    } else {
      absre = ci * ci;
      ci += absre / (muDoubleScalarSqrt(absre + 1.0) + 1.0);
      absre = muDoubleScalarAbs(ci);
      if ((absre > 4.503599627370496E+15) || (muDoubleScalarIsInf(ci) ||
           muDoubleScalarIsNaN(ci))) {
        ci++;
        ci = muDoubleScalarLog(ci);
      } else {
        if (!(absre < 2.2204460492503131E-16)) {
          ci = muDoubleScalarLog(ci + 1.0) * (ci / ((ci + 1.0) - 1.0));
        }
      }
    }

    if (xneg) {
      ci = -ci;
    }

    x->re = 2.0 * muDoubleScalarAtan2(u.re, v.re);
    x->im = ci;
  }
}

/* End of code generation (acos.c) */
