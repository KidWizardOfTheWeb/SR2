#ifndef NNCALCTRSMOTION_H
#define NNCALCTRSMOTION_H

#include "usr/local/sega/nn/src/Object/nnobject.h"

enum NNE_MOTIONBLEND {
    NNE_MOTIONBLEND_REPLACE_ALL = 0,
    NNE_MOTIONBLEND_ADD_TRANSLATION = 1,
    NNE_MOTIONBLEND_ADD_ALL = 2,
};

void nnCalcTRSList(struct NNS_TRS* trslist, struct NNS_OBJECT* obj);
signed int nnCalcNodeMotionTRSCore(signed int* tflag,
                                   signed int* rflag,
                                   signed int* sflag,
                                   struct NNS_VECTOR* tv,
                                   struct NNS_VECTOR* sv,
                                   struct NNS_QUATERNION* rq,
                                   struct NNS_QUATERNION* invrq,
                                   struct NNS_NODE* pNode,
                                   signed int NodeIdx,
                                   struct NNS_MOTION* pMot,
                                   signed int SubMotIdx,
                                   float frame);
void nnCalcTRSListMotion(struct NNS_TRS* trslist,
                         struct NNS_OBJECT* obj,
                         struct NNS_MOTION* mot,
                         float frame);
void nnLinkMotion(struct NNS_TRS* dstpose,
                  struct NNS_TRS* pose0,
                  struct NNS_TRS* pose1,
                  signed int nnode,
                  float ratio);
void nnCalcMatrixTRSList1BoneSIIK(float (*jnt1mtx)[4][4],
                                  float (*effmtx)[4][4],
                                  struct NNS_OBJECT* obj,
                                  struct NNS_TRS* trslist,
                                  float (*basemtx)[4][4],
                                  signed int jnt1idx);
void nnCalcMatrixTRSList2BoneSIIK(float (*jnt1mtx)[4][4],
                                  float (*jnt2mtx)[4][4],
                                  float (*effmtx)[4][4],
                                  struct NNS_OBJECT* obj,
                                  struct NNS_TRS* trslist,
                                  float (*basemtx)[4][4],
                                  signed int jnt1idx);

#endif // NNCALCTRSMOTION_H
