#ifndef NNMATERIALPRIM_H
#define NNMATERIALPRIM_H

#include "usr/local/sega/nn/src/Material/nnmaterial.h"
#include "usr/local/sega/nn/src/Material/nnmatdata.h"

signed int nnSetPrimitiveMaterialTexturePS2(struct NNS_MATERIAL_TEXMAP_DESC* pTexDesc);
void nnPutPrimitiveMaterialCore(struct NNS_MATERIALPTR* mat);

#endif // NNMATERIALPRIM_H
