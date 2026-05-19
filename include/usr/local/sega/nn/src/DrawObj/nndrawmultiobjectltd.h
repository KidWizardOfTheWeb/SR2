#ifndef NNDRAWMULTIOBJECTLTD_H
#define NNDRAWMULTIOBJECTLTD_H

#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

enum NNE_BOOL nnCheckMultiSubObjectFlagLtd(unsigned int nodestat);
void nnDrawMultiObjectLtd(struct NNS_OBJECT* obj,
                          float (**mtxpalptrlist)[4][4],
                          unsigned int** nodestatlistptrlist,
                          unsigned int subobjtype,
                          unsigned int flag,
                          signed int num);

#endif // NNDRAWMULTIOBJECTLTD_H
