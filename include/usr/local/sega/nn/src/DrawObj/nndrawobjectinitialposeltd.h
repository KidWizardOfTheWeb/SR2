#ifndef NNDRAWOBJECTINITIALPOSELTD_H
#define NNDRAWOBJECTINITIALPOSELTD_H

#include "usr/local/sega/nn/src/Object/nnobject.h"

void nnDrawObjectInitialPoseLtd(struct NNS_OBJECT* obj,
                                float (*basemtx)[4][4],
                                unsigned int* nodestatlist,
                                unsigned int subobjtype,
                                unsigned int flag);

#endif // NNDRAWOBJECTINITIALPOSELTD_H
