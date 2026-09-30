#ifndef NNDRAWOBJECTLTD_H
#define NNDRAWOBJECTLTD_H

#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "usr/local/sega/px/src/pxgeom.h"

extern void (*nngPutLightVectorLtdFunc)(struct PXS_MATRIX*, struct PXS_FXYZW*, struct PXS_MATRIX*);

#ifdef __cplusplus
extern "C" {
#endif

void nnCalcLightMatrix2Ltd(struct PXS_MATRIX* p, struct PXS_FXYZW* l, struct PXS_MATRIX* v);
void nnPutLightVectorLtd(struct PXS_MATRIX* v);
enum NNE_BOOL nnCheckSubObjectFlagLtd(unsigned int nodestat, unsigned int fSubObjType);
void nnDrawObjectLtd(struct NNS_OBJECT* obj,
                     NNS_MATRIX* mtxpal,
                     unsigned int* nodestatlist,
                     unsigned int subobjtype,
                     unsigned int flag);
void nnResetStmaskPS2(void);
void nnSetExtLightSwitchSubObject(void);
void nnSetCullSubObjectLtd(void);
void nnSetDrawObjectPrevParamAutoClearSwitchPS2(enum NNE_BOOL on_off);

#ifdef __cplusplus
}
#endif

#endif // NNDRAWOBJECTLTD_H
