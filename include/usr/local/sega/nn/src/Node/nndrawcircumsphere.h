#ifndef NNDRAWCIRCUMSPHERE_H
#define NNDRAWCIRCUMSPHERE_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"

enum NNE_CIRCUM_COL {
    NNE_CIRCUM_COL_NONE = 0,
    NNE_CIRCUM_COL_HIDE = 1,
    NNE_CIRCUM_COL_CLIPHIDE = 2,
    NNE_CIRCUM_COL_INSIDE = 3,
    NNE_CIRCUM_COL_GSINSIDE = 4,
    NNE_CIRCUM_COL_CROSSNEAR = 5,
    NNE_CIRCUM_COL_ERR = 6,
};

extern struct NNS_PRIM3D_P nngCircumPoint[120];

void nnInitCircumsphere();

#endif // NNDRAWCIRCUMSPHERE_H
