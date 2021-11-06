/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * disc_compute_agreement.h
 *
 * Code generation for function 'disc_compute_agreement'
 *
 */

#pragma once

/* Include files */
#include "disc_compute_bown_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void disc_compute_agreement(const emlrtStack *sp, struct0_T *DiscOutput, real_T
  DiscParams_space_constant, const real_T DiscParams_bown_params[7], real_T
  DiscParams_Knear, real_T DiscParams_linearAngTh);

/* End of code generation (disc_compute_agreement.h) */
