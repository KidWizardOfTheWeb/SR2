#ifndef NNDRAWVERTICESEXT_H
#define NNDRAWVERTICESEXT_H

struct NNS_VTXLISTPTR;

extern unsigned int* nngShaderTblReducedTbl[384];
extern unsigned int* nngShaderTblTbl[384];

unsigned int nnGetPxShader(unsigned int shader);
void nnDrawPliableVerticesProcessVUExt(struct NNS_VTXLISTPTR* pVtx, float (*pMtxPal)[4][4]);
void nnDrawRigidVerticesProcessVUExt(struct NNS_VTXLISTPTR* pVtx);

#endif // NNDRAWVERTICESEXT_H
