#ifndef NNDRAWOBJECTEXT_H
#define NNDRAWOBJECTEXT_H

#include "usr/local/sega/nn/src/DrawObj/nndrawobjectltd.h"
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

#ifdef __cplusplus
extern "C" {
#endif

void nnCalcLightMatrix2Ext(struct PXS_MATRIX* p, struct PXS_FXYZW* l, struct PXS_MATRIX* v);
void nnPutLightVectorExt(struct PXS_MATRIX* v);
void nnInitObject(void);
enum NNE_BOOL nnCheckObjectFlagExt(unsigned int flag);
enum NNE_BOOL nnCheckSubObjectFlagExt(unsigned int nodestat, unsigned int fSubObjType);
void nnSetCullSubObjectExt(void);
void nnDrawMeshsetExt(struct NNS_VTXLISTPTR* pVtxListPtr,
                      struct NNS_PRIMLISTPTR* pPrimListPtr,
                      NNS_MATRIX* mtxpal,
                      signed int mtxidx);
signed int nnCalcMeshSetClip(struct NNS_MESHSET* meshset, NNS_MATRIX* mtx);
void nnSetFastShaderSwitchPS2(enum NNE_BOOL on_off);
void nnDrawObjectExt(struct NNS_OBJECT* obj,
                     NNS_MATRIX* mtxpal,
                     unsigned int* nodestatlist,
                     unsigned int subobjtype,
                     unsigned int flag);
static void nnDrawObject(struct NNS_OBJECT* obj,
                         NNS_MATRIX* mtxpal,
                         unsigned int* nodestatlist,
                         unsigned int subobjtype,
                         unsigned int flag)
{
    if (flag & ~2U) {
        nnDrawObjectExt(obj, mtxpal, nodestatlist, subobjtype, flag);
    } else {
        nnDrawObjectLtd(obj, mtxpal, nodestatlist, subobjtype, flag);
    }
}

#ifdef __cplusplus
}
#endif

#endif // NNDRAWOBJECTEXT_H
