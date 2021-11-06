/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * disc_compute_bown_types.h
 *
 * Code generation for function 'disc_compute_bown'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

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

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_disc_compute_bownStackData
#define typedef_disc_compute_bownStackData

typedef struct {
  union
  {
    struct {
      struct1_T u[801];
    } f0;

    struct {
      real_T agreement_LCL[1420864];
      real_T agreement_GBL[1420864];
    } f1;
  } u1;

  struct {
    struct0_T DiscOutput;
  } f2;
} disc_compute_bownStackData;

#endif                                 /*typedef_disc_compute_bownStackData*/

/* End of code generation (disc_compute_bown_types.h) */
