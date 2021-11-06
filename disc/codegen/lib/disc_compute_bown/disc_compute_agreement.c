/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: disc_compute_agreement.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

/* Include Files */
#include "disc_compute_agreement.h"
#include "acos.h"
#include "disc_compute_bown_emxutil.h"
#include "disc_compute_bown_rtwutil.h"
#include "disc_compute_bown_types.h"
#include "norm.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include <math.h>

/* Function Definitions */
/*
 * DISC_COMPUTE_AGREEMENT - computes if nodes are in agreement
 *
 *  Synopsis
 *    [ DiscOutput ] = disc_compute_agreement( DiscOutput,DiscParams )
 *
 *  Description
 *    Based on the original DISC code by Naoki Kogo extended for the use
 *    cases and theories behind DISC2.
 *
 *  Inputs ([]s are optional)
 *    (struct)    DiscOutput
 *
 *  Outputs ([]s are optional)
 *    (struct)    DiscOutput
 *    (struct)    DiscParams
 *
 *  Examples
 *    <Example Code>
 *
 *  See also
 *    disc_main, disc_params_default, disc_compute_bown
 *
 *  Requirements
 *    --
 *
 *  Authors
 *    Vicky Froyen <vicky.froyen@gmail.com>
 *    Naoki Kogo <naoki.kogo@gmail.com>
 *
 *  License
 *    DISC2 is free software accompanying our paper:
 *    "Emergence of border-ownership by large-scale consistency and
 *    long-range interactions: Neuro-computational model to reflect
 *    global configurations"
 *    Copyright (C) 2020 Vicky Froyen, Naoki Kogo
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License along
 *    with this program; if not, write to the Free Software Foundation, Inc.,
 *    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *  Changes
 *    see <git log>
 * Arguments    : struct0_T *DiscOutput
 *                double DiscParams_space_constant
 *                const double DiscParams_bown_params[7]
 *                double DiscParams_Knear
 *                double DiscParams_linearAngTh
 * Return Type  : void
 */
void disc_compute_agreement(struct0_T *DiscOutput, double
  DiscParams_space_constant, const double DiscParams_bown_params[7], double
  DiscParams_Knear, double DiscParams_linearAngTh)
{
  emxArray_real_T *b_DiscOutput;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  creal_T alpha_i;
  creal_T alpha_j;
  double c_DiscOutput[1192];
  double d_DiscOutput[1192];
  double norm_i2j[2];
  double vec_i2j[2];
  double vecprev_j[2];
  double a;
  double distanceTemp;
  double linearAngCos;
  double re;
  int b_i;
  int condI;
  int condJ;
  int i;
  int i1;
  int iK;
  int j;
  boolean_T guard1 = false;

  /* \codegen */
  /*  compute pairwise distances for graded interaction */
  i = (int)(DiscOutput->num_nodes / 2.0);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = (int)(DiscOutput->num_nodes / 2.0 + (1.0 - (((double)b_i + 1.0) + 1.0)));
    for (j = 0; j < i1; j++) {
      linearAngCos = (((double)b_i + 1.0) + 1.0) + (double)j;

      /*  compute the graded interaction -- the further away the less */
      /*  influence two nodes with assert. */
      distanceTemp = DiscOutput->pos_x[b_i] - DiscOutput->pos_x[(int)
        linearAngCos - 1];
      a = DiscOutput->pos_y[b_i] - DiscOutput->pos_y[(int)linearAngCos - 1];
      distanceTemp = sqrt(distanceTemp * distanceTemp + a * a);
      condJ = b_i + 1192 * ((int)linearAngCos - 1);
      DiscOutput->distance[condJ] = distanceTemp;
      DiscOutput->dist_decay[condJ] = exp(-distanceTemp /
        DiscParams_space_constant);

      /*  reflect over diagonal to grab the other side */
      iK = ((int)linearAngCos + 1192 * b_i) - 1;
      DiscOutput->distance[iK] = DiscOutput->distance[condJ];
      DiscOutput->dist_decay[iK] = DiscOutput->dist_decay[condJ];
    }
  }

  /*  the full matrix contains four blocks of the same configuration: */
  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    j = 0;
  } else {
    j = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    condI = 0;
  } else {
    condI = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (distanceTemp + 1.0 > 1192.0) {
    i = 1;
  } else {
    i = (int)(distanceTemp + 1.0);
  }

  emxInit_real_T(&b_DiscOutput, 2);
  i1 = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(b_DiscOutput, i1);
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
      DiscOutput->distance[((i + condJ) + 1192 * i1) - 1] = b_DiscOutput->
        data[condJ + b_DiscOutput->size[0] * i1];
    }
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    j = 0;
  } else {
    j = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    condI = 0;
  } else {
    condI = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (distanceTemp + 1.0 > 1192.0) {
    i = 1;
  } else {
    i = (int)(distanceTemp + 1.0);
  }

  i1 = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(b_DiscOutput, i1);
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
      DiscOutput->distance[condJ + 1192 * ((i + i1) - 1)] = b_DiscOutput->
        data[condJ + b_DiscOutput->size[0] * i1];
    }
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    j = 0;
  } else {
    j = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    condI = 0;
  } else {
    condI = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0 + 1.0;
  if (distanceTemp > 1192.0) {
    i = 1;
  } else {
    i = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0 + 1.0;
  if (distanceTemp > 1192.0) {
    i1 = 1;
  } else {
    i1 = (int)distanceTemp;
  }

  condJ = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(b_DiscOutput, condJ);
  for (condJ = 0; condJ < condI; condJ++) {
    for (iK = 0; iK < j; iK++) {
      b_DiscOutput->data[iK + b_DiscOutput->size[0] * condJ] =
        DiscOutput->distance[iK + 1192 * condJ];
    }
  }

  j = b_DiscOutput->size[1];
  for (condJ = 0; condJ < j; condJ++) {
    condI = b_DiscOutput->size[0];
    for (iK = 0; iK < condI; iK++) {
      DiscOutput->distance[((i + iK) + 1192 * ((i1 + condJ) - 1)) - 1] =
        b_DiscOutput->data[iK + b_DiscOutput->size[0] * condJ];
    }
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    j = 0;
  } else {
    j = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    condI = 0;
  } else {
    condI = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0 + 1.0;
  if (distanceTemp > 1192.0) {
    i = 1;
  } else {
    i = (int)distanceTemp;
  }

  i1 = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(b_DiscOutput, i1);
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
      DiscOutput->dist_decay[((i + condJ) + 1192 * i1) - 1] = b_DiscOutput->
        data[condJ + b_DiscOutput->size[0] * i1];
    }
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    j = 0;
  } else {
    j = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    condI = 0;
  } else {
    condI = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0 + 1.0;
  if (distanceTemp > 1192.0) {
    i = 1;
  } else {
    i = (int)distanceTemp;
  }

  i1 = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(b_DiscOutput, i1);
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
      DiscOutput->dist_decay[condJ + 1192 * ((i + i1) - 1)] = b_DiscOutput->
        data[condJ + b_DiscOutput->size[0] * i1];
    }
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    j = 0;
  } else {
    j = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0;
  if (1.0 > distanceTemp) {
    condI = 0;
  } else {
    condI = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0 + 1.0;
  if (distanceTemp > 1192.0) {
    i = 1;
  } else {
    i = (int)distanceTemp;
  }

  distanceTemp = DiscOutput->num_nodes / 2.0 + 1.0;
  if (distanceTemp > 1192.0) {
    i1 = 1;
  } else {
    i1 = (int)distanceTemp;
  }

  condJ = b_DiscOutput->size[0] * b_DiscOutput->size[1];
  b_DiscOutput->size[0] = j;
  b_DiscOutput->size[1] = condI;
  emxEnsureCapacity_real_T(b_DiscOutput, condJ);
  for (condJ = 0; condJ < condI; condJ++) {
    for (iK = 0; iK < j; iK++) {
      b_DiscOutput->data[iK + b_DiscOutput->size[0] * condJ] =
        DiscOutput->dist_decay[iK + 1192 * condJ];
    }
  }

  j = b_DiscOutput->size[1];
  for (condJ = 0; condJ < j; condJ++) {
    condI = b_DiscOutput->size[0];
    for (iK = 0; iK < condI; iK++) {
      DiscOutput->dist_decay[((i + iK) + 1192 * ((i1 + condJ) - 1)) - 1] =
        b_DiscOutput->data[iK + b_DiscOutput->size[0] * condJ];
    }
  }

  emxFree_real_T(&b_DiscOutput);

  /*  compute orientation based correspondence */
  i = (int)DiscOutput->num_nodes;
  for (b_i = 0; b_i < i; b_i++) {
    i1 = (int)(DiscOutput->num_nodes + (1.0 - (((double)b_i + 1.0) + 1.0)));
    for (j = 0; j < i1; j++) {
      linearAngCos = (((double)b_i + 1.0) + 1.0) + (double)j;

      /*  same position but opposite polarity: */
      if (linearAngCos != DiscOutput->num_nodes / 2.0 + ((double)b_i + 1.0)) {
        /*  get normalized vector going from node i to node j */
        vec_i2j[0] = DiscOutput->pos_x[(int)linearAngCos - 1] -
          DiscOutput->pos_x[b_i];
        vec_i2j[1] = DiscOutput->pos_y[(int)linearAngCos - 1] -
          DiscOutput->pos_y[b_i];
        distanceTemp = b_norm(vec_i2j);
        norm_i2j[0] = vec_i2j[0] / distanceTemp;
        norm_i2j[1] = vec_i2j[1] / distanceTemp;

        /*  compute angles between connecting vector and each bown direction */
        vec_i2j[0] = DiscOutput->dx[b_i];
        vec_i2j[1] = DiscOutput->dy[b_i];
        vecprev_j[0] = DiscOutput->dx[(int)linearAngCos - 1];
        vecprev_j[1] = DiscOutput->dy[(int)linearAngCos - 1];
        distanceTemp = b_norm(norm_i2j);
        alpha_j.re = vec_i2j[0] * norm_i2j[0] + vec_i2j[1] * norm_i2j[1];
        alpha_j.im = 0.0;
        b_acos(&alpha_j);
        a = b_norm(vec_i2j) * distanceTemp;
        if (alpha_j.im == 0.0) {
          alpha_i.re = alpha_j.re / a;
          alpha_i.im = 0.0;
        } else if (alpha_j.re == 0.0) {
          alpha_i.re = 0.0;
          alpha_i.im = alpha_j.im / a;
        } else {
          alpha_i.re = alpha_j.re / a;
          alpha_i.im = alpha_j.im / a;
        }

        alpha_j.re = vecprev_j[0] * norm_i2j[0] + vecprev_j[1] * norm_i2j[1];
        alpha_j.im = 0.0;
        b_acos(&alpha_j);
        a = b_norm(vecprev_j) * distanceTemp;
        if (alpha_j.im == 0.0) {
          re = alpha_j.re / a;
          distanceTemp = 0.0;
        } else if (alpha_j.re == 0.0) {
          re = 0.0;
          distanceTemp = alpha_j.im / a;
        } else {
          re = alpha_j.re / a;
          distanceTemp = alpha_j.im / a;
        }

        alpha_j.re = re;
        alpha_j.im = distanceTemp;
        a = vec_i2j[0] * norm_i2j[1] - vec_i2j[1] * norm_i2j[0];
        guard1 = false;
        if (a < 0.0) {
          a = -1.0;
          guard1 = true;
        } else if (a > 0.0) {
          a = 1.0;
          guard1 = true;
        } else {
          if (!(a == 0.0)) {
            guard1 = true;
          }
        }

        if (guard1) {
          alpha_i.re *= a;
          alpha_i.im *= a;
        }

        a = vecprev_j[0] * norm_i2j[1] - vecprev_j[1] * norm_i2j[0];
        guard1 = false;
        if (a < 0.0) {
          a = -1.0;
          guard1 = true;
        } else if (a > 0.0) {
          a = 1.0;
          guard1 = true;
        } else {
          if (!(a == 0.0)) {
            guard1 = true;
          }
        }

        if (guard1) {
          alpha_j.re = a * re;
          alpha_j.im = a * distanceTemp;
        }

        /*  above node i */
        if ((alpha_i.re > -1.5707963267948966) && (alpha_i.re <
             1.5707963267948966)) {
          /*  and norm of j is facing away from i */
          if ((alpha_j.re >= -1.5707963267948966) && (alpha_j.re <=
               1.5707963267948966)) {
            DiscOutput->agreement[b_i + 1192 * ((int)linearAngCos - 1)] =
              DiscParams_bown_params[3];

            /*  and norm of j is facing i */
          } else {
            DiscOutput->agreement[b_i + 1192 * ((int)linearAngCos - 1)] =
              DiscParams_bown_params[2];
          }

          /*  if alligned */
        } else if (rt_hypotd_snf(alpha_i.re, alpha_i.im) == 1.5707963267948966)
        {
          /*  collinear with same polarity */
          if ((alpha_i.re == alpha_j.re) && (alpha_i.im == alpha_j.im)) {
            DiscOutput->agreement[b_i + 1192 * ((int)linearAngCos - 1)] =
              DiscParams_bown_params[0];

            /*  collinear with opposite polarity */
          } else if (((alpha_i.re != alpha_j.re) || (alpha_i.im != alpha_j.im)) &&
                     (rt_hypotd_snf(alpha_j.re, alpha_j.im) ==
                      1.5707963267948966)) {
            DiscOutput->agreement[b_i + 1192 * ((int)linearAngCos - 1)] =
              DiscParams_bown_params[1];

            /*  I do not feel comfortable with this part in the original code */
          } else {
            DiscOutput->agreement[b_i + 1192 * ((int)linearAngCos - 1)] =
              DiscParams_bown_params[6];
          }

          /*  below node i */
        } else {
          /*  and norm of j is facing i */
          if ((alpha_j.re > -1.5707963267948966) && (alpha_j.re <
               1.5707963267948966)) {
            DiscOutput->agreement[b_i + 1192 * ((int)linearAngCos - 1)] =
              DiscParams_bown_params[4];

            /*  and norm of j is facing away from i */
          } else {
            DiscOutput->agreement[b_i + 1192 * ((int)linearAngCos - 1)] =
              DiscParams_bown_params[5];
          }
        }

        /*  fill out reflection of the matrix for later use */
        DiscOutput->agreement[((int)linearAngCos + 1192 * b_i) - 1] =
          DiscOutput->agreement[b_i + 1192 * ((int)linearAngCos - 1)];
      }
    }
  }

  emxInit_real_T(&r, 2);
  emxInit_real_T(&r1, 2);

  /*  compute luminance based agreements: same polarity */
  /*  that is the luminance of the region towards which the arrow is pointing */
  repmat(DiscOutput->color_norm, DiscOutput->num_nodes, r);
  b_repmat(DiscOutput->color_norm, DiscOutput->num_nodes, r1);

  /*  compute luminance based agreements: opposite polarity */
  /*  that is the luminance of the region from which the arrow is pointing */
  for (i = 0; i < 1192; i++) {
    for (i1 = 0; i1 < 1192; i1++) {
      condJ = i1 + 1192 * i;
      DiscOutput->agreement[condJ + 1420864] = (r->data[condJ] == r1->data[condJ]);
    }

    distanceTemp = DiscOutput->color_norm[i] + DiscOutput->color_contrast[i];
    c_DiscOutput[i] = distanceTemp;
    d_DiscOutput[i] = distanceTemp;
  }

  repmat(c_DiscOutput, DiscOutput->num_nodes, r);
  b_repmat(d_DiscOutput, DiscOutput->num_nodes, r1);
  for (i = 0; i < 1192; i++) {
    for (i1 = 0; i1 < 1192; i1++) {
      condJ = i1 + 1192 * i;
      DiscOutput->agreement[condJ + 2841728] = (r->data[condJ] == r1->data[condJ]);
    }
  }

  /*  compute luminance based agreements: contrast */
  repmat(DiscOutput->color_contrast, DiscOutput->num_nodes, r);
  b_repmat(DiscOutput->color_contrast, DiscOutput->num_nodes, r1);
  for (i = 0; i < 1192; i++) {
    for (i1 = 0; i1 < 1192; i1++) {
      condJ = i1 + 1192 * i;
      DiscOutput->agreement[condJ + 4262592] = (r->data[condJ] == r1->data[condJ]);
    }
  }

  emxFree_real_T(&r1);
  emxFree_real_T(&r);

  /*  compute neighbor nodes agreements based on colinearity */
  /*  that is the immediate neighbor with angle difference less than linearAngTh */
  /*  the agreement is already computed by NieghboringPointsFinder */
  /*  This is used for the augmented model */
  linearAngCos = cos(DiscParams_linearAngTh / 180.0 * 3.1415926535897931);
  i = (int)DiscParams_Knear;
  for (iK = 0; iK < i; iK++) {
    i1 = (int)DiscOutput->num_nodes;
    for (b_i = 0; b_i < i1; b_i++) {
      /*  same position but opposite polarity: */
      if ((DiscOutput->NB[iK].NBind[b_i] != (double)b_i + 1.0) &&
          (DiscOutput->NB[iK].NBind[b_i] != ((double)b_i + 1.0) +
           DiscOutput->num_nodes / 2.0) && (DiscOutput->NB[iK].NBind[b_i] !=
           ((double)b_i + 1.0) - DiscOutput->num_nodes / 2.0)) {
        /*  get normalized vector going from node i to node j */
        j = (int)DiscOutput->NB[iK].NBind[b_i] - 1;
        vec_i2j[0] = DiscOutput->pos_x[j] - DiscOutput->pos_x[b_i];
        vec_i2j[1] = DiscOutput->pos_y[j] - DiscOutput->pos_y[b_i];
        distanceTemp = b_norm(vec_i2j);
        norm_i2j[0] = vec_i2j[0] / distanceTemp;
        norm_i2j[1] = vec_i2j[1] / distanceTemp;

        /*  compute angles between connecting vector and each bown direction         */
        vec_i2j[0] = DiscOutput->dx[b_i];
        vec_i2j[1] = DiscOutput->dy[b_i];
        vecprev_j[0] = DiscOutput->dx[j];
        vecprev_j[1] = DiscOutput->dy[j];
        distanceTemp = b_norm(norm_i2j);
        alpha_j.re = vec_i2j[0] * norm_i2j[0] + vec_i2j[1] * norm_i2j[1];
        alpha_j.im = 0.0;
        b_acos(&alpha_j);
        a = b_norm(vec_i2j) * distanceTemp;
        if (alpha_j.im == 0.0) {
          alpha_i.re = alpha_j.re / a;
          alpha_i.im = 0.0;
        } else if (alpha_j.re == 0.0) {
          alpha_i.re = 0.0;
          alpha_i.im = alpha_j.im / a;
        } else {
          alpha_i.re = alpha_j.re / a;
          alpha_i.im = alpha_j.im / a;
        }

        alpha_j.re = vecprev_j[0] * norm_i2j[0] + vecprev_j[1] * norm_i2j[1];
        alpha_j.im = 0.0;
        b_acos(&alpha_j);
        a = b_norm(vecprev_j) * distanceTemp;
        if (alpha_j.im == 0.0) {
          re = alpha_j.re / a;
          distanceTemp = 0.0;
        } else if (alpha_j.re == 0.0) {
          re = 0.0;
          distanceTemp = alpha_j.im / a;
        } else {
          re = alpha_j.re / a;
          distanceTemp = alpha_j.im / a;
        }

        alpha_j.re = re;
        alpha_j.im = distanceTemp;

        /* %%%%% */
        a = vec_i2j[0] * norm_i2j[1] - vec_i2j[1] * norm_i2j[0];
        guard1 = false;
        if (a < 0.0) {
          a = -1.0;
          guard1 = true;
        } else if (a > 0.0) {
          a = 1.0;
          guard1 = true;
        } else {
          if (!(a == 0.0)) {
            guard1 = true;
          }
        }

        if (guard1) {
          alpha_i.re *= a;
          alpha_i.im *= a;
        }

        a = vecprev_j[0] * norm_i2j[1] - vecprev_j[1] * norm_i2j[0];
        guard1 = false;
        if (a < 0.0) {
          a = -1.0;
          guard1 = true;
        } else if (a > 0.0) {
          a = 1.0;
          guard1 = true;
        } else {
          if (!(a == 0.0)) {
            guard1 = true;
          }
        }

        if (guard1) {
          alpha_j.re = a * re;
          alpha_j.im = a * distanceTemp;
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
            DiscOutput->agreement[(b_i + 1192 * ((int)DiscOutput->NB[iK]
              .NBind[b_i] - 1)) + 5683456] = ((rt_hypotd_snf(alpha_i.re,
              alpha_i.im) >= linearAngCos) && (rt_hypotd_snf(alpha_j.re,
              alpha_j.im) >= linearAngCos));
          } else {
            DiscOutput->agreement[(b_i + 1192 * ((int)DiscOutput->NB[iK]
              .NBind[b_i] - 1)) + 5683456] = 0.0;
          }
        } else if (condI == -1) {
          if (condJ == 1) {
            DiscOutput->agreement[(b_i + 1192 * ((int)DiscOutput->NB[iK]
              .NBind[b_i] - 1)) + 5683456] = 0.0;
          } else if (condJ == -1) {
            b_sin(&alpha_i);
            b_sin(&alpha_j);
            DiscOutput->agreement[(b_i + 1192 * ((int)DiscOutput->NB[iK]
              .NBind[b_i] - 1)) + 5683456] = ((rt_hypotd_snf(alpha_i.re,
              alpha_i.im) >= linearAngCos) && (rt_hypotd_snf(alpha_j.re,
              alpha_j.im) >= linearAngCos));
          } else {
            DiscOutput->agreement[(b_i + 1192 * ((int)DiscOutput->NB[iK]
              .NBind[b_i] - 1)) + 5683456] = 0.0;
          }
        } else {
          DiscOutput->agreement[(b_i + 1192 * j) + 5683456] = 0.0;
        }
      }
    }
  }
}

/*
 * File trailer for disc_compute_agreement.c
 *
 * [EOF]
 */
