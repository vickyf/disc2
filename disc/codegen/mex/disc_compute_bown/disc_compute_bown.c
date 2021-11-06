/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * disc_compute_bown.c
 *
 * Code generation for function 'disc_compute_bown'
 *
 */

/* Include files */
#include "disc_compute_bown.h"
#include "disc_compute_agreement.h"
#include "disc_compute_bown_data.h"
#include "disc_compute_bown_mexutil.h"
#include "disc_compute_bown_types.h"
#include "mtimes.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 62,    /* lineNo */
  "disc_compute_bown",                 /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 63,  /* lineNo */
  "disc_compute_bown",                 /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 79,  /* lineNo */
  "disc_compute_bown",                 /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 89,  /* lineNo */
  "disc_compute_bown",                 /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 95,  /* lineNo */
  "disc_compute_bown",                 /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 97,  /* lineNo */
  "disc_compute_bown",                 /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 110, /* lineNo */
  "disc_compute_bown",                 /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 122, /* lineNo */
  "disc_compute_bown",                 /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 42,  /* lineNo */
  "string/disp",                       /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\string.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 38,  /* lineNo */
  "fprintf",                           /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 79, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 64,    /* lineNo */
  18,                                  /* colNo */
  "fprintf",                           /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 91,/* lineNo */
  12,                                  /* colNo */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pName */
};

static emlrtDCInfo b_emlrtDCI = { 108, /* lineNo */
  28,                                  /* colNo */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  1192,                                /* iLast */
  108,                                 /* lineNo */
  28,                                  /* colNo */
  "current_bown",                      /* aName */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 109, /* lineNo */
  22,                                  /* colNo */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  109,                                 /* lineNo */
  22,                                  /* colNo */
  "current_bown",                      /* aName */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 109, /* lineNo */
  47,                                  /* colNo */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  109,                                 /* lineNo */
  47,                                  /* colNo */
  "current_bown",                      /* aName */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  108,                                 /* lineNo */
  13,                                  /* colNo */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"/* pName */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  2385,                                /* iLast */
  113,                                 /* lineNo */
  32,                                  /* colNo */
  "DiscOutput.bown_timecourse",        /* aName */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  2385,                                /* iLast */
  116,                                 /* lineNo */
  56,                                  /* colNo */
  "DiscOutput.bown_timecourse",        /* aName */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  6,                                   /* iLast */
  75,                                  /* lineNo */
  35,                                  /* colNo */
  "DiscOutput.agreement",              /* aName */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 75,  /* lineNo */
  35,                                  /* colNo */
  "disc_compute_bown",                 /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRSInfo gb_emlrtRSI = { 64, /* lineNo */
  "fprintf",                           /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

/* Function Declarations */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_feval_, const char_T *identifier);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);

/* Function Definitions */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_feval_, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_feval_), &thisId);
  emlrtDestroyArray(&a__output_of_feval_);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m, 4, pArrays, "feval", true, location);
}

void disc_compute_bown(disc_compute_bownStackData *SD, const emlrtStack *sp,
  struct0_T *DiscOutput, const struct2_T *DiscParams)
{
  static const int32_T b_iv[2] = { 1, 7 };

  static const int32_T iv1[2] = { 1, 4 };

  static const int32_T iv10[2] = { 1, 4 };

  static const int32_T iv11[2] = { 1, 21 };

  static const int32_T iv2[2] = { 1, 77 };

  static const int32_T iv3[2] = { 1, 7 };

  static const int32_T iv4[2] = { 1, 4 };

  static const int32_T iv5[2] = { 1, 7 };

  static const int32_T iv6[2] = { 1, 7 };

  static const int32_T iv7[2] = { 1, 4 };

  static const int32_T iv8[2] = { 1, 39 };

  static const int32_T iv9[2] = { 1, 7 };

  static const char_T varargin_1[77] = { '>', '>', ' ', 'S', 'T', 'E', 'P', ' ',
    '1', ':', ' ', 'C', 'o', 'm', 'p', 'u', 't', 'i', 'n', 'g', ' ', 'A', 'g',
    'r', 'e', 'e', 'm', 'e', 'n', 't', '/', 'C', 'o', 'r', 'r', 'e', 's', 'p',
    'o', 'n', 'd', 'e', 'n', 'c', 'e', ' ', 'm', 'a', 't', 'r', 'i', 'x', ' ',
    'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', 'B', 'O', 'W', 'N', ' ', 's', 'i',
    'g', 'n', 'a', 'l', 's', ' ', '.', '.', '.' };

  static const char_T c_varargin_1[39] = { '>', '>', ' ', 'S', 'T', 'E', 'P',
    ' ', '2', ':', ' ', 'P', 'r', 'o', 'p', 'a', 'g', 'a', 't', 'i', 'n', 'g',
    ' ', 'B', 'O', 'W', 'N', ' ', 's', 'i', 'g', 'n', 'a', 'l', 's', ' ', '.',
    '.', '.' };

  static const char_T d_varargin_1[21] = { '>', '>', ' ', 'C', 'O', 'N', 'V',
    'E', 'R', 'G', 'E', 'D', ' ', 'A', 'N', 'D', ' ', 'D', 'O', 'N', 'E' };

  static const char_T b_varargin_1[7] = { '>', '>', ' ', 'D', 'O', 'N', 'E' };

  static const char_T c_u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  static const char_T e_u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  static const char_T g_u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  static const char_T u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  static const char_T b_u[4] = { '%', 's', '\\', 'n' };

  static const char_T d_u[4] = { '%', 's', '\\', 'n' };

  static const char_T f_u[4] = { '%', 's', '\\', 'n' };

  static const char_T h_u[4] = { '%', 's', '\\', 'n' };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *y;
  real_T y_data[2384];
  real_T transition_vectorGBL[1192];
  real_T transition_vectorLCL[1192];
  real_T b_DiscOutput;
  real_T nrep;
  int32_T DiscOutput_size[2];
  int32_T iv12[2];
  int32_T y_size[2];
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T xoffset;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;

  /*  DISC_COMPUTE_BOWN - core of the DISC model */
  /*  */
  /*  Synopsis */
  /*    [ DiscOutput ] = disc_compute_bown(DiscOutput,DiscParams) */
  /*  */
  /*  Description */
  /*    First this code will compute correspondencies between different BOWN */
  /*    nodes to decide if they will interact with eachother or not. Then based */
  /*    on this correspondence/agreement matrix it will start propagating BOWN */
  /*    signals throughout the image until convergence is reached. */
  /*  */
  /*  Inputs ([]s are optional) */
  /*    (struct) DiscOutput */
  /*    (struct) DiscParams */
  /*  */
  /*  Outputs ([]s are optional) */
  /*    (struct) DiscOutput */
  /*  */
  /*  Examples */
  /*    <Example Code> */
  /*  */
  /*  See also */
  /*    disc_main */
  /*  */
  /*  Requirements */
  /*    -- */
  /*  */
  /*  Authors */
  /*    Vicky Froyen <vicky.froyen@gmail.com> */
  /*    Naoki Kogo <naoki.kogo@gmail.com> */
  /*  */
  /*  License */
  /*    DISC2 is free software accompanying our paper: */
  /*    "Emergence of border-ownership by large-scale consistency and  */
  /*    long-range interactions: Neuro-computational model to reflect */
  /*    global configurations" */
  /*    Copyright (C) 2020 Vicky Froyen, Naoki Kogo */
  /*  */
  /*    This program is free software; you can redistribute it and/or modify */
  /*    it under the terms of the GNU General Public License as published by */
  /*    the Free Software Foundation; either version 2 of the License, or */
  /*    (at your option) any later version. */
  /*  */
  /*    This program is distributed in the hope that it will be useful, */
  /*    but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*    GNU General Public License for more details. */
  /*  */
  /*    You should have received a copy of the GNU General Public License along */
  /*    with this program; if not, write to the Free Software Foundation, Inc., */
  /*    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */
  /*  */
  /*  Changes */
  /*    see <git log> */
  /* \codegen */
  /*  compute if bown nodes are in agreement */
  st.site = &emlrtRSI;
  b_st.site = &i_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a(&c_st, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(&c_st, 4, m, &b_u[0]);
  emlrtAssign(&c_y, m);
  d_y = NULL;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a(&c_st, 77, m, &varargin_1[0]);
  emlrtAssign(&d_y, m);
  d_st.site = &gb_emlrtRSI;
  emlrt_marshallIn(&d_st, feval(&d_st, y, b_y, c_y, d_y, &emlrtMCI),
                   "<output of feval>");
  st.site = &b_emlrtRSI;
  disc_compute_agreement(&st, DiscOutput, DiscParams->space_constant,
    DiscParams->bown_params, DiscParams->Knear, DiscParams->linearAngTh);

  /* %%local */
  /* agreement: less than distLCL, distance decay, owner side color consistency, colinearity */
  for (i = 0; i < 1192; i++) {
    for (k = 0; k < 1192; k++) {
      xoffset = k + 1192 * i;
      SD->u1.f1.agreement_LCL[xoffset] = (real_T)(DiscOutput->distance[xoffset] <=
        DiscParams->distLCL) * DiscOutput->dist_decay[xoffset] *
        DiscOutput->agreement[xoffset + 1420864] * DiscOutput->agreement[xoffset
        + 5683456];
    }
  }

  /* %%global */
  /*  combine different agreement features as set by the user in */
  /*  DiscParams.agreement_combo with the distance decay matrix. */
  if (DiscParams->agreement_combo[0] != (int32_T)muDoubleScalarFloor
      (DiscParams->agreement_combo[0])) {
    emlrtIntegerCheckR2012b(DiscParams->agreement_combo[0], &e_emlrtDCI, sp);
  }

  if (((int32_T)DiscParams->agreement_combo[0] < 1) || ((int32_T)
       DiscParams->agreement_combo[0] > 6)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)DiscParams->agreement_combo[0], 1, 6,
      &f_emlrtBCI, sp);
  }

  if (DiscParams->agreement_combo[1] != (int32_T)muDoubleScalarFloor
      (DiscParams->agreement_combo[1])) {
    emlrtIntegerCheckR2012b(DiscParams->agreement_combo[1], &e_emlrtDCI, sp);
  }

  if (((int32_T)DiscParams->agreement_combo[1] < 1) || ((int32_T)
       DiscParams->agreement_combo[1] > 6)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)DiscParams->agreement_combo[1], 1, 6,
      &f_emlrtBCI, sp);
  }

  if (DiscParams->agreement_combo[2] != (int32_T)muDoubleScalarFloor
      (DiscParams->agreement_combo[2])) {
    emlrtIntegerCheckR2012b(DiscParams->agreement_combo[2], &e_emlrtDCI, sp);
  }

  if (((int32_T)DiscParams->agreement_combo[2] < 1) || ((int32_T)
       DiscParams->agreement_combo[2] > 6)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)DiscParams->agreement_combo[2], 1, 6,
      &f_emlrtBCI, sp);
  }

  for (j = 0; j < 1420864; j++) {
    SD->u1.f1.agreement_GBL[j] = DiscOutput->agreement[(j % 1192 + 1192 * (j /
      1192 % 1192)) + 1420864 * ((int32_T)DiscParams->agreement_combo[j /
      1420864] - 1)];
  }

  for (k = 0; k < 2; k++) {
    xoffset = (k + 1) * 1420864;
    for (j = 0; j < 1420864; j++) {
      i = xoffset + j;
      SD->u1.f1.agreement_GBL[j] *= DiscOutput->agreement[(i % 1192 + 1192 * (i /
        1192 % 1192)) + 1420864 * ((int32_T)DiscParams->agreement_combo[i /
        1420864] - 1)];
    }
  }

  for (i = 0; i < 1420864; i++) {
    SD->u1.f1.agreement_GBL[i] *= DiscOutput->dist_decay[i];
  }

  /*  set the initial bown (also the current bown) */
  st.site = &c_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  e_y = NULL;
  m = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a(&c_st, 7, m, &c_u[0]);
  emlrtAssign(&e_y, m);
  f_y = NULL;
  m = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&f_y, m);
  g_y = NULL;
  m = emlrtCreateCharArray(2, &iv4[0]);
  emlrtInitCharArrayR2013a(&c_st, 4, m, &d_u[0]);
  emlrtAssign(&g_y, m);
  h_y = NULL;
  m = emlrtCreateCharArray(2, &iv5[0]);
  emlrtInitCharArrayR2013a(&c_st, 7, m, &b_varargin_1[0]);
  emlrtAssign(&h_y, m);
  d_st.site = &gb_emlrtRSI;
  emlrt_marshallIn(&d_st, feval(&d_st, e_y, f_y, g_y, h_y, &emlrtMCI),
                   "<output of feval>");

  /*  propagate the bown signals based on the agreement matrix */
  /*  save the current bown as the initial one in the timecourse matrix */
  for (i = 0; i < 1192; i++) {
    DiscOutput->bown_timecourse[2385 * i] = DiscOutput->bown[i];
  }

  /*  initialize and declare nrep */
  st.site = &d_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  i_y = NULL;
  m = emlrtCreateCharArray(2, &iv6[0]);
  emlrtInitCharArrayR2013a(&c_st, 7, m, &e_u[0]);
  emlrtAssign(&i_y, m);
  j_y = NULL;
  m = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&j_y, m);
  k_y = NULL;
  m = emlrtCreateCharArray(2, &iv7[0]);
  emlrtInitCharArrayR2013a(&c_st, 4, m, &f_u[0]);
  emlrtAssign(&k_y, m);
  l_y = NULL;
  m = emlrtCreateCharArray(2, &iv8[0]);
  emlrtInitCharArrayR2013a(&c_st, 39, m, &c_varargin_1[0]);
  emlrtAssign(&l_y, m);
  d_st.site = &gb_emlrtRSI;
  emlrt_marshallIn(&d_st, feval(&d_st, i_y, j_y, k_y, l_y, &emlrtMCI),
                   "<output of feval>");

  /*  iterate till convergence */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, DiscParams->max_iter, mxDOUBLE_CLASS,
    (int32_T)DiscParams->max_iter, &d_emlrtRTEI, sp);
  nrep = 1.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j <= (int32_T)DiscParams->max_iter - 1)) {
    nrep = (real_T)j + 1.0;

    /*  compute the transition vector */
    /* global */
    st.site = &e_emlrtRSI;
    b_st.site = &ab_emlrtRSI;
    mtimes(DiscOutput->bown, SD->u1.f1.agreement_GBL, transition_vectorGBL);

    /* local */
    st.site = &f_emlrtRSI;
    b_st.site = &ab_emlrtRSI;
    mtimes(DiscOutput->bown, SD->u1.f1.agreement_LCL, transition_vectorLCL);

    /*  update bown */
    b_DiscOutput = DiscOutput->num_nodes - 1.0;

    /*  no negative "activities" -- they become 0 */
    for (xoffset = 0; xoffset < 1192; xoffset++) {
      DiscOutput->bown[xoffset] = (DiscOutput->bown[xoffset] +
        DiscParams->weightGBL * transition_vectorGBL[xoffset] / b_DiscOutput) +
        DiscParams->weightLCL * transition_vectorLCL[xoffset] /
        (DiscParams->Knear - 1.0);
      if (DiscOutput->bown[xoffset] < 0.0) {
        DiscOutput->bown[xoffset] = 0.0;
      }
    }

    /*  normalize bown */
    b_DiscOutput = DiscOutput->num_nodes / 2.0;
    if (1.0 > b_DiscOutput) {
      xoffset = 0;
    } else {
      if (b_DiscOutput != (int32_T)muDoubleScalarFloor(b_DiscOutput)) {
        emlrtIntegerCheckR2012b(b_DiscOutput, &b_emlrtDCI, sp);
      }

      if (((int32_T)b_DiscOutput < 1) || ((int32_T)b_DiscOutput > 1192)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_DiscOutput, 1, 1192, &emlrtBCI,
          sp);
      }

      xoffset = (int32_T)b_DiscOutput;
    }

    if (b_DiscOutput + 1.0 > DiscOutput->num_nodes) {
      i = -1;
      k = 0;
    } else {
      if (b_DiscOutput + 1.0 != (int32_T)muDoubleScalarFloor(b_DiscOutput + 1.0))
      {
        emlrtIntegerCheckR2012b(b_DiscOutput + 1.0, &c_emlrtDCI, sp);
      }

      if (((int32_T)(b_DiscOutput + 1.0) < 1) || ((int32_T)(b_DiscOutput + 1.0) >
           1192)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_DiscOutput + 1.0), 1, 1192,
          &b_emlrtBCI, sp);
      }

      i = (int32_T)(b_DiscOutput + 1.0) - 2;
      if (DiscOutput->num_nodes != (int32_T)muDoubleScalarFloor
          (DiscOutput->num_nodes)) {
        emlrtIntegerCheckR2012b(DiscOutput->num_nodes, &d_emlrtDCI, sp);
      }

      if (((int32_T)DiscOutput->num_nodes < 1) || ((int32_T)
           DiscOutput->num_nodes > 1192)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)DiscOutput->num_nodes, 1, 1192,
          &c_emlrtBCI, sp);
      }

      k = (int32_T)DiscOutput->num_nodes;
    }

    y_size[0] = 1;
    y_size[1] = xoffset;
    iv12[0] = 1;
    iv12[1] = (k - i) - 1;
    if (xoffset != iv12[1]) {
      emlrtSizeEqCheckNDR2012b(&y_size[0], &iv12[0], &emlrtECI, sp);
    }

    st.site = &g_emlrtRSI;
    DiscOutput_size[0] = 1;
    DiscOutput_size[1] = xoffset;
    for (k = 0; k < xoffset; k++) {
      transition_vectorGBL[k] = DiscOutput->bown[k] + DiscOutput->bown[(i + k) +
        1];
    }

    b_st.site = &g_emlrtRSI;
    c_repmat(&b_st, transition_vectorGBL, DiscOutput_size, y_data, y_size);
    if (1192 != y_size[1]) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI, "MATLAB:dimagree",
        "MATLAB:dimagree", 0);
    }

    for (i = 0; i < 1192; i++) {
      DiscOutput->bown[i] /= y_data[i];
    }

    /*  save the timecourse */
    if (((int32_T)(((real_T)j + 1.0) + 1.0) < 1) || ((int32_T)(((real_T)j + 1.0)
          + 1.0) > 2385)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(((real_T)j + 1.0) + 1.0), 1, 2385,
        &d_emlrtBCI, sp);
    }

    for (i = 0; i < 1192; i++) {
      DiscOutput->bown_timecourse[((int32_T)(((real_T)j + 1.0) + 1.0) + 2385 * i)
        - 1] = DiscOutput->bown[i];
    }

    /*  check for convergence */
    if ((j + 1 < 1) || (j + 1 > 2385)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, 2385, &e_emlrtBCI, sp);
    }

    for (k = 0; k < 1192; k++) {
      transition_vectorLCL[k] = muDoubleScalarAbs(DiscOutput->bown[k] -
        DiscOutput->bown_timecourse[j + 2385 * k]);
    }

    b_DiscOutput = transition_vectorLCL[0];
    for (k = 0; k < 1191; k++) {
      b_DiscOutput += transition_vectorLCL[k + 1];
    }

    if (b_DiscOutput < DiscOutput->num_nodes * DiscParams->convergence_lambda) {
      exitg1 = true;
    } else {
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  st.site = &h_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  m_y = NULL;
  m = emlrtCreateCharArray(2, &iv9[0]);
  emlrtInitCharArrayR2013a(&c_st, 7, m, &g_u[0]);
  emlrtAssign(&m_y, m);
  n_y = NULL;
  m = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&n_y, m);
  o_y = NULL;
  m = emlrtCreateCharArray(2, &iv10[0]);
  emlrtInitCharArrayR2013a(&c_st, 4, m, &h_u[0]);
  emlrtAssign(&o_y, m);
  p_y = NULL;
  m = emlrtCreateCharArray(2, &iv11[0]);
  emlrtInitCharArrayR2013a(&c_st, 21, m, &d_varargin_1[0]);
  emlrtAssign(&p_y, m);
  d_st.site = &gb_emlrtRSI;
  emlrt_marshallIn(&d_st, feval(&d_st, m_y, n_y, o_y, p_y, &emlrtMCI),
                   "<output of feval>");

  /*  save findings */
  /*  save the number of iterations needed */
  DiscOutput->num_iter = nrep;

  /*  save the converged bown values */
}

/* End of code generation (disc_compute_bown.c) */
