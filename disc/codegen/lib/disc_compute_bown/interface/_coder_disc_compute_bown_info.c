/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_disc_compute_bown_info.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 22-Dec-2020 12:49:11
 */

/* Include Files */
#include "_coder_disc_compute_bown_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4] = {
    "789cc553cb4ec240141d0c1237282bffc1050e3471a14b0d10168a09b8d1985aa6232d741ece4cb1aefc047fc94f7065fc0f976e645a4a4b03a9095a6fd2999e"
    "39737bcfb93705a5ee790900b00ba278ad447b75f634b700a8cdcfb7c07264f9d28afdeb39b9bf0dca21aea6789dff32c78851850315016a11bcc8b41971a945",
    "d5e0896320b064de14db2173ef7a78e012dc4f830b8d483b452d80a6f4fb9983d1a4ef13201c9928f4d220ec87d6f796f2abf5c77ecb2bfa91e6e33eb8191c47"
    "2dc3dfb46e5b27d0610443eed0808b31b41992900b36c648493861236622e65943098d86d1a8378d7ae3c8b45d894c81a7ae74198588d918ea23235cc3659644",
    "b8afb039648ff49064fc051bfadbcff117f34b4aac91c09860aa121d771beaa8acd5113152091fa9df9b2bcdf11df305cc75d14d3ddcbc7eeefdd05f764feeef"
    "84f7af3ede43aaa87a071dffb3c87a71fc57bda2fe4b3979e80df8b571cc47a7ac236cde0d7aed76a2e332a74e9e0eb006fff5f7bf01d750c2c0",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1752U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  const char_T *propFieldName[4] = { "Version", "ResolvedFunctions",
    "EntryPoints", "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, epFieldName);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("disc_compute_bown"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "E:\\home\\phnxprj\\docs\\projects\\kogo_colabs\\2020-12-05_disc_revision\\code\\disc2\\disc\\disc_compute_bown.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738147.51811342593));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.9.0.1495850 (R2020b) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_disc_compute_bown_info.c
 *
 * [EOF]
 */
