/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "disc_compute_bown.h"
#include "disc_compute_bown_terminate.h"
#include "disc_compute_bown_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void argInit_1192x1192_real_T(double result[1420864]);
static void argInit_1192x1192x6_real_T(double result[8525184]);
static void argInit_1x1192_real_T(double result[1192]);
static void argInit_1x13_char_T(char result[13]);
static void argInit_1x3_real_T(double result[3]);
static void argInit_1x4_real_T(double result[4]);
static void argInit_1x7_real_T(double result[7]);
static void argInit_1x801_struct1_T(struct1_T result[801]);
static void argInit_2385x1192_real_T(double result[2842920]);
static char argInit_char_T(void);
static double argInit_real_T(void);
static rtString argInit_rtString(void);
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static void argInit_struct2_T(struct2_T *result);
static void main_disc_compute_bown(void);

/* Function Definitions */
/*
 * Arguments    : double result[1420864]
 * Return Type  : void
 */
static void argInit_1192x1192_real_T(double result[1420864])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1192; idx0++) {
    for (idx1 = 0; idx1 < 1192; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 1192 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[8525184]
 * Return Type  : void
 */
static void argInit_1192x1192x6_real_T(double result[8525184])
{
  int idx0;
  int idx1;
  int idx2;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1192; idx0++) {
    for (idx1 = 0; idx1 < 1192; idx1++) {
      for (idx2 = 0; idx2 < 6; idx2++) {
        /* Set the value of the array element.
           Change this value to the value that the application requires. */
        result[(idx0 + 1192 * idx1) + 1420864 * idx2] = argInit_real_T();
      }
    }
  }
}

/*
 * Arguments    : double result[1192]
 * Return Type  : void
 */
static void argInit_1x1192_real_T(double result[1192])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 1192; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : char result[13]
 * Return Type  : void
 */
static void argInit_1x13_char_T(char result[13])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 13; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : double result[3]
 * Return Type  : void
 */
static void argInit_1x3_real_T(double result[3])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 3; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[4]
 * Return Type  : void
 */
static void argInit_1x4_real_T(double result[4])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 4; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[7]
 * Return Type  : void
 */
static void argInit_1x7_real_T(double result[7])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : struct1_T result[801]
 * Return Type  : void
 */
static void argInit_1x801_struct1_T(struct1_T result[801])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 801; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    argInit_struct1_T(&result[idx1]);
  }
}

/*
 * Arguments    : double result[2842920]
 * Return Type  : void
 */
static void argInit_2385x1192_real_T(double result[2842920])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2385; idx0++) {
    for (idx1 = 0; idx1 < 1192; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 2385 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : char
 */
static char argInit_char_T(void)
{
  return '?';
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : rtString
 */
static rtString argInit_rtString(void)
{
  rtString result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x13_char_T(result.Value);
  return result;
}

/*
 * Arguments    : struct0_T *result
 * Return Type  : void
 */
static void argInit_struct0_T(struct0_T *result)
{
  double result_tmp;
  int i;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x1192_real_T(result->pos_x);
  result_tmp = argInit_real_T();
  result->num_iter = result_tmp;
  argInit_1192x1192_real_T(result->dist_decay);
  result->stim_name = argInit_rtString();
  result->num_nodes = result_tmp;
  argInit_2385x1192_real_T(result->bown_timecourse);
  argInit_1192x1192x6_real_T(result->agreement);
  argInit_1x4_real_T(result->axes_range);
  argInit_1x801_struct1_T(result->NB);
  for (i = 0; i < 1192; i++) {
    result_tmp = result->pos_x[i];
    result->pos_y[i] = result_tmp;
    result->dx[i] = result_tmp;
    result->dy[i] = result_tmp;
    result->angle[i] = result_tmp;
    result->bown[i] = result_tmp;
    result->color_norm[i] = result_tmp;
    result->color_contrast[i] = result_tmp;
  }

  memcpy(&result->distance[0], &result->dist_decay[0], 1420864U * sizeof(double));
}

/*
 * Arguments    : struct1_T *result
 * Return Type  : void
 */
static void argInit_struct1_T(struct1_T *result)
{
  double d;
  int i;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x1192_real_T(result->NBind);
  for (i = 0; i < 1192; i++) {
    d = result->NBind[i];
    result->NBpos_x[i] = d;
    result->NBpos_y[i] = d;
    result->NBang[i] = d;
    result->NBdx[i] = d;
    result->NBdy[i] = d;
    result->NBcolor_norm[i] = d;
  }
}

/*
 * Arguments    : struct2_T *result
 * Return Type  : void
 */
static void argInit_struct2_T(struct2_T *result)
{
  double result_tmp;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result->space_constant = result_tmp;
  result->convergence_lambda = result_tmp;
  result->max_iter = result_tmp;
  result->Knear = result_tmp;
  result->weightLCL = result_tmp;
  result->weightGBL = result_tmp;
  result->linearAngTh = result_tmp;
  result->distLCL = result_tmp;
  result->initial_bown = result_tmp;
  argInit_1x3_real_T(result->agreement_combo);
  argInit_1x7_real_T(result->bown_params);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_disc_compute_bown(void)
{
  static struct0_T DiscOutput;
  struct2_T r;

  /* Initialize function 'disc_compute_bown' input arguments. */
  /* Initialize function input argument 'DiscOutput'. */
  /* Initialize function input argument 'DiscParams'. */
  /* Call the entry-point 'disc_compute_bown'. */
  argInit_struct0_T(&DiscOutput);
  argInit_struct2_T(&r);
  disc_compute_bown(&DiscOutput, &r);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_disc_compute_bown();

  /* Terminate the application.
     You do not need to do this more than one time. */
  disc_compute_bown_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
