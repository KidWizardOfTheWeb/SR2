#ifndef NNDRAWOBJECTEXT_H
#define NNDRAWOBJECTEXT_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "usr/local/sega/px/src/pxgeom.h"
#include "usr/local/sega/px/src/pxpushbuffer.h"

struct NNS_PRIMLISTPTR;
struct NNS_VTXLISTPTR;

extern unsigned int nngFastShaderSwitch;
extern struct NNS_RGBA_U8 nngNormalColor;
extern float nngNormalLength;
extern void (*nngPutLightVectorExtFunc)(struct PXS_MATRIX*, struct PXS_FXYZW*, struct PXS_MATRIX*);
extern struct NNS_RGBA_U8 nngWireColor;
extern unsigned int nngWireType;
extern struct tagPXS_PUSHBUFFER* pxgCurrentPB;
extern struct PXS_FXYZW pxgLight[4];
extern struct PXS_FXYZW pxgLightMatrix[8];

void nnCalcLightMatrix2Ext(struct PXS_MATRIX* p, struct PXS_FXYZW* l, struct PXS_MATRIX* v);
void nnPutLightVectorExt(struct PXS_MATRIX* v);
void nnInitObject(void);
enum NNE_BOOL nnCheckObjectFlagExt(unsigned int flag);
enum NNE_BOOL nnCheckSubObjectFlagExt(unsigned int nodestat, unsigned int fSubObjType);
void nnSetCullSubObjectExt(void);
void nnDrawMeshsetExt(struct NNS_VTXLISTPTR* pVtxListPtr,
                      struct NNS_PRIMLISTPTR* pPrimListPtr,
                      float (*mtxpal)[4][4],
                      signed int mtxidx);
signed int nnCalcMeshSetClip(struct NNS_MESHSET* meshset, float (*mtx)[4][4]);
void nnDrawObjectExt(struct NNS_OBJECT* obj,
                     float (*mtxpal)[4][4],
                     unsigned int* nodestatlist,
                     unsigned int subobjtype,
                     unsigned int flag);
void nnSetFastShaderSwitchPS2(enum NNE_BOOL on_off);

#endif // NNDRAWOBJECTEXT_H
