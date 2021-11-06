/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_disc_compute_bown_mex.c
 *
 * Code generation for function '_coder_disc_compute_bown_mex'
 *
 */

/* Include files */
#include "_coder_disc_compute_bown_mex.h"
#include "_coder_disc_compute_bown_api.h"
#include "disc_compute_bown_data.h"
#include "disc_compute_bown_initialize.h"
#include "disc_compute_bown_terminate.h"
#include "disc_compute_bown_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void disc_compute_bown_mexFunction(disc_compute_bownStackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        17, "disc_compute_bown");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "disc_compute_bown");
  }

  /* Call the function. */
  disc_compute_bown_api(SD, prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  disc_compute_bownStackData *c_disc_compute_bownStackDataGlo = NULL;
  c_disc_compute_bownStackDataGlo = (disc_compute_bownStackData *)emlrtMxCalloc
    (1, (size_t)1U * sizeof(disc_compute_bownStackData));
  mexAtExit(&disc_compute_bown_atexit);

  /* Module initialization. */
  disc_compute_bown_initialize();

  /* Dispatch the entry-point. */
  disc_compute_bown_mexFunction(c_disc_compute_bownStackDataGlo, nlhs, plhs,
    nrhs, prhs);

  /* Module termination. */
  disc_compute_bown_terminate();
  emlrtMxFree(c_disc_compute_bownStackDataGlo);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_disc_compute_bown_mex.c) */
