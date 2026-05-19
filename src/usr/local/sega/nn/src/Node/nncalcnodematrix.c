#include "usr/local/sega/nn/src/Node/nncalcnodematrix.h"

void nnCalcNodeMatrixNode(float (*mtx)[4][4], struct NNS_OBJECT* obj, signed int nodeidx)
{
}

void nnCalcNodeMatrix(float (*mtx)[4][4],
                      struct NNS_OBJECT* obj,
                      signed int nodeidx,
                      float (*basemtx)[4][4])
{
}

void nnCalcNodeMatrixMotionNode(float (*mtx)[4][4], signed int nodeidx)
{
}

void nnCalcNodeMatrixMotion(float (*mtx)[4][4],
                            struct NNS_OBJECT* obj,
                            signed int nodeidx,
                            struct NNS_MOTION* mot,
                            float frame,
                            float (*basemtx)[4][4])
{
}

void nnCalcNodeMatrixTRSListNode(float (*mtx)[4][4],
                                 struct NNS_OBJECT* obj,
                                 signed int nodeidx,
                                 struct NNS_TRS* trslist)
{
}

void nnCalcNodeMatrixTRSList(float (*mtx)[4][4],
                             struct NNS_OBJECT* obj,
                             signed int nodeidx,
                             struct NNS_TRS* trslist,
                             float (*basemtx)[4][4])
{
}
