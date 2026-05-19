#ifndef NNDRAWPRIM_H
#define NNDRAWPRIM_H

#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "usr/local/sce/ee/lib/eestruct.h"

enum NNE_PRIM_ALPHABLEND {
    NNE_PRIM_ALPHABLEND_OFF = 0,
    NNE_PRIM_ALPHABLEND_ON = 1,
};

enum NNE_PRIM_BLEND {
    NNE_PRIM_BLEND_ADD = 0,
    NNE_PRIM_BLEND_BLEND = 1,
    NNE_PRIM_BLEND_PS2_CUSTOM = 2,
};

enum NNE_PRIM_TEXBLEND {
    NNE_PRIM_TEXBLEND_MODULATE = 0,
    NNE_PRIM_TEXBLEND_REPLACE = 1,
};

enum NNE_PRIM_TEXCOORD {
    NNE_PRIM_TEXCOORD_UV = 0,
    NNE_PRIM_TEXCOORD_ENVIRONMENT = 1,
};

enum NNE_PRIM_TEXWRAP {
    NNE_PRIM_TEXWRAP_REPEAT = 0,
    NNE_PRIM_TEXWRAP_CLAMP = 1,
    NNE_PRIM_TEXWRAP_REGION_REPEAT = 2,
    NNE_PRIM_TEXWRAP_REGION_CLAMP = 3,
};

enum NNE_PRIM2D_FMT {
    NNE_PRIM2D_FMT_P = 0,
    NNE_PRIM2D_FMT_PC = 1,
    NNE_PRIM2D_FMT_PCT = 2,
};

enum NNE_PRIM3D_FMT {
    NNE_PRIM3D_FMT_P = 0,
    NNE_PRIM3D_FMT_PN = 1,
    NNE_PRIM3D_FMT_PC = 2,
    NNE_PRIM3D_FMT_PNT = 3,
    NNE_PRIM3D_FMT_PCT = 4,
};

enum NNE_PRIM_LIGHT {
    NNE_PRIM_LIGHT_DISABLE = 0,
    NNE_PRIM_LIGHT_ENABLE = 1,
    NNE_PRIM_LIGHT_SPECULAR = 2,
};

enum NNE_PRIM_CULL {
    NNE_PRIM_CULL_NONE = 0,
    NNE_PRIM_CULL_R = 1,
    NNE_PRIM_CULL_L = 2,
};

enum NNE_PRIM_TRIANGLE {
    NNE_PRIM_TRIANGLE_LIST = 0,
    NNE_PRIM_TRIANGLE_STRIP = 1,
};

enum NNE_PRIM_LINE {
    NNE_PRIM_LINE_LIST = 0,
    NNE_PRIM_LINE_STRIP = 1,
};

// total size: 0xC
struct NNS_RGB {
    float r; // offset 0x0, size 0x4
    float g; // offset 0x4, size 0x4
    float b; // offset 0x8, size 0x4
};

// total size: 0x10
struct NNS_RGBA {
    float r; // offset 0x0
    float g; // offset 0x4
    float b; // offset 0x8
    float a; // offset 0xC
};

// total size: 0x4
struct NNS_RGBA_U8 {
    unsigned char r; // offset 0x0, size 0x1
    unsigned char g; // offset 0x1, size 0x1
    unsigned char b; // offset 0x2, size 0x1
    unsigned char a; // offset 0x3, size 0x1
};

// total size: 0x10
struct NNS_RGBA_U32 {
    unsigned int r; // offset 0x0, size 0x4
    unsigned int g; // offset 0x4, size 0x4
    unsigned int b; // offset 0x8, size 0x4
    unsigned int a; // offset 0xC, size 0x4
};

// total size: 0x10
struct NNS_GSTEST {
    enum NNE_BOOL fForce; // offset 0x0, size 0x4
    unsigned int _pad4;   // offset 0x4, size 0x4
    struct sceGsTest reg; // offset 0x8, size 0x8
};

// total size: 0x18
struct NNS_GSZBUF {
    enum NNE_BOOL fForce;    // offset 0x0, size 0x4
    enum NNE_BOOL fSwitch;   // offset 0x4, size 0x4
    struct sceGsZbuf reg[2]; // offset 0x8, size 0x10
};

// total size: 0x10
struct NNS_PRIM2D_PARAM {
    float xbias; // offset 0x0, size 0x4
    float xmul;  // offset 0x4, size 0x4
    float ybias; // offset 0x8, size 0x4
    float ymul;  // offset 0xC, size 0x4
};

// total size: 0x8
struct NNS_MATERIALPTR {
    unsigned int fType; // offset 0x0, size 0x4
    void* pMaterial;    // offset 0x4, size 0x4
};

// total size: 0x8
struct NNS_VTXLISTPTR {
    unsigned int fType; // offset 0x0, size 0x4
    void* pVtxList;     // offset 0x4, size 0x4
};

// total size: 0x8
struct NNS_PRIMLISTPTR {
    unsigned int fType; // offset 0x0, size 0x4
    void* pPrimList;    // offset 0x4, size 0x4
};

// total size: 0x8
struct NNS_TEXCOORD {
    float u; // offset 0x0, size 0x4
    float v; // offset 0x4, size 0x4
};

// total size: 0x8
struct NNS_VECTOR2D {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
};

// total size: 0x8
struct NNS_PRIM2D_P {
    struct NNS_VECTOR2D Pos; // offset 0x0, size 0x8
};

// total size: 0x14
struct NNS_PRIM2D_PCT {
    struct NNS_VECTOR2D Pos; // offset 0x0, size 0x8
    unsigned int Col;        // offset 0x8, size 0x4
    struct NNS_TEXCOORD Tex; // offset 0xC, size 0x8
};

// total size: 0x10
struct NNS_PRIM3D_P {
    struct NNS_VECTOR Pos; // offset 0x0, size 0xC
};

// total size: 0x18
struct NNS_PRIM3D_PN {
    struct NNS_VECTOR Pos; // offset 0x0, size 0xC
    struct NNS_VECTOR Nrm; // offset 0xC, size 0xC
};

// total size: 0x10
struct NNS_PRIM3D_PC {
    struct NNS_VECTOR Pos; // offset 0x0, size 0xC
    unsigned int Col;      // offset 0xC, size 0x4
};

// total size: 0x18
struct NNS_PRIM3D_PCT {
    struct NNS_VECTOR Pos;   // offset 0x0, size 0xC
    unsigned int Col;        // offset 0xC, size 0x4
    struct NNS_TEXCOORD Tex; // offset 0x10, size 0x8
};

// total size: 0x30
struct NNS_PX_VERTEX {
    float x;        // offset 0x0, size 0x4
    float y;        // offset 0x4, size 0x4
    float z;        // offset 0x8, size 0x4
    float w;        // offset 0xC, size 0x4
    unsigned int r; // offset 0x10, size 0x4
    unsigned int g; // offset 0x14, size 0x4
    unsigned int b; // offset 0x18, size 0x4
    unsigned int a; // offset 0x1C, size 0x4
    float u;        // offset 0x20, size 0x4
    float v;        // offset 0x24, size 0x4
    float q;        // offset 0x28, size 0x4
    float rsvd;     // offset 0x2C, size 0x4
};

extern struct NNS_GSTEST nngGsTest;
extern struct NNS_GSZBUF nngGsZbuf;
extern struct NNS_PRIM2D_PARAM nngPrim2dParam;
extern unsigned long nngPrimBlendGsAlpha64;
extern float nngPrimMtx[4][4];
extern enum NNE_PROJECTION_TYPE nngProjectionType;

#include "usr/local/sega/nn/src/Material/nnmatdata.h"

extern enum NNE_PRIM_BLEND nngPrimBlend;
extern unsigned int nngPrimBlendGsAlpha32;
extern signed int nngPrimPutTexRequest;
extern enum NNE_PRIM_TEXBLEND nngPrimTexBlend;
extern unsigned long nngPrimTexGsClamp;
extern struct _NNS_TEXLIST* nngPrimTexList;
extern enum NNE_PRIM_TEXCOORD nngPrimTexMap;
extern signed int nngPrimTexNum;
extern enum NNE_PRIM_TEXWRAP nngPrimTexWrapU;
extern enum NNE_PRIM_TEXWRAP nngPrimTexWrapV;
extern signed int (*nngPutTextureFunc)(struct _NNS_TEXINFO**, signed int);

void nnSetPrimitiveBlend(enum NNE_PRIM_BLEND blend);
void nnSetPrimitiveTexNum(struct _NNS_TEXLIST* texlist, signed int num);
void nnSetPrimitiveTexState(enum NNE_PRIM_TEXBLEND blend,
                            enum NNE_PRIM_TEXCOORD coord,
                            enum NNE_PRIM_TEXWRAP uwrap,
                            enum NNE_PRIM_TEXWRAP vwrap);
void nnBeginDrawPrimitive2D(enum NNE_PRIM2D_FMT fmt, enum NNE_PRIM_ALPHABLEND blend);
void nnDrawPrimitive2D(enum NNE_PRIM_TRIANGLE type, void* vtx, signed int count, float pri);
void nnEndDrawPrimitive2D(void);
void nnSetPrimitive3DMatrix(float (*mtx)[4][4]);
void nnBeginDrawPrimitive3D(enum NNE_PRIM3D_FMT fmt,
                            enum NNE_PRIM_ALPHABLEND blend,
                            enum NNE_PRIM_LIGHT light,
                            enum NNE_PRIM_CULL cull);
void nnDrawPrimitive3D(enum NNE_PRIM_TRIANGLE type, void* vtx, signed int count);
void nnEndDrawPrimitive3D(void);

#endif // NNDRAWPRIM_H
