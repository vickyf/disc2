/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

#ifndef REPMAT_H
#define REPMAT_H

/* Include Files */
#include "disc_compute_bown_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_repmat(const double a[1192], double varargin_1, emxArray_real_T *b);
  void c_repmat(const double a_data[], const int a_size[2], double b_data[], int
                b_size[2]);
  void repmat(const double a[1192], double varargin_2, emxArray_real_T *b);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for repmat.h
 *
 * [EOF]
 */
