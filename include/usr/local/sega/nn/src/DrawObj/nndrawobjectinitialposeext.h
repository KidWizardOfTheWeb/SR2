#ifndef NNDRAWOBJECTINITIALPOSEEXT_H
#define NNDRAWOBJECTINITIALPOSEEXT_H

#include "usr/local/sega/nn/src/Object/nnobject.h"

void nnDrawObjectInitialPoseExt(struct NNS_OBJECT* obj,
                                float (*basemtx)[4][4],
                                unsigned int* nodestatlist,
                                unsigned int subobjtype,
                                unsigned int flag);

#endif // NNDRAWOBJECTINITIALPOSEEXT_H
