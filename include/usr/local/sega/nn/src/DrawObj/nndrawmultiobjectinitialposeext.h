#ifndef NNDRAWMULTIOBJECTINITIALPOSEEXT_H
#define NNDRAWMULTIOBJECTINITIALPOSEEXT_H

#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

void nnDrawMultiObjectInitialPoseExt(struct NNS_OBJECT* obj,
                                     void* basemtxptrlist,
                                     unsigned int** nodestatlistptrlist,
                                     unsigned int subobjtype,
                                     unsigned int flag,
                                     signed int num,
                                     enum NNE_BOOL basemtxlistsw);

#endif // NNDRAWMULTIOBJECTINITIALPOSEEXT_H
