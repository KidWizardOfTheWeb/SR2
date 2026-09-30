#ifndef NNCALCMATRIXPALETTE_H
#define NNCALCMATRIXPALETTE_H

#include "usr/local/sega/nn/src/System/nnsystem.h"

struct NNS_MATRIXSTACK;
struct NNS_OBJECT;

#ifdef __cplusplus
extern "C" {
#endif

void nnCopyMatrix33(NNS_MATRIX* dst, NNS_MATRIX* src);
void nnCalcMatrixPaletteNode(signed int nodeIdx);
void nnCalcMatrixPalette(NNS_MATRIX* mtxpal,
                         unsigned int* nodestatlist,
                         struct NNS_OBJECT* obj,
                         NNS_MATRIX* basemtx,
                         struct NNS_MATRIXSTACK* mstk,
                         unsigned int flag);

#ifdef __cplusplus
}
#endif

#endif // NNCALCMATRIXPALETTE_H
