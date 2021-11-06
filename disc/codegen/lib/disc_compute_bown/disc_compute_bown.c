/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: disc_compute_bown.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

/* Include Files */
#include "disc_compute_bown.h"
#include "disc_compute_agreement.h"
#include "disc_compute_bown_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Function Definitions */
/*
 * DISC_COMPUTE_BOWN - core of the DISC model
 *
 *  Synopsis
 *    [ DiscOutput ] = disc_compute_bown(DiscOutput,DiscParams)
 *
 *  Description
 *    First this code will compute correspondencies between different BOWN
 *    nodes to decide if they will interact with eachother or not. Then based
 *    on this correspondence/agreement matrix it will start propagating BOWN
 *    signals throughout the image until convergence is reached.
 *
 *  Inputs ([]s are optional)
 *    (struct) DiscOutput
 *    (struct) DiscParams
 *
 *  Outputs ([]s are optional)
 *    (struct) DiscOutput
 *
 *  Examples
 *    <Example Code>
 *
 *  See also
 *    disc_main
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
 *                const struct2_T *DiscParams
 * Return Type  : void
 */
void disc_compute_bown(struct0_T *DiscOutput, const struct2_T *DiscParams)
{
  static double agreement_GBL[1420864];
  static double agreement_LCL[1420864];
  double tmp_data[2384];
  double c_DiscOutput[1192];
  double d_DiscOutput[1192];
  double b_DiscOutput;
  double d;
  double d1;
  double nrep;
  int DiscOutput_size[2];
  int tmp_size[2];
  int b_nrep;
  int i;
  int j;
  int k;
  int xoffset;
  boolean_T exitg1;

  /* \codegen */
  /*  compute if bown nodes are in agreement */
  printf("%s\n",
         ">> STEP 1: Computing Agreement/Correspondence matrix between BOWN signals ...");
  fflush(stdout);
  disc_compute_agreement(DiscOutput, DiscParams->space_constant,
    DiscParams->bown_params, DiscParams->Knear, DiscParams->linearAngTh);

  /* %%local */
  /* agreement: less than distLCL, distance decay, owner side color consistency, colinearity */
  for (i = 0; i < 1192; i++) {
    for (j = 0; j < 1192; j++) {
      xoffset = j + 1192 * i;
      agreement_LCL[xoffset] = (double)(DiscOutput->distance[xoffset] <=
        DiscParams->distLCL) * DiscOutput->dist_decay[xoffset] *
        DiscOutput->agreement[xoffset + 1420864] * DiscOutput->agreement[xoffset
        + 5683456];
    }
  }

  /* %%global */
  /*  combine different agreement features as set by the user in */
  /*  DiscParams.agreement_combo with the distance decay matrix. */
  for (j = 0; j < 1420864; j++) {
    agreement_GBL[j] = DiscOutput->agreement[(j % 1192 + 1192 * (j / 1192 % 1192))
      + 1420864 * ((int)DiscParams->agreement_combo[j / 1420864] - 1)];
  }

  for (k = 0; k < 2; k++) {
    xoffset = (k + 1) * 1420864;
    for (j = 0; j < 1420864; j++) {
      i = xoffset + j;
      agreement_GBL[j] *= DiscOutput->agreement[(i % 1192 + 1192 * (i / 1192 %
        1192)) + 1420864 * ((int)DiscParams->agreement_combo[i / 1420864] - 1)];
    }
  }

  for (i = 0; i < 1420864; i++) {
    agreement_GBL[i] *= DiscOutput->dist_decay[i];
  }

  /*  set the initial bown (also the current bown) */
  printf("%s\n", ">> DONE");
  fflush(stdout);

  /*  propagate the bown signals based on the agreement matrix */
  /*  save the current bown as the initial one in the timecourse matrix */
  for (i = 0; i < 1192; i++) {
    DiscOutput->bown_timecourse[2385 * i] = DiscOutput->bown[i];
  }

  /*  initialize and declare nrep */
  printf("%s\n", ">> STEP 2: Propagating BOWN signals ...");
  fflush(stdout);

  /*  iterate till convergence */
  nrep = 1.0;
  b_nrep = 0;
  exitg1 = false;
  while ((!exitg1) && (b_nrep <= (int)DiscParams->max_iter - 1)) {
    nrep = (double)b_nrep + 1.0;

    /*  compute the transition vector */
    /* global */
    /* local */
    /*  update bown */
    b_DiscOutput = DiscOutput->num_nodes - 1.0;
    for (i = 0; i < 1192; i++) {
      d = 0.0;
      d1 = 0.0;
      for (j = 0; j < 1192; j++) {
        xoffset = j + 1192 * i;
        d += DiscOutput->bown[j] * agreement_GBL[xoffset];
        d1 += DiscOutput->bown[j] * agreement_LCL[xoffset];
      }

      d_DiscOutput[i] = d1;
      c_DiscOutput[i] = d;
    }

    /*  no negative "activities" -- they become 0 */
    for (xoffset = 0; xoffset < 1192; xoffset++) {
      DiscOutput->bown[xoffset] = (DiscOutput->bown[xoffset] +
        DiscParams->weightGBL * c_DiscOutput[xoffset] / b_DiscOutput) +
        DiscParams->weightLCL * d_DiscOutput[xoffset] / (DiscParams->Knear - 1.0);
      if (DiscOutput->bown[xoffset] < 0.0) {
        DiscOutput->bown[xoffset] = 0.0;
      }
    }

    /*  normalize bown */
    d = DiscOutput->num_nodes / 2.0;
    if (1.0 > d) {
      xoffset = 0;
    } else {
      xoffset = (int)d;
    }

    if (d + 1.0 > DiscOutput->num_nodes) {
      i = 1;
    } else {
      i = (int)(d + 1.0);
    }

    DiscOutput_size[0] = 1;
    DiscOutput_size[1] = xoffset;
    for (j = 0; j < xoffset; j++) {
      c_DiscOutput[j] = DiscOutput->bown[j] + DiscOutput->bown[(i + j) - 1];
    }

    c_repmat(c_DiscOutput, DiscOutput_size, tmp_data, tmp_size);

    /*  save the timecourse */
    for (i = 0; i < 1192; i++) {
      DiscOutput->bown[i] /= tmp_data[i];
      DiscOutput->bown_timecourse[((int)(((double)b_nrep + 1.0) + 1.0) + 2385 *
        i) - 1] = DiscOutput->bown[i];
    }

    /*  check for convergence */
    for (k = 0; k < 1192; k++) {
      d_DiscOutput[k] = fabs(DiscOutput->bown[k] - DiscOutput->
        bown_timecourse[b_nrep + 2385 * k]);
    }

    b_DiscOutput = d_DiscOutput[0];
    for (k = 0; k < 1191; k++) {
      b_DiscOutput += d_DiscOutput[k + 1];
    }

    if (b_DiscOutput < DiscOutput->num_nodes * DiscParams->convergence_lambda) {
      exitg1 = true;
    } else {
      b_nrep++;
    }
  }

  printf("%s\n", ">> CONVERGED AND DONE");
  fflush(stdout);

  /*  save findings */
  /*  save the number of iterations needed */
  DiscOutput->num_iter = nrep;

  /*  save the converged bown values */
}

/*
 * File trailer for disc_compute_bown.c
 *
 * [EOF]
 */
