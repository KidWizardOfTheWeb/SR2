#ifndef NNMATERIALCOREEXT_H
#define NNMATERIALCOREEXT_H

#include "usr/local/sega/nn/src/Material/nnmaterial.h"
#include "usr/local/sega/nn/src/Material/nnmatdata.h"
#include "usr/local/sega/px/src/pxcontext.h"

extern enum NNE_BOOL nngfEnableUvParam;
extern float nngMatEnvMatrixExt[4][4];
extern struct PXS_CONTEXTBUFFER* nngMaterialCb;
extern signed int nngMaterialCbCurr;

signed int nnSetMaterialMultiTextureExtPS2(struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc1,
                                           struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc2);
signed int nnSetMaterialSingleTextureExtPS2(struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc);
void nnSetMaterialTextureWrapModeExtPS2(signed int context,
                                        struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc);
enum NNE_BOOL nnPutMaterialCoreExt(struct NNS_DRAWCALLBACK_VAL* val);

#endif // NNMATERIALCOREEXT_H
