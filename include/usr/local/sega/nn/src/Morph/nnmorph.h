#ifndef NNMORPH_H
#define NNMORPH_H

#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/px/src/pxgeom.h"

// Forward declaration for NNS_VTXLISTPTR (defined in nndrawprim.h)
struct NNS_VTXLISTPTR;

// total size: 0x8
struct NNS_MORPHTARGETPTR {
    signed int nVtxList;                 // offset 0x0, size 0x4
    struct NNS_VTXLISTPTR* pMorphTarget; // offset 0x4, size 0x4
};

// total size: 0x8
struct NNS_MORPHTARGETLIST {
    signed int nMorphTarget;                        // offset 0x0, size 0x4
    struct NNS_MORPHTARGETPTR* pMorphTargetPtrList; // offset 0x4, size 0x4
};

// total size: 0x20
struct NNS_VTXLIST_PS2_VU_DESC_MORPH_OBJECT {
    unsigned int fType;  // offset 0x0, size 0x4
    signed int nDmaQwc;  // offset 0x4, size 0x4
    void* pVertex;       // offset 0x8, size 0x4
    signed int nBoneMtx; // offset 0xC, size 0x4
    void* pBoneMtxList;  // offset 0x10, size 0x4
    void* pRsrvVertex;   // offset 0x14, size 0x4
    void* pOrgVertex;    // offset 0x18, size 0x4
    signed int nStrip;   // offset 0x1C, size 0x4
};

// total size: 0x8
struct NNS_VTXLIST_PS2_DESC_TYPE {
    unsigned int fType; // offset 0x0, size 0x4
    void* pList;        // offset 0x4, size 0x4
};

// total size: 0xC
struct NNS_VTXLIST_PS2_DESC_COMBINED_MORPH_TARGET {
    unsigned int fType; // offset 0x0, size 0x4
    signed int nStrip;  // offset 0x4, size 0x4
    void* pVertex;      // offset 0x8, size 0x4
};

// total size: 0x2C
struct NNS_VTXLIST_PS2_DESC_MORPH_TARGET {
    signed int nStrip;                       // offset 0x0, size 0x4
    struct NNS_VTXLIST_PS2_DESC_TYPE Pos;    // offset 0x4, size 0x8
    struct NNS_VTXLIST_PS2_DESC_TYPE Nrm;    // offset 0xC, size 0x8
    struct NNS_VTXLIST_PS2_DESC_TYPE Col;    // offset 0x14, size 0x8
    struct NNS_VTXLIST_PS2_DESC_TYPE Tex;    // offset 0x1C, size 0x8
    struct NNS_VTXLIST_PS2_DESC_TYPE Weight; // offset 0x24, size 0x8
};

unsigned int nnCalcMorphObjectBufferSize(struct NNS_OBJECT* obj,
                                         struct NNS_MORPHTARGETLIST* mtgt,
                                         unsigned int flag);
unsigned int nnInitMorphObject(struct NNS_OBJECT* mobj,
                               struct NNS_OBJECT* obj,
                               struct NNS_MORPHTARGETLIST* mtgt,
                               unsigned int flag);
void nnCalcMorphSeparateVertices(struct NNS_VTXLISTPTR* pVtxListPtrList,
                                 struct NNS_MORPHTARGETLIST* mtgt,
                                 unsigned int iVtxList,
                                 float* mwpal,
                                 unsigned int flag);
void nnCalcMorphObject(struct NNS_OBJECT* mobj,
                       struct NNS_MORPHTARGETLIST* mtgt,
                       float* mwpal,
                       unsigned int flag);
void nnDrawMorphObject(struct NNS_OBJECT* mobj,
                       float (*mtxpal)[4][4],
                       unsigned int* nodestatlist,
                       unsigned int subobjtype,
                       unsigned int flag);

#endif // NNMORPH_H
