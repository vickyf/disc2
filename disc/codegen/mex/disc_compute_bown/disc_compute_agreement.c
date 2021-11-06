/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * disc_compute_agreement.c
 *
 * Code generation for function 'disc_compute_agreement'
 *
 */

/* Include files */
#include "disc_compute_agreement.h"
#include "acos.h"
#include "disc_compute_bown_data.h"
#include "disc_compute_bown_emxutil.h"
#include "disc_compute_bown_types.h"
#include "norm.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = { 64,  /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 65,  /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 110, /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 112, /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 158, /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 165, /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 171, /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 223, /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 225, /* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtMCInfo b_emlrtMCI = { 104, /* lineNo */
  17,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 217, /* lineNo */
  17,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 60,/* lineNo */
  9,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 61,/* lineNo */
  13,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtDCInfo f_emlrtDCI = { 76,  /* lineNo */
  106,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  76,                                  /* lineNo */
  106,                                 /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 76,  /* lineNo */
  131,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  76,                                  /* lineNo */
  131,                                 /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 76,  /* lineNo */
  21,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  76,                                  /* lineNo */
  21,                                  /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 76,  /* lineNo */
  52,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  76,                                  /* lineNo */
  52,                                  /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  76,                                  /* lineNo */
  1,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtDCInfo j_emlrtDCI = { 77,  /* lineNo */
  106,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  77,                                  /* lineNo */
  106,                                 /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 77,  /* lineNo */
  131,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  77,                                  /* lineNo */
  131,                                 /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 77,  /* lineNo */
  23,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  77,                                  /* lineNo */
  23,                                  /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 77,  /* lineNo */
  46,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  77,                                  /* lineNo */
  46,                                  /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  77,                                  /* lineNo */
  1,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtDCInfo n_emlrtDCI = { 78,  /* lineNo */
  106,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  78,                                  /* lineNo */
  106,                                 /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 78,  /* lineNo */
  131,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  78,                                  /* lineNo */
  131,                                 /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 78,  /* lineNo */
  21,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  78,                                  /* lineNo */
  21,                                  /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 78,  /* lineNo */
  50,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  78,                                  /* lineNo */
  50,                                  /* colNo */
  "DiscOutput.distance",               /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  78,                                  /* lineNo */
  1,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtDCInfo r_emlrtDCI = { 80,  /* lineNo */
  108,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  80,                                  /* lineNo */
  108,                                 /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 80,  /* lineNo */
  133,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  80,                                  /* lineNo */
  133,                                 /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 80,  /* lineNo */
  23,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  80,                                  /* lineNo */
  23,                                  /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 80,  /* lineNo */
  54,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  80,                                  /* lineNo */
  54,                                  /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  80,                                  /* lineNo */
  1,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtDCInfo v_emlrtDCI = { 81,  /* lineNo */
  108,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  81,                                  /* lineNo */
  108,                                 /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 81,  /* lineNo */
  133,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  81,                                  /* lineNo */
  133,                                 /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 81,  /* lineNo */
  25,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  1192,                                /* iLast */
  81,                                  /* lineNo */
  25,                                  /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 81,  /* lineNo */
  48,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  81,                                  /* lineNo */
  48,                                  /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  81,                                  /* lineNo */
  1,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtDCInfo ab_emlrtDCI = { 82, /* lineNo */
  108,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  82,                                  /* lineNo */
  108,                                 /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 82, /* lineNo */
  133,                                 /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  82,                                  /* lineNo */
  133,                                 /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 82, /* lineNo */
  23,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  82,                                  /* lineNo */
  23,                                  /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 82, /* lineNo */
  52,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  82,                                  /* lineNo */
  52,                                  /* colNo */
  "DiscOutput.dist_decay",             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  82,                                  /* lineNo */
  1,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 87,/* lineNo */
  9,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 88,/* lineNo */
  13,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  158,                                 /* lineNo */
  5,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { 2,   /* nDims */
  165,                                 /* lineNo */
  5,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { 2,   /* nDims */
  171,                                 /* lineNo */
  5,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 184,/* lineNo */
  8,                                   /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtBCInfo fb_emlrtBCI = { 1,  /* iFirst */
  801,                                 /* iLast */
  185,                                 /* lineNo */
  37,                                  /* colNo */
  "neighborDbl",                       /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo k_emlrtRTEI = { 187,/* lineNo */
  13,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtBCInfo gb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  188,                                 /* lineNo */
  19,                                  /* colNo */
  "indNB",                             /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 196,/* lineNo */
  39,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  196,                                 /* lineNo */
  39,                                  /* colNo */
  "DiscOutput.pos_x",                  /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo l_emlrtRTEI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtBCInfo ib_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  64,                                  /* lineNo */
  30,                                  /* colNo */
  "DiscOutput.pos_x",                  /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  64,                                  /* lineNo */
  50,                                  /* colNo */
  "DiscOutput.pos_x",                  /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  65,                                  /* lineNo */
  15,                                  /* colNo */
  "DiscOutput.pos_y",                  /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  94,                                  /* lineNo */
  24,                                  /* colNo */
  "DiscOutput.pos_x",                  /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { 1,  /* iFirst */
  1192,                                /* iLast */
  94,                                  /* lineNo */
  64,                                  /* colNo */
  "DiscOutput.pos_y",                  /* aName */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo m_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "G:\\Others\\MATLAB\\R2020\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 76,/* lineNo */
  84,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 77,/* lineNo */
  84,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 78,/* lineNo */
  84,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 80,/* lineNo */
  84,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 81,/* lineNo */
  84,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 82,/* lineNo */
  84,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 1, /* lineNo */
  25,                                  /* colNo */
  "disc_compute_agreement",            /* fName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pName */
};

static emlrtRSInfo eb_emlrtRSI = { 217,/* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 104,/* lineNo */
  "disc_compute_agreement",            /* fcnName */
  "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_agreement.m"/* pathName */
};

/* Function Declarations */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[3]);

/* Function Definitions */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "disp", true, location);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[3])
{
  static const int32_T b_iv[2] = { 1, 3 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a(sp, 3, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

void disc_compute_agreement(const emlrtStack *sp, struct0_T *DiscOutput, real_T
  DiscParams_space_constant, const real_T DiscParams_bown_params[7], real_T
  DiscParams_Knear, real_T DiscParams_linearAngTh)
{
  static const char_T cv[3] = { 'n', 'a', 'n' };

  emlrtStack st;
  emxArray_real_T *b_DiscOutput;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  creal_T alpha_i;
  creal_T alpha_j;
  real_T c_DiscOutput[1192];
  real_T norm_i2j[2];
  real_T vec_i2j[2];
  real_T vecprev_j[2];
  real_T b_j;
  real_T br;
  real_T d;
  real_T distanceTemp;
  real_T linearAngCos;
  real_T re;
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T b_i;
  int32_T condI;
  int32_T condJ;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T iK;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  DISC_COMPUTE_AGREEMENT - computes if nodes are in agreement */
  /*  */
  /*  Synopsis */
  /*    [ DiscOutput ] = disc_compute_agreement( DiscOutput,DiscParams ) */
  /*  */
  /*  Description */
  /*    Based on the original DISC code by Naoki Kogo extended for the use */
  /*    cases and theories behind DISC2. */
  /*  */
  /*  Inputs ([]s are optional) */
  /*    (struct)    DiscOutput */
  /*  */
  /*  Outputs ([]s are optional) */
  /*    (struct)    DiscOutput */
  /*    (struct)    DiscParams */
  /*  */
  /*  Examples */
  /*    <Example Code> */
  /*  */
  /*  See also */
  /*    disc_main, disc_params_default, disc_compute_bown */
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
  /*  compute pairwise distances for graded interaction */
  d = DiscOutput->num_nodes / 2.0;
  i = (int32_T)d;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
    &f_emlrtRTEI, sp);
  for (b_i = 0; b_i < i; b_i++) {
    d = DiscOutput->num_nodes / 2.0;
    i1 = (int32_T)(d + (1.0 - (((real_T)b_i + 1.0) + 1.0)));
    emlrtForLoopVectorCheckR2012b(((real_T)b_i + 1.0) + 1.0, 1.0, d,
      mxDOUBLE_CLASS, i1, &g_emlrtRTEI, sp);
    for (j = 0; j < i1; j++) {
      b_j = (((real_T)b_i + 1.0) + 1.0) + (real_T)j;

      /*  compute the graded interaction -- the further away the less */
      /*  influence two nodes with assert. */
      st.site = &k_emlrtRSI;
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > 1192)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, 1192, &ib_emlrtBCI,
          &st);
      }

      if (((int32_T)b_j < 1) || ((int32_T)b_j > 1192)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_j, 1, 1192, &jb_emlrtBCI, &st);
      }

      distanceTemp = DiscOutput->pos_x[b_i] - DiscOutput->pos_x[(int32_T)b_j - 1];
      st.site = &l_emlrtRSI;
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > 1192)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, 1192, &kb_emlrtBCI,
          &st);
      }

      linearAngCos = DiscOutput->pos_y[b_i] - DiscOutput->pos_y[(int32_T)b_j - 1];
      distanceTemp = distanceTemp * distanceTemp + linearAngCos * linearAngCos;
      st.site = &k_emlrtRSI;
      if (distanceTemp < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      distanceTemp = muDoubleScalarSqrt(distanceTemp);
      i2 = b_i + 1192 * ((int32_T)b_j - 1);
      DiscOutput->distance[i2] = distanceTemp;
      DiscOutput->dist_decay[i2] = muDoubleScalarExp(-distanceTemp /
        DiscParams_space_constant);

      /*  reflect over diagonal to grab the other side */
      condJ = ((int32_T)b_j + 1192 * b_i) - 1;
      DiscOutput->distance[condJ] = DiscOutput->distance[i2];
      DiscOutput->dist_decay[condJ] = DiscOutput->dist_decay[i2];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  the full matrix contains four blocks of the same configuration: */
  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    j = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &f_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &g_emlrtBCI, sp);
    }

    j = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    condI = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &g_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &h_emlrtBCI, sp);
    }

    condI = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (d + 1.0 > 1192.0) {
    i = -1;
    i1 = -1;
  } else {
    if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
      emlrtIntegerCheckR2012b(d + 1.0, &h_emlrtDCI, sp);
    }

    if (((int32_T)(d + 1.0) < 1) || ((int32_T)(d + 1.0) > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(d + 1.0), 1, 1192, &i_emlrtBCI, sp);
    }

    i = (int32_T)(d + 1.0) - 2;
    i1 = 1191;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    i2 = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &i_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &j_emlrtBCI, sp);
    }

    i2 = (int32_T)d;
  }

  emxInit_real_T(sp, &b_DiscOutput, 2, &o_emlrtRTEI, true);
  b_iv[0] = i1 - i;
  b_iv[1] = i2;
  iv1[0] = j;
  iv1[1] = condI;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &b_emlrtECI, sp);
  i1 = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(sp, b_DiscOutput, i1, &o_emlrtRTEI);
  for (i1 = 0; i1 < condI; i1++) {
    for (i2 = 0; i2 < j; i2++) {
      b_DiscOutput->data[i2 + b_DiscOutput->size[0] * i1] = DiscOutput->
        distance[i2 + 1192 * i1];
    }
  }

  j = b_DiscOutput->size[1];
  for (i1 = 0; i1 < j; i1++) {
    condI = b_DiscOutput->size[0];
    for (i2 = 0; i2 < condI; i2++) {
      DiscOutput->distance[((i + i2) + 1192 * i1) + 1] = b_DiscOutput->data[i2 +
        b_DiscOutput->size[0] * i1];
    }
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    j = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &j_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &k_emlrtBCI, sp);
    }

    j = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    condI = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &k_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &l_emlrtBCI, sp);
    }

    condI = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    i = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &l_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &m_emlrtBCI, sp);
    }

    i = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (d + 1.0 > 1192.0) {
    i1 = -1;
    i2 = -1;
  } else {
    if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
      emlrtIntegerCheckR2012b(d + 1.0, &m_emlrtDCI, sp);
    }

    if (((int32_T)(d + 1.0) < 1) || ((int32_T)(d + 1.0) > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(d + 1.0), 1, 1192, &n_emlrtBCI, sp);
    }

    i1 = (int32_T)(d + 1.0) - 2;
    i2 = 1191;
  }

  b_iv[0] = i;
  b_iv[1] = i2 - i1;
  iv1[0] = j;
  iv1[1] = condI;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &c_emlrtECI, sp);
  i = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(sp, b_DiscOutput, i, &p_emlrtRTEI);
  for (i = 0; i < condI; i++) {
    for (i2 = 0; i2 < j; i2++) {
      b_DiscOutput->data[i2 + b_DiscOutput->size[0] * i] = DiscOutput->
        distance[i2 + 1192 * i];
    }
  }

  j = b_DiscOutput->size[1];
  for (i = 0; i < j; i++) {
    condI = b_DiscOutput->size[0];
    for (i2 = 0; i2 < condI; i2++) {
      DiscOutput->distance[i2 + 1192 * ((i1 + i) + 1)] = b_DiscOutput->data[i2 +
        b_DiscOutput->size[0] * i];
    }
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    j = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &n_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &o_emlrtBCI, sp);
    }

    j = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    condI = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &o_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &p_emlrtBCI, sp);
    }

    condI = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0 + 1.0;
  if (d > 1192.0) {
    i = -1;
    i1 = -1;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &p_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &q_emlrtBCI, sp);
    }

    i = (int32_T)d - 2;
    i1 = 1191;
  }

  d = DiscOutput->num_nodes / 2.0 + 1.0;
  if (d > 1192.0) {
    i2 = -1;
    condJ = -1;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &q_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &r_emlrtBCI, sp);
    }

    i2 = (int32_T)d - 2;
    condJ = 1191;
  }

  b_iv[0] = i1 - i;
  b_iv[1] = condJ - i2;
  iv1[0] = j;
  iv1[1] = condI;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &d_emlrtECI, sp);
  i1 = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(sp, b_DiscOutput, i1, &q_emlrtRTEI);
  for (i1 = 0; i1 < condI; i1++) {
    for (condJ = 0; condJ < j; condJ++) {
      b_DiscOutput->data[condJ + b_DiscOutput->size[0] * i1] =
        DiscOutput->distance[condJ + 1192 * i1];
    }
  }

  j = b_DiscOutput->size[1];
  for (i1 = 0; i1 < j; i1++) {
    condI = b_DiscOutput->size[0];
    for (condJ = 0; condJ < condI; condJ++) {
      DiscOutput->distance[((i + condJ) + 1192 * ((i2 + i1) + 1)) + 1] =
        b_DiscOutput->data[condJ + b_DiscOutput->size[0] * i1];
    }
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    j = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &r_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &s_emlrtBCI, sp);
    }

    j = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    condI = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &s_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &t_emlrtBCI, sp);
    }

    condI = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0 + 1.0;
  if (d > 1192.0) {
    i = -1;
    i1 = -1;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &t_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &u_emlrtBCI, sp);
    }

    i = (int32_T)d - 2;
    i1 = 1191;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    i2 = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &u_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &v_emlrtBCI, sp);
    }

    i2 = (int32_T)d;
  }

  b_iv[0] = i1 - i;
  b_iv[1] = i2;
  iv1[0] = j;
  iv1[1] = condI;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &e_emlrtECI, sp);
  i1 = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(sp, b_DiscOutput, i1, &r_emlrtRTEI);
  for (i1 = 0; i1 < condI; i1++) {
    for (i2 = 0; i2 < j; i2++) {
      b_DiscOutput->data[i2 + b_DiscOutput->size[0] * i1] =
        DiscOutput->dist_decay[i2 + 1192 * i1];
    }
  }

  j = b_DiscOutput->size[1];
  for (i1 = 0; i1 < j; i1++) {
    condI = b_DiscOutput->size[0];
    for (i2 = 0; i2 < condI; i2++) {
      DiscOutput->dist_decay[((i + i2) + 1192 * i1) + 1] = b_DiscOutput->data[i2
        + b_DiscOutput->size[0] * i1];
    }
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    j = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &v_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &w_emlrtBCI, sp);
    }

    j = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    condI = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &w_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &x_emlrtBCI, sp);
    }

    condI = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    i = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &x_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &y_emlrtBCI, sp);
    }

    i = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0 + 1.0;
  if (d > 1192.0) {
    i1 = -1;
    i2 = -1;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &y_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &ab_emlrtBCI, sp);
    }

    i1 = (int32_T)d - 2;
    i2 = 1191;
  }

  b_iv[0] = i;
  b_iv[1] = i2 - i1;
  iv1[0] = j;
  iv1[1] = condI;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI, sp);
  i = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(sp, b_DiscOutput, i, &s_emlrtRTEI);
  for (i = 0; i < condI; i++) {
    for (i2 = 0; i2 < j; i2++) {
      b_DiscOutput->data[i2 + b_DiscOutput->size[0] * i] =
        DiscOutput->dist_decay[i2 + 1192 * i];
    }
  }

  j = b_DiscOutput->size[1];
  for (i = 0; i < j; i++) {
    condI = b_DiscOutput->size[0];
    for (i2 = 0; i2 < condI; i2++) {
      DiscOutput->dist_decay[i2 + 1192 * ((i1 + i) + 1)] = b_DiscOutput->data[i2
        + b_DiscOutput->size[0] * i];
    }
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    j = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &ab_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &bb_emlrtBCI, sp);
    }

    j = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0;
  if (1.0 > d) {
    condI = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &bb_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &cb_emlrtBCI, sp);
    }

    condI = (int32_T)d;
  }

  d = DiscOutput->num_nodes / 2.0 + 1.0;
  if (d > 1192.0) {
    i = -1;
    i1 = -1;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &cb_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &db_emlrtBCI, sp);
    }

    i = (int32_T)d - 2;
    i1 = 1191;
  }

  d = DiscOutput->num_nodes / 2.0 + 1.0;
  if (d > 1192.0) {
    i2 = -1;
    condJ = -1;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &db_emlrtDCI, sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &eb_emlrtBCI, sp);
    }

    i2 = (int32_T)d - 2;
    condJ = 1191;
  }

  b_iv[0] = i1 - i;
  b_iv[1] = condJ - i2;
  iv1[0] = j;
  iv1[1] = condI;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &g_emlrtECI, sp);
  i1 = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(sp, b_DiscOutput, i1, &t_emlrtRTEI);
  for (i1 = 0; i1 < condI; i1++) {
    for (condJ = 0; condJ < j; condJ++) {
      b_DiscOutput->data[condJ + b_DiscOutput->size[0] * i1] =
        DiscOutput->dist_decay[condJ + 1192 * i1];
    }
  }

  j = b_DiscOutput->size[1];
  for (i1 = 0; i1 < j; i1++) {
    condI = b_DiscOutput->size[0];
    for (condJ = 0; condJ < condI; condJ++) {
      DiscOutput->dist_decay[((i + condJ) + 1192 * ((i2 + i1) + 1)) + 1] =
        b_DiscOutput->data[condJ + b_DiscOutput->size[0] * i1];
    }
  }

  emxFree_real_T(&b_DiscOutput);

  /*  compute orientation based correspondence */
  i = (int32_T)DiscOutput->num_nodes;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, DiscOutput->num_nodes, mxDOUBLE_CLASS,
    (int32_T)DiscOutput->num_nodes, &h_emlrtRTEI, sp);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = (int32_T)(DiscOutput->num_nodes + (1.0 - (((real_T)b_i + 1.0) + 1.0)));
    emlrtForLoopVectorCheckR2012b(((real_T)b_i + 1.0) + 1.0, 1.0,
      DiscOutput->num_nodes, mxDOUBLE_CLASS, i1, &i_emlrtRTEI, sp);
    for (j = 0; j < i1; j++) {
      b_j = (((real_T)b_i + 1.0) + 1.0) + (real_T)j;

      /*  same position but opposite polarity: */
      if (b_j != DiscOutput->num_nodes / 2.0 + ((real_T)b_i + 1.0)) {
        /*  get normalized vector going from node i to node j */
        if (((int32_T)b_j < 1) || ((int32_T)b_j > 1192)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_j, 1, 1192, &lb_emlrtBCI, sp);
        }

        if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > 1192)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, 1192,
            &lb_emlrtBCI, sp);
        }

        vec_i2j[0] = DiscOutput->pos_x[(int32_T)b_j - 1] - DiscOutput->pos_x[b_i];
        if (((int32_T)b_j < 1) || ((int32_T)b_j > 1192)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_j, 1, 1192, &mb_emlrtBCI, sp);
        }

        if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > 1192)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, 1192,
            &mb_emlrtBCI, sp);
        }

        vec_i2j[1] = DiscOutput->pos_y[(int32_T)b_j - 1] - DiscOutput->pos_y[b_i];
        d = b_norm(vec_i2j);
        norm_i2j[0] = vec_i2j[0] / d;
        norm_i2j[1] = vec_i2j[1] / d;

        /*  compute angles between connecting vector and each bown direction */
        d = DiscOutput->dx[b_i];
        vec_i2j[0] = d;
        linearAngCos = DiscOutput->dy[b_i];
        vec_i2j[1] = linearAngCos;
        vecprev_j[0] = DiscOutput->dx[(int32_T)b_j - 1];
        vecprev_j[1] = DiscOutput->dy[(int32_T)b_j - 1];
        distanceTemp = b_norm(norm_i2j);
        alpha_j.re = d * norm_i2j[0] + linearAngCos * norm_i2j[1];
        alpha_j.im = 0.0;
        b_acos(&alpha_j);
        br = b_norm(vec_i2j) * distanceTemp;
        if (alpha_j.im == 0.0) {
          alpha_i.re = alpha_j.re / br;
          alpha_i.im = 0.0;
        } else if (alpha_j.re == 0.0) {
          alpha_i.re = 0.0;
          alpha_i.im = alpha_j.im / br;
        } else {
          alpha_i.re = alpha_j.re / br;
          alpha_i.im = alpha_j.im / br;
        }

        alpha_j.re = vecprev_j[0] * norm_i2j[0] + vecprev_j[1] * norm_i2j[1];
        alpha_j.im = 0.0;
        b_acos(&alpha_j);
        br = b_norm(vecprev_j) * distanceTemp;
        if (alpha_j.im == 0.0) {
          re = alpha_j.re / br;
          br = 0.0;
        } else if (alpha_j.re == 0.0) {
          re = 0.0;
          br = alpha_j.im / br;
        } else {
          re = alpha_j.re / br;
          br = alpha_j.im / br;
        }

        alpha_j.re = re;
        alpha_j.im = br;
        if (muDoubleScalarIsNaN(alpha_i.re) || muDoubleScalarIsNaN(alpha_i.im))
        {
          st.site = &fb_emlrtRSI;
          disp(&st, emlrt_marshallOut(&st, cv), &b_emlrtMCI);
        }

        /*  get the sign of the orientation through the crossproduct */
        /*  sometimes the sign=0 because cp(3)=0, exclude those cases. */
        distanceTemp = muDoubleScalarSign(d * norm_i2j[1] - linearAngCos *
          norm_i2j[0]);
        st.site = &m_emlrtRSI;
        if (muDoubleScalarIsNaN(distanceTemp)) {
          emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI, "MATLAB:nologicalnan",
            "MATLAB:nologicalnan", 0);
        }

        if (distanceTemp != 0.0) {
          alpha_i.re *= distanceTemp;
          alpha_i.im *= distanceTemp;
        }

        distanceTemp = muDoubleScalarSign(vecprev_j[0] * norm_i2j[1] -
          vecprev_j[1] * norm_i2j[0]);
        st.site = &n_emlrtRSI;
        if (muDoubleScalarIsNaN(distanceTemp)) {
          emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI, "MATLAB:nologicalnan",
            "MATLAB:nologicalnan", 0);
        }

        if (distanceTemp != 0.0) {
          alpha_j.re = distanceTemp * re;
          alpha_j.im = distanceTemp * br;
        }

        /*  above node i */
        if ((alpha_i.re > -1.5707963267948966) && (alpha_i.re <
             1.5707963267948966)) {
          /*  and norm of j is facing away from i */
          if ((alpha_j.re >= -1.5707963267948966) && (alpha_j.re <=
               1.5707963267948966)) {
            DiscOutput->agreement[b_i + 1192 * ((int32_T)b_j - 1)] =
              DiscParams_bown_params[3];

            /*  and norm of j is facing i */
          } else {
            DiscOutput->agreement[b_i + 1192 * ((int32_T)b_j - 1)] =
              DiscParams_bown_params[2];
          }

          /*  if alligned */
        } else if (muDoubleScalarHypot(alpha_i.re, alpha_i.im) ==
                   1.5707963267948966) {
          /*  collinear with same polarity */
          if ((alpha_i.re == alpha_j.re) && (alpha_i.im == alpha_j.im)) {
            DiscOutput->agreement[b_i + 1192 * ((int32_T)b_j - 1)] =
              DiscParams_bown_params[0];

            /*  collinear with opposite polarity */
          } else if (((alpha_i.re != alpha_j.re) || (alpha_i.im != alpha_j.im)) &&
                     (muDoubleScalarHypot(alpha_j.re, alpha_j.im) ==
                      1.5707963267948966)) {
            DiscOutput->agreement[b_i + 1192 * ((int32_T)b_j - 1)] =
              DiscParams_bown_params[1];

            /*  I do not feel comfortable with this part in the original code */
          } else {
            DiscOutput->agreement[b_i + 1192 * ((int32_T)b_j - 1)] =
              DiscParams_bown_params[6];
          }

          /*  below node i */
        } else {
          /*  and norm of j is facing i */
          if ((alpha_j.re > -1.5707963267948966) && (alpha_j.re <
               1.5707963267948966)) {
            DiscOutput->agreement[b_i + 1192 * ((int32_T)b_j - 1)] =
              DiscParams_bown_params[4];

            /*  and norm of j is facing away from i */
          } else {
            DiscOutput->agreement[b_i + 1192 * ((int32_T)b_j - 1)] =
              DiscParams_bown_params[5];
          }
        }

        /*  fill out reflection of the matrix for later use */
        DiscOutput->agreement[((int32_T)b_j + 1192 * b_i) - 1] =
          DiscOutput->agreement[b_i + 1192 * ((int32_T)b_j - 1)];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &r, 2, &u_emlrtRTEI, true);
  emxInit_real_T(sp, &r1, 2, &u_emlrtRTEI, true);

  /*  compute luminance based agreements: same polarity */
  /*  that is the luminance of the region towards which the arrow is pointing */
  st.site = &o_emlrtRSI;
  repmat(&st, DiscOutput->color_norm, DiscOutput->num_nodes, r);
  st.site = &o_emlrtRSI;
  b_repmat(&st, DiscOutput->color_norm, DiscOutput->num_nodes, r1);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])r->size, *(int32_T (*)[2])r1->size,
    &h_emlrtECI, sp);

  /*  compute luminance based agreements: opposite polarity */
  /*  that is the luminance of the region from which the arrow is pointing */
  for (i = 0; i < 1192; i++) {
    for (i1 = 0; i1 < 1192; i1++) {
      i2 = i1 + 1192 * i;
      DiscOutput->agreement[i2 + 1420864] = (r->data[i2] == r1->data[i2]);
    }

    c_DiscOutput[i] = DiscOutput->color_norm[i] + DiscOutput->color_contrast[i];
  }

  st.site = &p_emlrtRSI;
  repmat(&st, c_DiscOutput, DiscOutput->num_nodes, r);
  for (i = 0; i < 1192; i++) {
    c_DiscOutput[i] = DiscOutput->color_norm[i] + DiscOutput->color_contrast[i];
  }

  st.site = &p_emlrtRSI;
  b_repmat(&st, c_DiscOutput, DiscOutput->num_nodes, r1);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])r->size, *(int32_T (*)[2])r1->size,
    &i_emlrtECI, sp);
  for (i = 0; i < 1192; i++) {
    for (i1 = 0; i1 < 1192; i1++) {
      i2 = i1 + 1192 * i;
      DiscOutput->agreement[i2 + 2841728] = (r->data[i2] == r1->data[i2]);
    }
  }

  /*  compute luminance based agreements: contrast */
  st.site = &q_emlrtRSI;
  repmat(&st, DiscOutput->color_contrast, DiscOutput->num_nodes, r);
  st.site = &q_emlrtRSI;
  b_repmat(&st, DiscOutput->color_contrast, DiscOutput->num_nodes, r1);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])r->size, *(int32_T (*)[2])r1->size,
    &j_emlrtECI, sp);
  for (i = 0; i < 1192; i++) {
    for (i1 = 0; i1 < 1192; i1++) {
      i2 = i1 + 1192 * i;
      DiscOutput->agreement[i2 + 4262592] = (r->data[i2] == r1->data[i2]);
    }
  }

  emxFree_real_T(&r1);
  emxFree_real_T(&r);

  /*  compute neighbor nodes agreements based on colinearity */
  /*  that is the immediate neighbor with angle difference less than linearAngTh */
  /*  the agreement is already computed by NieghboringPointsFinder */
  /*  This is used for the augmented model */
  linearAngCos = muDoubleScalarCos(DiscParams_linearAngTh / 180.0 *
    3.1415926535897931);
  i = (int32_T)DiscParams_Knear;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, DiscParams_Knear, mxDOUBLE_CLASS,
    (int32_T)DiscParams_Knear, &j_emlrtRTEI, sp);
  for (iK = 0; iK < i; iK++) {
    i1 = iK + 1;
    if ((i1 < 1) || (i1 > 801)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 801, &fb_emlrtBCI, sp);
    }

    i1 = (int32_T)DiscOutput->num_nodes;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, DiscOutput->num_nodes,
      mxDOUBLE_CLASS, (int32_T)DiscOutput->num_nodes, &k_emlrtRTEI, sp);
    for (b_i = 0; b_i < i1; b_i++) {
      i2 = b_i + 1;
      if ((i2 < 1) || (i2 > 1192)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 1192, &gb_emlrtBCI, sp);
      }

      /*  same position but opposite polarity: */
      if ((DiscOutput->NB[iK].NBind[b_i] != (real_T)b_i + 1.0) &&
          (DiscOutput->NB[iK].NBind[b_i] != ((real_T)b_i + 1.0) +
           DiscOutput->num_nodes / 2.0) && (DiscOutput->NB[iK].NBind[b_i] !=
           ((real_T)b_i + 1.0) - DiscOutput->num_nodes / 2.0)) {
        d = DiscOutput->NB[iK].NBind[b_i];
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &eb_emlrtDCI, sp);
        }

        if (((int32_T)d < 1) || ((int32_T)d > 1192)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 1192, &hb_emlrtBCI, sp);
        }

        /*  get normalized vector going from node i to node j */
        j = (int32_T)DiscOutput->NB[iK].NBind[b_i] - 1;
        vec_i2j[0] = DiscOutput->pos_x[j] - DiscOutput->pos_x[b_i];
        vec_i2j[1] = DiscOutput->pos_y[j] - DiscOutput->pos_y[b_i];
        d = b_norm(vec_i2j);
        norm_i2j[0] = vec_i2j[0] / d;
        norm_i2j[1] = vec_i2j[1] / d;

        /*  compute angles between connecting vector and each bown direction         */
        vec_i2j[0] = DiscOutput->dx[b_i];
        vec_i2j[1] = DiscOutput->dy[b_i];
        vecprev_j[0] = DiscOutput->dx[j];
        vecprev_j[1] = DiscOutput->dy[j];
        distanceTemp = b_norm(norm_i2j);
        alpha_j.re = vec_i2j[0] * norm_i2j[0] + vec_i2j[1] * norm_i2j[1];
        alpha_j.im = 0.0;
        b_acos(&alpha_j);
        br = b_norm(vec_i2j) * distanceTemp;
        if (alpha_j.im == 0.0) {
          alpha_i.re = alpha_j.re / br;
          alpha_i.im = 0.0;
        } else if (alpha_j.re == 0.0) {
          alpha_i.re = 0.0;
          alpha_i.im = alpha_j.im / br;
        } else {
          alpha_i.re = alpha_j.re / br;
          alpha_i.im = alpha_j.im / br;
        }

        alpha_j.re = vecprev_j[0] * norm_i2j[0] + vecprev_j[1] * norm_i2j[1];
        alpha_j.im = 0.0;
        b_acos(&alpha_j);
        br = b_norm(vecprev_j) * distanceTemp;
        if (alpha_j.im == 0.0) {
          re = alpha_j.re / br;
          br = 0.0;
        } else if (alpha_j.re == 0.0) {
          re = 0.0;
          br = alpha_j.im / br;
        } else {
          re = alpha_j.re / br;
          br = alpha_j.im / br;
        }

        alpha_j.re = re;
        alpha_j.im = br;

        /* %%%%% */
        if (muDoubleScalarIsNaN(alpha_i.re) || muDoubleScalarIsNaN(alpha_i.im))
        {
          st.site = &eb_emlrtRSI;
          disp(&st, emlrt_marshallOut(&st, cv), &c_emlrtMCI);
        }

        /*  get the sign of the orientation through the crossproduct */
        /*  sometimes the sign=0 because cp(3)=0, exclude those cases. */
        distanceTemp = muDoubleScalarSign(vec_i2j[0] * norm_i2j[1] - vec_i2j[1] *
          norm_i2j[0]);
        st.site = &r_emlrtRSI;
        if (muDoubleScalarIsNaN(distanceTemp)) {
          emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI, "MATLAB:nologicalnan",
            "MATLAB:nologicalnan", 0);
        }

        if (distanceTemp != 0.0) {
          alpha_i.re *= distanceTemp;
          alpha_i.im *= distanceTemp;
        }

        distanceTemp = muDoubleScalarSign(vecprev_j[0] * norm_i2j[1] -
          vecprev_j[1] * norm_i2j[0]);
        st.site = &s_emlrtRSI;
        if (muDoubleScalarIsNaN(distanceTemp)) {
          emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI, "MATLAB:nologicalnan",
            "MATLAB:nologicalnan", 0);
        }

        if (distanceTemp != 0.0) {
          alpha_j.re = distanceTemp * re;
          alpha_j.im = distanceTemp * br;
        }

        /*  above node i */
        if ((alpha_i.re > 0.0) && (alpha_i.re < 3.1415926535897931)) {
          condI = 1;
        } else if ((alpha_i.re < 0.0) && (alpha_i.re > -3.1415926535897931)) {
          condI = -1;
        } else {
          condI = 0;
        }

        if ((alpha_j.re > 0.0) && (alpha_j.re < 3.1415926535897931)) {
          condJ = 1;
        } else if ((alpha_j.re < 0.0) && (alpha_j.re > -3.1415926535897931)) {
          condJ = -1;
        } else {
          condJ = 0;
        }

        if (condI == 1) {
          if (condJ == 1) {
            b_sin(&alpha_i);
            b_sin(&alpha_j);
            DiscOutput->agreement[(b_i + 1192 * ((int32_T)DiscOutput->NB[iK].
              NBind[b_i] - 1)) + 5683456] = ((muDoubleScalarHypot(alpha_i.re,
              alpha_i.im) >= linearAngCos) && (muDoubleScalarHypot(alpha_j.re,
              alpha_j.im) >= linearAngCos));
          } else {
            DiscOutput->agreement[(b_i + 1192 * ((int32_T)DiscOutput->NB[iK].
              NBind[b_i] - 1)) + 5683456] = 0.0;
          }
        } else if (condI == -1) {
          if (condJ == 1) {
            DiscOutput->agreement[(b_i + 1192 * ((int32_T)DiscOutput->NB[iK].
              NBind[b_i] - 1)) + 5683456] = 0.0;
          } else if (condJ == -1) {
            b_sin(&alpha_i);
            b_sin(&alpha_j);
            DiscOutput->agreement[(b_i + 1192 * ((int32_T)DiscOutput->NB[iK].
              NBind[b_i] - 1)) + 5683456] = ((muDoubleScalarHypot(alpha_i.re,
              alpha_i.im) >= linearAngCos) && (muDoubleScalarHypot(alpha_j.re,
              alpha_j.im) >= linearAngCos));
          } else {
            DiscOutput->agreement[(b_i + 1192 * ((int32_T)DiscOutput->NB[iK].
              NBind[b_i] - 1)) + 5683456] = 0.0;
          }
        } else {
          DiscOutput->agreement[(b_i + 1192 * j) + 5683456] = 0.0;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (disc_compute_agreement.c) */
