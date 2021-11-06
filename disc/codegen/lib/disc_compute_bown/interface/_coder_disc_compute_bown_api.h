/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_disc_compute_bown_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

#ifndef _CODER_DISC_COMPUTE_BOWN_API_H
#define _CODER_DISC_COMPUTE_BOWN_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T NBind[1192];
  real_T NBpos_x[1192];
  real_T NBpos_y[1192];
  real_T NBang[1192];
  real_T NBdx[1192];
  real_T NBdy[1192];
  real_T NBcolor_norm[1192];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_rtString
#define typedef_rtString

typedef struct {
  char_T Value[13];
} rtString;

#endif                                 /*typedef_rtString*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  rtString stim_name;
  real_T num_nodes;
  real_T pos_x[1192];
  real_T pos_y[1192];
  real_T dx[1192];
  real_T dy[1192];
  real_T angle[1192];
  real_T bown[1192];
  real_T color_norm[1192];
  real_T color_contrast[1192];
  real_T bown_timecourse[2842920];
  real_T num_iter;
  real_T dist_decay[1420864];
  real_T distance[1420864];
  real_T agreement[8525184];
  real_T axes_range[4];
  struct1_T NB[801];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T initial_bown;
  real_T space_constant;
  real_T agreement_combo[3];
  real_T bown_params[7];
  real_T convergence_lambda;
  real_T max_iter;
  real_T Knear;
  real_T weightLCL;
  real_T weightGBL;
  real_T linearAngTh;
  real_T distLCL;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void disc_compute_bown(struct0_T *DiscOutput, struct2_T *DiscParams);
  void disc_compute_bown_api(const mxArray * const prhs[2], const mxArray *plhs
    [1]);
  void disc_compute_bown_atexit(void);
  void disc_compute_bown_initialize(void);
  void disc_compute_bown_terminate(void);
  void disc_compute_bown_xil_shutdown(void);
  void disc_compute_bown_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_disc_compute_bown_api.h
 *
 * [EOF]
 */
