#include "usr/local/sega/nn/src/Node/nncalcmatrixlist.h"

void nnCalcMatrixList(float (*mtxlist)[4][4], struct NNS_OBJECT* obj, float (*basemtx)[4][4])
{
}

void nnCalcMatrixListMotionNode(float (*mtxlist)[4][4],
                                struct NNS_OBJECT* obj,
                                float (*basemtx)[4][4],
                                struct NNS_MOTION* mot,
                                float frame)
{
}

void nnCalcMatrixListMotion(float (*mtxlist)[4][4],
                            struct NNS_OBJECT* obj,
                            struct NNS_MOTION* mot,
                            float frame,
                            float (*basemtx)[4][4])
{
}

void nnCalcMatrixListTRSList(float (*mtxlist)[4][4],
                             struct NNS_OBJECT* obj,
                             struct NNS_TRS* trslist,
                             float (*basemtx)[4][4])
{
}

void nnCalcMatrixPaletteMatrixList(float (*mtxpal)[4][4],
                                   struct NNS_OBJECT* obj,
                                   float (*mtxlist)[4][4],
                                   float (*basemtx)[4][4])
{
}

void nnCalcMatrixListMotionNode1BoneSIIK(float (*mtxlist)[4][4],
                                         struct NNS_OBJECT* obj,
                                         float (*basemtx)[4][4],
                                         signed int jnt1idx,
                                         signed int submotidx,
                                         struct NNS_MOTION* mot,
                                         float frame)
{
}

void nnCalcMatrixListMotionNode2BoneSIIK(float (*mtxlist)[4][4],
                                         struct NNS_OBJECT* obj,
                                         float (*basemtx)[4][4],
                                         signed int jnt1idx,
                                         signed int submotidx,
                                         struct NNS_MOTION* mot,
                                         float frame)
{
}
