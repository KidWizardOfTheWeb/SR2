#ifndef NNCALCMATRIXPALETTE_H
#define NNCALCMATRIXPALETTE_H

struct NNS_MATRIXSTACK;
struct NNS_OBJECT;

void nnCopyMatrix33(float (*dst)[4][4], float (*src)[4][4]);
void nnCalcMatrixPaletteNode(signed int nodeIdx);
void nnCalcMatrixPalette(float (*mtxpal)[4][4],
                         unsigned int* nodestatlist,
                         struct NNS_OBJECT* obj,
                         float (*basemtx)[4][4],
                         struct NNS_MATRIXSTACK* mstk,
                         unsigned int flag);

#endif // NNCALCMATRIXPALETTE_H
