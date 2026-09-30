#ifndef NNCALCMATRIXLIST_H
#define NNCALCMATRIXLIST_H

#include "usr/local/sega/nn/src/Object/nnobject.h"

#ifdef __cplusplus
extern "C" {
#endif

void nnCalcMatrixList(NNS_MATRIX* mtxlist, struct NNS_OBJECT* obj, NNS_MATRIX* basemtx);
void nnCalcMatrixListMotionNode(NNS_MATRIX* mtxlist,
                                struct NNS_OBJECT* obj,
                                NNS_MATRIX* basemtx,
                                struct NNS_MOTION* mot,
                                float frame);
void nnCalcMatrixListMotion(NNS_MATRIX* mtxlist,
                            struct NNS_OBJECT* obj,
                            struct NNS_MOTION* mot,
                            float frame,
                            NNS_MATRIX* basemtx);
void nnCalcMatrixListTRSList(NNS_MATRIX* mtxlist,
                             struct NNS_OBJECT* obj,
                             struct NNS_TRS* trslist,
                             NNS_MATRIX* basemtx);
void nnCalcMatrixPaletteMatrixList(NNS_MATRIX* mtxpal,
                                   struct NNS_OBJECT* obj,
                                   NNS_MATRIX* mtxlist,
                                   NNS_MATRIX* basemtx);
void nnCalcMatrixListMotionNode1BoneSIIK(NNS_MATRIX* mtxlist,
                                         struct NNS_OBJECT* obj,
                                         NNS_MATRIX* basemtx,
                                         signed int jnt1idx,
                                         signed int submotidx,
                                         struct NNS_MOTION* mot,
                                         float frame);
void nnCalcMatrixListMotionNode2BoneSIIK(NNS_MATRIX* mtxlist,
                                         struct NNS_OBJECT* obj,
                                         NNS_MATRIX* basemtx,
                                         signed int jnt1idx,
                                         signed int submotidx,
                                         struct NNS_MOTION* mot,
                                         float frame);

#ifdef __cplusplus
}
#endif

#endif // NNCALCMATRIXLIST_H
