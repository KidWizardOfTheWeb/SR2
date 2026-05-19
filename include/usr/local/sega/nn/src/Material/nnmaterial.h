#ifndef NNMATERIAL_H
#define NNMATERIAL_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

// total size: 0x40
struct NNS_DRAWCALLBACK_VAL {
    signed int iMaterial;               // offset 0x0, size 0x4
    signed int iPrevMaterial;           // offset 0x4, size 0x4
    signed int iVtxList;                // offset 0x8, size 0x4
    signed int iPrevVtxList;            // offset 0xC, size 0x4
    signed int iNode;                   // offset 0x10, size 0x4
    signed int iMeshset;                // offset 0x14, size 0x4
    signed int iSubobject;              // offset 0x18, size 0x4
    struct NNS_MATERIALPTR* pMaterial;  // offset 0x1C, size 0x4
    struct NNS_VTXLISTPTR* pVtxListPtr; // offset 0x20, size 0x4
    struct NNS_OBJECT* pObject;         // offset 0x24, size 0x4
    float (*pMatrixPalette)[4][4];      // offset 0x28, size 0x4
    unsigned int* pNodeStatusList;      // offset 0x2C, size 0x4
    unsigned int DrawSubobjType;        // offset 0x30, size 0x4
    unsigned int DrawFlag;              // offset 0x34, size 0x4
    enum NNE_BOOL bModified;            // offset 0x38, size 0x4
    enum NNE_BOOL bReDraw;              // offset 0x3C, size 0x4
};

typedef signed int (*NNS_MATERIAL_CALLBACK_FUNC)(struct NNS_DRAWCALLBACK_VAL*);

extern unsigned int nngGsPrmodeAnd;
extern unsigned int nngGsPrmodeOr;
extern NNS_MATERIAL_CALLBACK_FUNC nngMaterialCallbackFunc;
extern float (*nngpMatTextureMatrix)[4][4];

enum NNE_BOOL nnPutMaterialLtd(struct NNS_DRAWCALLBACK_VAL* val);
enum NNE_BOOL nnPutMaterialExt(struct NNS_DRAWCALLBACK_VAL* val);

#endif // NNMATERIAL_H
