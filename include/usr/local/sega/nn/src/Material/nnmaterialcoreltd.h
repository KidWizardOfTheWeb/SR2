#ifndef NNMATERIALCORELTD_H
#define NNMATERIALCORELTD_H

#include "usr/local/sega/nn/src/Material/nnmaterial.h"
#include "usr/local/sega/nn/src/Material/nnmatdata.h"

signed int nnSetMaterialMultiTextureLtdPS2(struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc1,
                                           struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc2);
signed int nnSetMaterialSingleTextureLtdPS2(struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc);
void nnSetMaterialTextureWrapModeLtdPS2(signed int context,
                                        struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc);
enum NNE_BOOL nnPutMaterialCoreLtd(struct NNS_DRAWCALLBACK_VAL* val);
void nnPutMultiMaterialCoreLtd(struct NNS_DRAWCALLBACK_VAL* val);

#endif // NNMATERIALCORELTD_H
