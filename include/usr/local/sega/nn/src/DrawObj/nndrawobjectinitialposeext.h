#ifndef NNDRAWOBJECTINITIALPOSEEXT_H
#define NNDRAWOBJECTINITIALPOSEEXT_H

#include "usr/local/sega/nn/src/DrawObj/nndrawobjectinitialposeltd.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

#include "usr/local/sega/nn/src/Object/nnobject.h"

#ifdef __cplusplus
extern "C" {
#endif
void nnDrawObjectInitialPoseExt(struct NNS_OBJECT* obj,
                                NNS_MATRIX* basemtx,
                                unsigned int* nodestatlist,
                                unsigned int subobjtype,
                                unsigned int flag);
static void nnDrawObjectInitialPose(struct NNS_OBJECT* obj,
                                    NNS_MATRIX* basemtx,
                                    unsigned int* nodestatlist,
                                    unsigned int subobjtype,
                                    unsigned int flag)
{
    if (flag & ~2U) {
        nnDrawObjectInitialPoseExt(obj, basemtx, nodestatlist, subobjtype, flag);
    } else {
        nnDrawObjectInitialPoseLtd(obj, basemtx, nodestatlist, subobjtype, flag);
    }
}

#ifdef __cplusplus
}
#endif

#endif // NNDRAWOBJECTINITIALPOSEEXT_H
