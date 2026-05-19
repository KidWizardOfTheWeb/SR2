#include "usr/local/sega/nn/src/Node/nncalcsiik.h"

void nnCalc1BoneSIIK(float (*jnt1mtx)[4][4],
                     float (*jnt1motmtx)[4][4],
                     float (*effmtx)[4][4],
                     float lbone1)
{
}

void nnCalc2BoneSIIK(float (*jnt1mtx)[4][4],
                     float (*jnt1motmtx)[4][4],
                     float (*jnt2mtx)[4][4],
                     float (*jnt2motmtx)[4][4],
                     float (*effmtx)[4][4],
                     float lbone1,
                     float lbone2,
                     enum NNE_BOOL zpref)
{
}

void nnAdjustMatrixXaxis(float (*mtx)[4][4], struct NNS_VECTORFAST* pos)
{
}

void nnCalcCosineTheorem2(
    float* sin0, float* cos0, float* sin1, float* cos1, float a, float b, float c)
{
}

void nnRotateYMatrixSinCosFast(float (*mtx)[4][4], float s, float c)
{
}

void nnRotateZMatrixSinCosFast(float (*mtx)[4][4], float s, float c)
{
}
