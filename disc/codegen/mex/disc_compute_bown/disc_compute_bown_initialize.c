/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * disc_compute_bown_initialize.c
 *
 * Code generation for function 'disc_compute_bown_initialize'
 *
 */

/* Include files */
#include "disc_compute_bown_initialize.h"
#include "_coder_disc_compute_bown_mex.h"
#include "disc_compute_bown_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void disc_compute_bown_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (disc_compute_bown_initialize.c) */
