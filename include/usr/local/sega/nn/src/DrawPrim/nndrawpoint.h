#ifndef NNDRAWPOINT_H
#define NNDRAWPOINT_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"

enum NNE_PRIM2D_POINT_FMT {
    NNE_PRIM2D_POINT_FMT_P = 0,
    NNE_PRIM2D_POINT_FMT_PC = 1,
};

enum NNE_PRIM3D_POINT_FMT {
    NNE_PRIM3D_POINT_FMT_P = 0,
    NNE_PRIM3D_POINT_FMT_PC = 1,
};

void nnBeginDrawPrimitivePoint2D(enum NNE_PRIM2D_POINT_FMT fmt,
                                 struct NNS_RGBA* col,
                                 enum NNE_PRIM_ALPHABLEND blend);
void nnDrawPrimitivePoint2D(void* vtx, signed int count, float pri);
void nnEndDrawPrimitivePoint2D(void);

#endif // NNDRAWPOINT_H
