#ifndef NNDRAWPRIMVBPS2_H
#define NNDRAWPRIMVBPS2_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"

void* nnSetUpVBPS2(void* vbbuf, signed int size);
void nnSetUpPrimitiveLine3DVBPS2(void* vb, enum NNE_PRIM_LINE type, void* vtx, signed int count);

#endif // NNDRAWPRIMVBPS2_H
