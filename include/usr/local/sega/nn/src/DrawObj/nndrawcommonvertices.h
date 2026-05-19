#ifndef NNDRAWCOMMONVERTICES_H
#define NNDRAWCOMMONVERTICES_H

#include "usr/local/sega/nn/src/DrawObj/nncopyobject.h"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Material/nnmaterial.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

// total size: 0x14
struct NNS_DRAW_PARAM_PS2 {
    unsigned int usealpha;             // offset 0x0, size 0x4
    unsigned int shader;               // offset 0x4, size 0x4
    unsigned int shadermaterial;       // offset 0x8, size 0x4
    unsigned int texmark;              // offset 0xC, size 0x4
    enum NNE_BOOL enablefastshadersub; // offset 0x10, size 0x4
};

// total size: 0x38
struct NNS_OBJECT_FLAG_PS2 {
    enum NNE_BOOL doubleside;      // offset 0x0, size 0x4
    enum NNE_BOOL backside;        // offset 0x4, size 0x4
    enum NNE_BOOL frontside;       // offset 0x8, size 0x4
    enum NNE_BOOL inside;          // offset 0xC, size 0x4
    enum NNE_BOOL gsinside;        // offset 0x10, size 0x4
    enum NNE_BOOL meshsetclip;     // offset 0x14, size 0x4
    enum NNE_BOOL crossnear;       // offset 0x18, size 0x4
    enum NNE_BOOL ignorematambi;   // offset 0x1C, size 0x4
    enum NNE_BOOL ignorematspec;   // offset 0x20, size 0x4
    enum NNE_BOOL disablelighting; // offset 0x24, size 0x4
    enum NNE_BOOL ignoretexture;   // offset 0x28, size 0x4
    enum NNE_BOOL specular;        // offset 0x2C, size 0x4
    enum NNE_BOOL usealpha;        // offset 0x30, size 0x4
    unsigned int drawtype;         // offset 0x34, size 0x4
};

// total size: 0x38
struct NNS_PREV_PARAM_PS2 {
    enum NNE_BOOL fautoclearsw;   // offset 0x0, size 0x4
    unsigned int shader;          // offset 0x4, size 0x4
    unsigned int cull;            // offset 0x8, size 0x4
    signed int specular;          // offset 0xC, size 0x4
    signed int disablelighting;   // offset 0x10, size 0x4
    signed int texidx[2];         // offset 0x14, size 0x8
    unsigned int clampmode[2];    // offset 0x1C, size 0x8
    struct NNS_TEXCOORD texuvofs; // offset 0x24, size 0x8
    unsigned int fgsprimmode[2];  // offset 0x2C, size 0x8
    void* pBoneList;              // offset 0x34, size 0x4
};

// total size: 0x8
struct NNS_COMMON_WEIGHT {
    signed int Index; // offset 0x0, size 0x4
    float Ratio;      // offset 0x4, size 0x4
};

// total size: 0xC
struct NNS_COMMON_WEIGHT2 {
    signed int Index0; // offset 0x0, size 0x4
    signed int Index1; // offset 0x4, size 0x4
    float Ratio;       // offset 0x8, size 0x4
};

// total size: 0x18
struct NNS_COMMON_PN {
    struct NNS_VECTOR Pos; // offset 0x0, size 0xC
    struct NNS_VECTOR Nrm; // offset 0xC, size 0xC
};

// total size: 0x18
struct NNS_COMMON_PW2 {
    struct NNS_VECTOR Pos;         // offset 0x0, size 0xC
    struct NNS_COMMON_WEIGHT2 Wgt; // offset 0xC, size 0xC
};

// total size: 0x2C
struct NNS_COMMON_PW4 {
    struct NNS_VECTOR Pos;           // offset 0x0, size 0xC
    struct NNS_COMMON_WEIGHT Wgt[4]; // offset 0xC, size 0x20
};

// total size: 0x24
struct NNS_COMMON_PNW2 {
    struct NNS_VECTOR Pos;         // offset 0x0, size 0xC
    struct NNS_VECTOR Nrm;         // offset 0xC, size 0xC
    struct NNS_COMMON_WEIGHT2 Wgt; // offset 0x18, size 0xC
};

// total size: 0x38
struct NNS_COMMON_PNW4 {
    struct NNS_VECTOR Pos;           // offset 0x0, size 0xC
    struct NNS_VECTOR Nrm;           // offset 0xC, size 0xC
    struct NNS_COMMON_WEIGHT Wgt[4]; // offset 0x18, size 0x20
};

// total size: 0x10
struct NNS_COMMON_TEXCOORD2 {
    struct NNS_TEXCOORD Tex[2]; // offset 0x0, size 0x10
};

// total size: 0x50
struct PXS_VERTEX_PCTT4I3W {
    float x;        // offset 0x0, size 0x4
    float y;        // offset 0x4, size 0x4
    float z;        // offset 0x8, size 0x4
    float w0;       // offset 0xC, size 0x4
    unsigned int r; // offset 0x10, size 0x4
    unsigned int g; // offset 0x14, size 0x4
    unsigned int b; // offset 0x18, size 0x4
    unsigned int a; // offset 0x1C, size 0x4
    float u0;       // offset 0x20, size 0x4
    float v0;       // offset 0x24, size 0x4
    signed int i0;  // offset 0x28, size 0x4
    signed int i1;  // offset 0x2C, size 0x4
    float w1;       // offset 0x30, size 0x4
    float w2;       // offset 0x34, size 0x4
    signed int i2;  // offset 0x38, size 0x4
    signed int i3;  // offset 0x3C, size 0x4
    float u1;       // offset 0x40, size 0x4
    float v1;       // offset 0x44, size 0x4
    float rsvd0;    // offset 0x48, size 0x4
    float rsvd1;    // offset 0x4C, size 0x4
};

struct NNS_PRIMLISTPTR;
struct NNS_PRIMLIST_COMMON_TRIANGLE_STRIP_R;
struct NNS_VTXLISTPTR;
struct NNS_VTXLIST_COMMON_DESC;

extern struct NNS_DRAW_PARAM_PS2 nngDrawParam;
extern struct NNS_PREV_PARAM_PS2 nngPrevParam;
extern struct NNS_OBJECT_FLAG_PS2 nngSubObjectFlag;
extern signed char nngBoneTable[128];
extern float nngDivColorAlpha;
extern struct NNS_DRAWCALLBACK_VAL nngDrawCallBackVal;

void nnPutRigidCommonVerticesColorStripStripL(struct NNS_VTXLIST_COMMON_DESC* pVDesc,
                                              struct NNS_PRIMLIST_COMMON_TRIANGLE_STRIP_R* pPList);
void nnPutRigidCommonVerticesStripL(struct NNS_VTXLIST_COMMON_DESC* pVDesc,
                                    struct NNS_PRIMLIST_COMMON_TRIANGLE_STRIP_R* pPList);
void nnPutPliableCommonVerticesColorStripStripL(
    struct NNS_VTXLIST_COMMON_DESC* pVDesc, struct NNS_PRIMLIST_COMMON_TRIANGLE_STRIP_R* pPList);
void nnPutPliableCommonVerticesStripL(struct NNS_VTXLIST_COMMON_DESC* pVDesc,
                                      struct NNS_PRIMLIST_COMMON_TRIANGLE_STRIP_R* pPList);
void nnPutBoneMatrixCommon(float (*pMtxPal)[4][4],
                           struct NNS_VTXLIST_COMMON_DESC* pVDesc,
                           struct NNS_PRIMLIST_COMMON_TRIANGLE_STRIP_R* pPList);
void nnDrawPliableCommonVerticesExt(struct NNS_VTXLISTPTR* pVtx,
                                    struct NNS_PRIMLISTPTR* pPrim,
                                    float (*pMtxPal)[4][4]);
void nnDrawRigidCommonVerticesExt(struct NNS_VTXLISTPTR* pVtx, struct NNS_PRIMLISTPTR* pPrim);

#endif // NNDRAWCOMMONVERTICES_H
