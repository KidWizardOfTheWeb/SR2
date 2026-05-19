#ifndef NNDRAWPRIMLINE_H
#define NNDRAWPRIMLINE_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Fog/nnfog.h"

extern struct NNS_RGBA_U32 nngPrimLineColor;

void nnBeginDrawPrimitiveLine2D(struct NNS_RGBA* col, enum NNE_PRIM_ALPHABLEND blend);
void nnDrawPrimitiveLine2D(enum NNE_PRIM_LINE type, void* vtx, signed int count, float pri);
void nnEndDrawPrimitiveLine2D(void);
void nnBeginDrawPrimitiveLine3D(struct NNS_RGBA* col, enum NNE_PRIM_ALPHABLEND blend);
void nnDrawPrimitiveLine3D(enum NNE_PRIM_LINE type, void* vtx, signed int count);
void nnEndDrawPrimitiveLine3D(void);

#endif // NNDRAWPRIMLINE_H
