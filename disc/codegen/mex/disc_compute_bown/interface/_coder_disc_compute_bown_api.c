/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_disc_compute_bown_api.c
 *
 * Code generation for function '_coder_disc_compute_bown_api'
 *
 */

/* Include files */
#include "_coder_disc_compute_bown_api.h"
#include "disc_compute_bown.h"
#include "disc_compute_bown_data.h"
#include "disc_compute_bown_mexutil.h"
#include "disc_compute_bown_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static const int32_T iv[3] = { 1192, 1192, 6 };

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
  disc_compute_bownStackData *SD, const struct0_T *u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DiscOutput,
  const char_T *identifier, struct0_T *y);
static const mxArray *c_emlrt_marshallOut(const real_T u[1192]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *d_emlrt_marshallOut(const real_T u[1420864]);
static rtString e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[13]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1192]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2842920]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1420864]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8525184]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T y[801]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1192]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DiscParams,
  const char_T *identifier, struct2_T *y);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[13]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1192]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2842920]);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1420864]);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8525184]);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1192]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[2] = { 1, 3 };

  real_T (*r)[3];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
  disc_compute_bownStackData *SD, const struct0_T *u)
{
  static const int32_T b_iv[2] = { 1, 13 };

  static const int32_T iv1[2] = { 2385, 1192 };

  static const int32_T iv2[2] = { 1, 4 };

  static const int32_T iv10[1] = { 1192 };

  static const int32_T iv4[1] = { 1192 };

  static const int32_T iv5[1] = { 1192 };

  static const int32_T iv6[1] = { 1192 };

  static const int32_T iv7[1] = { 1192 };

  static const int32_T iv8[1] = { 1192 };

  static const int32_T iv9[1] = { 1192 };

  static const char_T *sv[17] = { "stim_name", "num_nodes", "pos_x", "pos_y",
    "dx", "dy", "angle", "bown", "color_norm", "color_contrast",
    "bown_timecourse", "num_iter", "dist_decay", "distance", "agreement",
    "axes_range", "NB" };

  static const char_T *sv1[7] = { "NBind", "NBpos_x", "NBpos_y", "NBang", "NBdx",
    "NBdy", "NBcolor_norm" };

  const mxArray *propValues[1];
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
  const mxArray *m1;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *y;
  const struct1_T *r;
  real_T b_u[1192];
  real_T *pData;
  int32_T iv3[2];
  int32_T b_i;
  int32_T c_i;
  int32_T d_i;
  int32_T i;
  const char_T *propClasses[1] = { "coder.internal.string" };

  const char_T *propNames[1] = { "Value" };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 17, sv));
  b_y = NULL;
  m = NULL;
  emlrtAssign(&b_y, emlrtCreateClassInstance("coder.internal.string"));
  m = NULL;
  c_y = NULL;
  m1 = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a(sp, 13, m1, &u->stim_name.Value[0]);
  emlrtAssign(&c_y, m1);
  emlrtAssign(&m, c_y);
  propValues[0] = m;
  emlrtSetAllProperties(sp, &b_y, 0, 1, propNames, propClasses, propValues);
  emlrtAssign(&b_y, emlrtConvertInstanceToRedirectSource(sp, b_y, 0,
    "coder.internal.string"));
  emlrtSetFieldR2017b(y, 0, "stim_name", b_y, 0);
  d_y = NULL;
  m1 = emlrtCreateDoubleScalar(u->num_nodes);
  emlrtAssign(&d_y, m1);
  emlrtSetFieldR2017b(y, 0, "num_nodes", d_y, 1);
  emlrtSetFieldR2017b(y, 0, "pos_x", c_emlrt_marshallOut(u->pos_x), 2);
  emlrtSetFieldR2017b(y, 0, "pos_y", c_emlrt_marshallOut(u->pos_y), 3);
  emlrtSetFieldR2017b(y, 0, "dx", c_emlrt_marshallOut(u->dx), 4);
  emlrtSetFieldR2017b(y, 0, "dy", c_emlrt_marshallOut(u->dy), 5);
  emlrtSetFieldR2017b(y, 0, "angle", c_emlrt_marshallOut(u->angle), 6);
  emlrtSetFieldR2017b(y, 0, "bown", c_emlrt_marshallOut(u->bown), 7);
  emlrtSetFieldR2017b(y, 0, "color_norm", c_emlrt_marshallOut(u->color_norm), 8);
  emlrtSetFieldR2017b(y, 0, "color_contrast", c_emlrt_marshallOut
                      (u->color_contrast), 9);
  e_y = NULL;
  m1 = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m1);
  i = 0;
  for (b_i = 0; b_i < 1192; b_i++) {
    for (c_i = 0; c_i < 2385; c_i++) {
      pData[i] = u->bown_timecourse[c_i + 2385 * b_i];
      i++;
    }
  }

  emlrtAssign(&e_y, m1);
  emlrtSetFieldR2017b(y, 0, "bown_timecourse", e_y, 10);
  f_y = NULL;
  m1 = emlrtCreateDoubleScalar(u->num_iter);
  emlrtAssign(&f_y, m1);
  emlrtSetFieldR2017b(y, 0, "num_iter", f_y, 11);
  emlrtSetFieldR2017b(y, 0, "dist_decay", d_emlrt_marshallOut(u->dist_decay), 12);
  emlrtSetFieldR2017b(y, 0, "distance", d_emlrt_marshallOut(u->distance), 13);
  g_y = NULL;
  m1 = emlrtCreateNumericArray(3, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m1);
  i = 0;
  for (b_i = 0; b_i < 6; b_i++) {
    for (c_i = 0; c_i < 1192; c_i++) {
      for (d_i = 0; d_i < 1192; d_i++) {
        pData[i] = u->agreement[(d_i + 1192 * c_i) + 1420864 * b_i];
        i++;
      }
    }
  }

  emlrtAssign(&g_y, m1);
  emlrtSetFieldR2017b(y, 0, "agreement", g_y, 14);
  h_y = NULL;
  m1 = emlrtCreateNumericArray(2, &iv2[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m1);
  pData[0] = u->axes_range[0];
  pData[1] = u->axes_range[1];
  pData[2] = u->axes_range[2];
  pData[3] = u->axes_range[3];
  emlrtAssign(&h_y, m1);
  emlrtSetFieldR2017b(y, 0, "axes_range", h_y, 15);
  memcpy(&SD->u1.f0.u[0], &u->NB[0], 801U * sizeof(struct1_T));
  i_y = NULL;
  iv3[0] = 1;
  iv3[1] = 801;
  emlrtAssign(&i_y, emlrtCreateStructArray(2, iv3, 7, sv1));
  for (i = 0; i < 801; i++) {
    r = &SD->u1.f0.u[i];
    for (b_i = 0; b_i < 1192; b_i++) {
      b_u[b_i] = r->NBind[b_i];
    }

    j_y = NULL;
    m1 = emlrtCreateNumericArray(1, &iv4[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m1);
    c_i = 0;
    for (b_i = 0; b_i < 1192; b_i++) {
      pData[c_i] = b_u[b_i];
      c_i++;
    }

    emlrtAssign(&j_y, m1);
    emlrtSetFieldR2017b(i_y, i, "NBind", j_y, 0);
    for (b_i = 0; b_i < 1192; b_i++) {
      b_u[b_i] = r->NBpos_x[b_i];
    }

    k_y = NULL;
    m1 = emlrtCreateNumericArray(1, &iv5[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m1);
    c_i = 0;
    for (b_i = 0; b_i < 1192; b_i++) {
      pData[c_i] = b_u[b_i];
      c_i++;
    }

    emlrtAssign(&k_y, m1);
    emlrtSetFieldR2017b(i_y, i, "NBpos_x", k_y, 1);
    for (b_i = 0; b_i < 1192; b_i++) {
      b_u[b_i] = r->NBpos_y[b_i];
    }

    l_y = NULL;
    m1 = emlrtCreateNumericArray(1, &iv6[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m1);
    c_i = 0;
    for (b_i = 0; b_i < 1192; b_i++) {
      pData[c_i] = b_u[b_i];
      c_i++;
    }

    emlrtAssign(&l_y, m1);
    emlrtSetFieldR2017b(i_y, i, "NBpos_y", l_y, 2);
    for (b_i = 0; b_i < 1192; b_i++) {
      b_u[b_i] = r->NBang[b_i];
    }

    m_y = NULL;
    m1 = emlrtCreateNumericArray(1, &iv7[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m1);
    c_i = 0;
    for (b_i = 0; b_i < 1192; b_i++) {
      pData[c_i] = b_u[b_i];
      c_i++;
    }

    emlrtAssign(&m_y, m1);
    emlrtSetFieldR2017b(i_y, i, "NBang", m_y, 3);
    for (b_i = 0; b_i < 1192; b_i++) {
      b_u[b_i] = r->NBdx[b_i];
    }

    n_y = NULL;
    m1 = emlrtCreateNumericArray(1, &iv8[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m1);
    c_i = 0;
    for (b_i = 0; b_i < 1192; b_i++) {
      pData[c_i] = b_u[b_i];
      c_i++;
    }

    emlrtAssign(&n_y, m1);
    emlrtSetFieldR2017b(i_y, i, "NBdx", n_y, 4);
    for (b_i = 0; b_i < 1192; b_i++) {
      b_u[b_i] = r->NBdy[b_i];
    }

    o_y = NULL;
    m1 = emlrtCreateNumericArray(1, &iv9[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m1);
    c_i = 0;
    for (b_i = 0; b_i < 1192; b_i++) {
      pData[c_i] = b_u[b_i];
      c_i++;
    }

    emlrtAssign(&o_y, m1);
    emlrtSetFieldR2017b(i_y, i, "NBdy", o_y, 5);
    for (b_i = 0; b_i < 1192; b_i++) {
      b_u[b_i] = r->NBcolor_norm[b_i];
    }

    p_y = NULL;
    m1 = emlrtCreateNumericArray(1, &iv10[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m1);
    c_i = 0;
    for (b_i = 0; b_i < 1192; b_i++) {
      pData[c_i] = b_u[b_i];
      c_i++;
    }

    emlrtAssign(&p_y, m1);
    emlrtSetFieldR2017b(i_y, i, "NBcolor_norm", p_y, 6);
  }

  emlrtSetFieldR2017b(y, 0, "NB", i_y, 16);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7])
{
  static const int32_T dims[2] = { 1, 7 };

  real_T (*r)[7];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[7])emlrtMxGetData(src);
  for (i = 0; i < 7; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DiscOutput,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(DiscOutput), &thisId, y);
  emlrtDestroyArray(&DiscOutput);
}

static const mxArray *c_emlrt_marshallOut(const real_T u[1192])
{
  static const int32_T b_iv[2] = { 1, 1192 };

  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 1192; b_i++) {
    pData[i] = u[b_i];
    i++;
  }

  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[17] = { "stim_name", "num_nodes", "pos_x",
    "pos_y", "dx", "dy", "angle", "bown", "color_norm", "color_contrast",
    "bown_timecourse", "num_iter", "dist_decay", "distance", "agreement",
    "axes_range", "NB" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 17, fieldNames, 0U, &dims);
  thisId.fIdentifier = "stim_name";
  y->stim_name = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    0, "stim_name")), &thisId);
  thisId.fIdentifier = "num_nodes";
  y->num_nodes = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    1, "num_nodes")), &thisId);
  thisId.fIdentifier = "pos_x";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "pos_x")),
                     &thisId, y->pos_x);
  thisId.fIdentifier = "pos_y";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "pos_y")),
                     &thisId, y->pos_y);
  thisId.fIdentifier = "dx";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "dx")),
                     &thisId, y->dx);
  thisId.fIdentifier = "dy";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "dy")),
                     &thisId, y->dy);
  thisId.fIdentifier = "angle";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "angle")),
                     &thisId, y->angle);
  thisId.fIdentifier = "bown";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7, "bown")),
                     &thisId, y->bown);
  thisId.fIdentifier = "color_norm";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "color_norm")), &thisId, y->color_norm);
  thisId.fIdentifier = "color_contrast";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "color_contrast")), &thisId, y->color_contrast);
  thisId.fIdentifier = "bown_timecourse";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "bown_timecourse")), &thisId, y->bown_timecourse);
  thisId.fIdentifier = "num_iter";
  y->num_iter = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    11, "num_iter")), &thisId);
  thisId.fIdentifier = "dist_decay";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "dist_decay")), &thisId, y->dist_decay);
  thisId.fIdentifier = "distance";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13, "distance")),
                     &thisId, y->distance);
  thisId.fIdentifier = "agreement";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 14,
    "agreement")), &thisId, y->agreement);
  thisId.fIdentifier = "axes_range";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 15,
    "axes_range")), &thisId, y->axes_range);
  thisId.fIdentifier = "NB";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "NB")),
                     &thisId, y->NB);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const real_T u[1420864])
{
  static const int32_T b_iv[2] = { 1192, 1192 };

  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 1192; b_i++) {
    for (c_i = 0; c_i < 1192; c_i++) {
      pData[i] = u[c_i + 1192 * b_i];
      i++;
    }
  }

  emlrtAssign(&y, m);
  return y;
}

static rtString e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[1];
  rtString y;
  const char_T *propClasses[1] = { "coder.internal.string" };

  const char_T *propNames[1] = { "Value" };

  propValues[0] = NULL;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(sp, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(sp, u, 0,
    "coder.internal.string"));
  emlrtCheckMcosClass2017a(sp, parentId, u, "coder.internal.string");
  emlrtGetAllProperties(sp, u, 0, 1, propNames, propClasses, propValues);
  thisId.fIdentifier = "Value";
  f_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y.Value);
  emlrtDestroyArrays(1, (const mxArray **)&propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[13])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1192])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2842920])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1420864])
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8525184])
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T y[801])
{
  static const int32_T dims[2] = { 1, 801 };

  static const char_T *fieldNames[7] = { "NBind", "NBpos_x", "NBpos_y", "NBang",
    "NBdx", "NBdy", "NBcolor_norm" };

  emlrtMsgIdentifier thisId;
  int32_T i;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 7, fieldNames, 2U, dims);
  for (i = 0; i < 801; i++) {
    thisId.fIdentifier = "NBind";
    m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 0, "NBind")),
                       &thisId, y[i].NBind);
    thisId.fIdentifier = "NBpos_x";
    m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 1, "NBpos_x")),
                       &thisId, y[i].NBpos_x);
    thisId.fIdentifier = "NBpos_y";
    m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 2, "NBpos_y")),
                       &thisId, y[i].NBpos_y);
    thisId.fIdentifier = "NBang";
    m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 3, "NBang")),
                       &thisId, y[i].NBang);
    thisId.fIdentifier = "NBdx";
    m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 4, "NBdx")),
                       &thisId, y[i].NBdx);
    thisId.fIdentifier = "NBdy";
    m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 5, "NBdy")),
                       &thisId, y[i].NBdy);
    thisId.fIdentifier = "NBcolor_norm";
    m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 6,
      "NBcolor_norm")), &thisId, y[i].NBcolor_norm);
  }

  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1192])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DiscParams,
  const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  o_emlrt_marshallIn(sp, emlrtAlias(DiscParams), &thisId, y);
  emlrtDestroyArray(&DiscParams);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[11] = { "initial_bown", "space_constant",
    "agreement_combo", "bown_params", "convergence_lambda", "max_iter", "Knear",
    "weightLCL", "weightGBL", "linearAngTh", "distLCL" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 11, fieldNames, 0U, &dims);
  thisId.fIdentifier = "initial_bown";
  y->initial_bown = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 0, "initial_bown")), &thisId);
  thisId.fIdentifier = "space_constant";
  y->space_constant = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 1, "space_constant")), &thisId);
  thisId.fIdentifier = "agreement_combo";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "agreement_combo")), &thisId, y->agreement_combo);
  thisId.fIdentifier = "bown_params";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "bown_params")), &thisId, y->bown_params);
  thisId.fIdentifier = "convergence_lambda";
  y->convergence_lambda = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    (sp, u, 0, 4, "convergence_lambda")), &thisId);
  thisId.fIdentifier = "max_iter";
  y->max_iter = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    5, "max_iter")), &thisId);
  thisId.fIdentifier = "Knear";
  y->Knear = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "Knear")), &thisId);
  thisId.fIdentifier = "weightLCL";
  y->weightLCL = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    7, "weightLCL")), &thisId);
  thisId.fIdentifier = "weightGBL";
  y->weightGBL = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    8, "weightGBL")), &thisId);
  thisId.fIdentifier = "linearAngTh";
  y->linearAngTh = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 9, "linearAngTh")), &thisId);
  thisId.fIdentifier = "distLCL";
  y->distLCL = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    10, "distLCL")), &thisId);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[13])
{
  static const int32_T dims[2] = { 1, 13 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 13);
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1192])
{
  static const int32_T dims[2] = { 1, 1192 };

  real_T (*r)[1192];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[1192])emlrtMxGetData(src);
  for (i = 0; i < 1192; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2842920])
{
  static const int32_T dims[2] = { 2385, 1192 };

  real_T (*r)[2842920];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[2842920])emlrtMxGetData(src);
  for (i = 0; i < 2842920; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1420864])
{
  static const int32_T dims[2] = { 1192, 1192 };

  real_T (*r)[1420864];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[1420864])emlrtMxGetData(src);
  for (i = 0; i < 1420864; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8525184])
{
  real_T (*r)[8525184];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, iv);
  r = (real_T (*)[8525184])emlrtMxGetData(src);
  for (i = 0; i < 8525184; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  real_T (*r)[4];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1192])
{
  static const int32_T dims[1] = { 1192 };

  real_T (*r)[1192];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  r = (real_T (*)[1192])emlrtMxGetData(src);
  for (i = 0; i < 1192; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

void disc_compute_bown_api(disc_compute_bownStackData *SD, const mxArray * const
  prhs[2], const mxArray *plhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  struct2_T DiscParams;
  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "DiscOutput", &SD->f2.DiscOutput);
  n_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "DiscParams", &DiscParams);

  /* Invoke the target function */
  disc_compute_bown(SD, &st, &SD->f2.DiscOutput, &DiscParams);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(&st, SD, &SD->f2.DiscOutput);
}

/* End of code generation (_coder_disc_compute_bown_api.c) */
