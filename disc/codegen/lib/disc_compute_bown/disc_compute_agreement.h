/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: disc_compute_agreement.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

#ifndef DISC_COMPUTE_AGREEMENT_H
#define DISC_COMPUTE_AGREEMENT_H

/* Include Files */
#include "disc_compute_bown_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void disc_compute_agreement(struct0_T *DiscOutput, double
    DiscParams_space_constant, const double DiscParams_bown_params[7], double
    DiscParams_Knear, double DiscParams_linearAngTh);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for disc_compute_agreement.h
 *
 * [EOF]
 */
