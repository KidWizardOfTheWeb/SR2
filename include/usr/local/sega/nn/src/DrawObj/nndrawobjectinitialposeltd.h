#ifndef NNDRAWOBJECTINITIALPOSELTD_H
#define NNDRAWOBJECTINITIALPOSELTD_H

#include "usr/local/sega/nn/src/System/nnsystem.h"

#include "usr/local/sega/nn/src/Object/nnobject.h"

#ifdef __cplusplus
extern "C" {
#endif
void nnDrawObjectInitialPoseLtd(struct NNS_OBJECT* obj,
                                NNS_MATRIX* basemtx,
                                unsigned int* nodestatlist,
                                unsigned int subobjtype,
                                unsigned int flag);
#ifdef __cplusplus
}
#endif

#endif // NNDRAWOBJECTINITIALPOSELTD_H
