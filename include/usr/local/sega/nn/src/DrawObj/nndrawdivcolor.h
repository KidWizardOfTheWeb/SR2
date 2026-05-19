#ifndef NNDRAWDIVCOLOR_H
#define NNDRAWDIVCOLOR_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"

struct NNS_VTXLIST_PS2_VU_DESC;

extern struct NNS_RGBA_U8 nngDivColor32;

void nnSetDivColor(float r, float g, float b, float a);
void nnSetDivColorRandom(signed int i);
void nnPutSubMaterialDivColor(void);
void nnPutVerticesColorStripProcessVU(struct NNS_VTXLIST_PS2_VU_DESC* pVDesc);

#endif // NNDRAWDIVCOLOR_H
