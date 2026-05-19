#ifndef NNDRAWSIIKBONE_H
#define NNDRAWSIIKBONE_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"

extern struct NNS_RGBA nngAxisXColor;
extern struct NNS_RGBA nngAxisYColor;
extern struct NNS_RGBA nngAxisZColor;

void nnDrawAxis(struct NNS_VECTOR* p, float length, float (*mtx)[4][4]);

#endif // NNDRAWSIIKBONE_H
