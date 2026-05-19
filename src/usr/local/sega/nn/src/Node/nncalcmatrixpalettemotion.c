#include "usr/local/sega/nn/src/Node/nncalcmatrixpalettemotion.h"

void nnCalcMatrixPaletteMotion(float (*mtxpal)[4][4],
                               unsigned int* nodestatlist,
                               struct NNS_OBJECT* obj,
                               struct NNS_MOTION* mot,
                               float frame,
                               float (*basemtx)[4][4],
                               struct NNS_MATRIXSTACK* mstk,
                               unsigned int flag)
{
}

signed int nnCalcMotionFrame(
    float* dstframe, unsigned int fType, float startframe, float endframe, float frame)
{
}

void nnCalcMatrixPaletteMotionNode(signed int nodeIdx)
{
}

signed int nnCalcNodeMotionCore(float (*pNodeMtx)[4][4],
                                signed int* pHideFlag,
                                float (*pBaseMtx)[4][4],
                                struct NNS_NODE* pNode,
                                signed int NodeIdx,
                                struct NNS_MOTION* pMot,
                                signed int SubMotIdx,
                                float frame)
{
}

signed int nnCalcMotionRotate(struct NNS_SUBMOTION* submot,
                              float frame,
                              struct NNS_ROTATE_A32* rv,
                              struct NNS_QUATERNION* rq,
                              unsigned int rtype)
{
}

void nnRotateXYZMatrixFast(float (*mtx)[4][4], signed int ax, signed int ay, signed int az)
{
}

void nnRotateXZYMatrixFast(float (*mtx)[4][4], signed int ax, signed int ay, signed int az)
{
}

void nnRotateZXYMatrixFast(float (*mtx)[4][4], signed int ax, signed int ay, signed int az)
{
}

signed int nnCalcMotionTranslate(struct NNS_SUBMOTION* submot, float frame, struct NNS_VECTOR* tv)
{
}

void nnTranslateMatrixFast(float (*mtx)[4][4], float x, float y, float z)
{
}

signed int nnCalcMotionScale(struct NNS_SUBMOTION* submot, float frame, struct NNS_VECTOR* sv)
{
}

void nnScaleMatrixFast(float (*mtx)[4][4], float x, float y, float z)
{
}

void nnCalcMatrixPaletteMotionNode2BoneSIIK(signed int jnt1nodeIdx)
{
}

void nnCalcMatrixPaletteMotionNode1BoneSIIK(signed int jnt1nodeIdx)
{
}

enum NNE_BOOL nnCalcMotionUserData(struct NNS_NODEUSRMOT_CALLBACK_VAL* val,
                                   struct NNS_SUBMOTION* submot,
                                   float frame)
{
}

void nnNormalizeColumn(float (*mtx)[4][4], signed int clm)
{
}
