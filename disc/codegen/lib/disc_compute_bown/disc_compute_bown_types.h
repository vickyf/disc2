/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: disc_compute_bown_types.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

#ifndef DISC_COMPUTE_BOWN_TYPES_H
#define DISC_COMPUTE_BOWN_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  double NBind[1192];
  double NBpos_x[1192];
  double NBpos_y[1192];
  double NBang[1192];
  double NBdx[1192];
  double NBdy[1192];
  double NBcolor_norm[1192];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  double initial_bown;
  double space_constant;
  double agreement_combo[3];
  double bown_params[7];
  double convergence_lambda;
  double max_iter;
  double Knear;
  double weightLCL;
  double weightGBL;
  double linearAngTh;
  double distLCL;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_rtString
#define typedef_rtString

typedef struct {
  char Value[13];
} rtString;

#endif                                 /*typedef_rtString*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  rtString stim_name;
  double num_nodes;
  double pos_x[1192];
  double pos_y[1192];
  double dx[1192];
  double dy[1192];
  double angle[1192];
  double bown[1192];
  double color_norm[1192];
  double color_contrast[1192];
  double bown_timecourse[2842920];
  double num_iter;
  double dist_decay[1420864];
  double distance[1420864];
  double agreement[8525184];
  double axes_range[4];
  struct1_T NB[801];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/
#endif

/*
 * File trailer for disc_compute_bown_types.h
 *
 * [EOF]
 */
