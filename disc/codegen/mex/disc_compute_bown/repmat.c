/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "disc_compute_bown_emxutil.h"
#include "disc_compute_bown_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 28,  /* lineNo */
  "repmat",                            /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 64,  /* lineNo */
  "repmat",                            /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 69,  /* lineNo */
  "repmat",                            /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtMCInfo d_emlrtMCI = { 47,  /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 31,    /* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 58,  /* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 59,/* lineNo */
  28,                                  /* colNo */
  "repmat",                            /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRSInfo hb_emlrtRSI = { 47, /* lineNo */
  "repmat",                            /* fcnName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

/* Function Declarations */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

void b_repmat(const emlrtStack *sp, const real_T a[1192], real_T varargin_1,
              emxArray_real_T *b)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_varargin_1;
  int32_T ibmat;
  int32_T itilerow;
  int32_T jcol;
  int32_T ntilerows;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) || muDoubleScalarIsInf
      (varargin_1) || (varargin_1 < -2.147483648E+9) || (varargin_1 >
       2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }

  if (!(b_varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &emlrtDCI, sp);
  }

  ntilerows = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1;
  b->size[1] = 1192;
  emxEnsureCapacity_real_T(sp, b, ntilerows, &n_emlrtRTEI);
  ntilerows = (int32_T)varargin_1;
  overflow = ((1 <= (int32_T)varargin_1) && ((int32_T)varargin_1 > 2147483646));
  for (jcol = 0; jcol < 1192; jcol++) {
    ibmat = jcol * (int32_T)varargin_1;
    st.site = &y_emlrtRSI;
    if (overflow) {
      b_st.site = &x_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b->data[ibmat + itilerow] = a[jcol];
    }
  }
}

void c_repmat(const emlrtStack *sp, const real_T a_data[], const int32_T a_size
              [2], real_T b_data[], int32_T b_size[2])
{
  static const int32_T b_iv[2] = { 1, 15 };

  static const char_T u[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
    'x', 's', 'i', 'z', 'e' };

  emlrtStack st;
  const mxArray *m;
  const mxArray *y;
  int32_T jcol;
  int32_T ncols;
  st.prev = sp;
  st.tls = sp->tls;
  ncols = a_size[1] << 1;
  if ((int16_T)ncols != ncols) {
    y = NULL;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(sp, 15, m, &u[0]);
    emlrtAssign(&y, m);
    st.site = &hb_emlrtRSI;
    error(&st, y, &d_emlrtMCI);
  }

  b_size[0] = 1;
  b_size[1] = (int16_T)ncols;
  ncols = a_size[1];
  if (0 <= ncols - 1) {
    memcpy(&b_data[0], &a_data[0], ncols * sizeof(real_T));
  }

  for (jcol = 0; jcol < ncols; jcol++) {
    b_data[ncols + jcol] = a_data[jcol];
  }
}

void repmat(const emlrtStack *sp, const real_T a[1192], real_T varargin_2,
            emxArray_real_T *b)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_varargin_2;
  int32_T ibtile;
  int32_T jtilecol;
  int32_T k;
  int32_T ntilecols;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_2 != muDoubleScalarFloor(varargin_2)) || muDoubleScalarIsInf
      (varargin_2) || (varargin_2 < -2.147483648E+9) || (varargin_2 >
       2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_2 <= 0.0) {
    b_varargin_2 = 0.0;
  } else {
    b_varargin_2 = varargin_2;
  }

  if (!(b_varargin_2 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  if (!(varargin_2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, &emlrtDCI, sp);
  }

  ntilecols = b->size[0] * b->size[1];
  b->size[0] = 1192;
  b->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity_real_T(sp, b, ntilecols, &n_emlrtRTEI);
  ntilecols = (int32_T)varargin_2;
  st.site = &w_emlrtRSI;
  if ((1 <= (int32_T)varargin_2) && ((int32_T)varargin_2 > 2147483646)) {
    b_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (jtilecol = 0; jtilecol < ntilecols; jtilecol++) {
    ibtile = jtilecol * 1192;
    for (k = 0; k < 1192; k++) {
      b->data[ibtile + k] = a[k];
    }
  }
}

/* End of code generation (repmat.c) */
