#include "usr/local/sega/nn/src/DrawObj/nndrawobjectext.h"

void nnCalcLightMatrix2Ext(struct PXS_MATRIX* p, struct PXS_FXYZW* l, struct PXS_MATRIX* v)
{
}

void nnPutLightVectorExt(struct PXS_MATRIX* v)
{
}

void nnInitObject(void)
{
}

enum NNE_BOOL nnCheckObjectFlagExt(unsigned int flag)
{
}

enum NNE_BOOL nnCheckSubObjectFlagExt(unsigned int nodestat, unsigned int fSubObjType)
{
}

void nnSetCullSubObjectExt(void)
{
}

void nnDrawMeshsetExt(struct NNS_VTXLISTPTR* pVtxListPtr,
                      struct NNS_PRIMLISTPTR* pPrimListPtr,
                      float (*mtxpal)[4][4],
                      signed int mtxidx)
{
}

signed int nnCalcMeshSetClip(struct NNS_MESHSET* meshset, float (*mtx)[4][4])
{
}

void nnDrawObjectExt(struct NNS_OBJECT* obj,
                     float (*mtxpal)[4][4],
                     unsigned int* nodestatlist,
                     unsigned int subobjtype,
                     unsigned int flag)
{
}

void nnSetFastShaderSwitchPS2(enum NNE_BOOL on_off)
{
}
