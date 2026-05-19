#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"

void nnSetPrimitiveBlend(enum NNE_PRIM_BLEND blend)
{
}

void nnSetPrimitiveTexNum(struct _NNS_TEXLIST* texlist, signed int num)
{
}

void nnSetPrimitiveTexState(enum NNE_PRIM_TEXBLEND blend,
                            enum NNE_PRIM_TEXCOORD coord,
                            enum NNE_PRIM_TEXWRAP uwrap,
                            enum NNE_PRIM_TEXWRAP vwrap)
{
}

void nnBeginDrawPrimitive2D(enum NNE_PRIM2D_FMT fmt, enum NNE_PRIM_ALPHABLEND blend)
{
}

void nnDrawPrimitive2D(enum NNE_PRIM_TRIANGLE type, void* vtx, signed int count, float pri)
{
}

void nnEndDrawPrimitive2D(void)
{
}

void nnSetPrimitive3DMatrix(float (*mtx)[4][4])
{
}

void nnBeginDrawPrimitive3D(enum NNE_PRIM3D_FMT fmt,
                            enum NNE_PRIM_ALPHABLEND blend,
                            enum NNE_PRIM_LIGHT light,
                            enum NNE_PRIM_CULL cull)
{
}

void nnDrawPrimitive3D(enum NNE_PRIM_TRIANGLE type, void* vtx, signed int count)
{
}

void nnEndDrawPrimitive3D(void)
{
}
