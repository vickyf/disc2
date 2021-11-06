/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

/* Include Files */
#include "repmat.h"
#include "disc_compute_bown_emxutil.h"
#include "disc_compute_bown_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double a[1192]
 *                double varargin_1
 *                emxArray_real_T *b
 * Return Type  : void
 */
void b_repmat(const double a[1192], double varargin_1, emxArray_real_T *b)
{
  int ibmat;
  int itilerow;
  int jcol;
  int ntilerows;
  ntilerows = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = 1192;
  emxEnsureCapacity_real_T(b, ntilerows);
  ntilerows = (int)varargin_1;
  for (jcol = 0; jcol < 1192; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b->data[ibmat + itilerow] = a[jcol];
    }
  }
}

/*
 * Arguments    : const double a_data[]
 *                const int a_size[2]
 *                double b_data[]
 *                int b_size[2]
 * Return Type  : void
 */
void c_repmat(const double a_data[], const int a_size[2], double b_data[], int
              b_size[2])
{
  int jcol;
  int ncols;
  b_size[0] = 1;
  b_size[1] = (short)(a_size[1] << 1);
  ncols = a_size[1];
  for (jcol = 0; jcol < ncols; jcol++) {
    b_data[jcol] = a_data[jcol];
    b_data[ncols + jcol] = a_data[jcol];
  }
}

/*
 * Arguments    : const double a[1192]
 *                double varargin_2
 *                emxArray_real_T *b
 * Return Type  : void
 */
void repmat(const double a[1192], double varargin_2, emxArray_real_T *b)
{
  int ibtile;
  int jtilecol;
  int k;
  int ntilecols;
  ntilecols = b->size[0] * b->size[1];
  b->size[0] = 1192;
  b->size[1] = (int)varargin_2;
  emxEnsureCapacity_real_T(b, ntilecols);
  ntilecols = (int)varargin_2;
  for (jtilecol = 0; jtilecol < ntilecols; jtilecol++) {
    ibtile = jtilecol * 1192;
    for (k = 0; k < 1192; k++) {
      b->data[ibtile + k] = a[k];
    }
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
