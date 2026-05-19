#ifndef NNDRAWVERTICESLTD_H
#define NNDRAWVERTICESLTD_H

#include "usr/local/sega/nn/src/DrawObj/nndrawverticesext.h"

struct NNS_VTXLISTPTR;

void nnPutShader(unsigned int shader);
void nnPutBoneMatrix(float (*pMtxPal)[4][4], signed int* pBoneMtxList, unsigned int nBoneMtx);
void nnDrawPliableVerticesProcessVULtd(struct NNS_VTXLISTPTR* pVtx, float (*pMtxPal)[4][4]);
void nnDrawRigidVerticesProcessVULtd(struct NNS_VTXLISTPTR* pVtx);

#endif // NNDRAWVERTICESLTD_H
