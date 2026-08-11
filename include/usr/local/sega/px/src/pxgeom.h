#ifndef PXGEOM_H
#define PXGEOM_H

#include "usr/local/sega/nn/src/DrawObj/nntexmtxps2.h"

enum PXE_CULL {
    PXE_CULL_NONE = 0,
    PXE_CULL_CW = 1,
    PXE_CULL_CCW = 2,
};

enum PXE_LIGHT {
    PXE_LIGHT_0 = 0,
    PXE_LIGHT_1 = 1,
    PXE_LIGHT_2 = 2,
};

// total size: 0x10
struct PXS_FXYZW {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
};

// total size: 0xC
struct PXS_SVF_POSITION {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
};

// total size: 0xC
struct PXS_SVF_NORMAL {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
};

// total size: 0x6
struct PXS_SVF_NORMAL16 {
    signed short x; // offset 0x0, size 0x2
    signed short y; // offset 0x2, size 0x2
    signed short z; // offset 0x4, size 0x2
};

// total size: 0x4
struct PXS_SVF_COLOR {
    union {
        unsigned int color; // offset 0x0, size 0x4
        struct {
            unsigned char r; // offset 0x0, size 0x1
            unsigned char g; // offset 0x1, size 0x1
            unsigned char b; // offset 0x2, size 0x1
            unsigned char a; // offset 0x3, size 0x1
        };
    };
};

// total size: 0x8
struct PXS_SVF_UV {
    float u; // offset 0x0, size 0x4
    float v; // offset 0x4, size 0x4
};

// total size: 0x4
struct PXS_SVF_UV16 {
    signed short u; // offset 0x0, size 0x2
    signed short v; // offset 0x2, size 0x2
};

// total size: 0x40
struct PXS_MATERIAL {
    float diffuse[3]; // offset 0x0, size 0xC
    union {
        float alpha;    // offset 0xC, size 0x4
        float specular; // offset 0xC, size 0x4
    };
    float ambient[4];  // offset 0x10, size 0x10
    float emissive[4]; // offset 0x20, size 0x10
    float power;       // offset 0x30, size 0x4
    float colorClamp;  // offset 0x34, size 0x4
    float alphaClamp;  // offset 0x38, size 0x4
    float reserved;    // offset 0x3C, size 0x4
};

// total size: 0x30
struct PXS_PARTICLEMATERIAL {
    float width;  // offset 0x0, size 0x4
    float height; // offset 0x4, size 0x4
    float rsvd0;  // offset 0x8, size 0x4
    float rsvd1;  // offset 0xC, size 0x4
    float s0;     // offset 0x10, size 0x4
    float t0;     // offset 0x14, size 0x4
    float q0;     // offset 0x18, size 0x4
    float rsvd2;  // offset 0x1C, size 0x4
    float s1;     // offset 0x20, size 0x4
    float t1;     // offset 0x24, size 0x4
    float q1;     // offset 0x28, size 0x4
    float rsvd3;  // offset 0x2C, size 0x4
};

// total size: 0x30
struct PXS_PARTICLEMATERIAL2 {
    unsigned int giftag_tristrip[4]; // offset 0x0, size 0x10
    unsigned int giftag_eop[4];      // offset 0x10, size 0x10
    float r;                         // offset 0x20, size 0x4
    float g;                         // offset 0x24, size 0x4
    float b;                         // offset 0x28, size 0x4
    float a;                         // offset 0x2C, size 0x4
};

// total size: 0x40
struct PXS_MATRIX {
    union {
        float m[4][4]; // offset 0x0, size 0x40
        struct {
            float _11; // offset 0x0, size 0x4
            float _12; // offset 0x4, size 0x4
            float _13; // offset 0x8, size 0x4
            float _14; // offset 0xC, size 0x4
            float _21; // offset 0x10, size 0x4
            float _22; // offset 0x14, size 0x4
            float _23; // offset 0x18, size 0x4
            float _24; // offset 0x1C, size 0x4
            float _31; // offset 0x20, size 0x4
            float _32; // offset 0x24, size 0x4
            float _33; // offset 0x28, size 0x4
            float _34; // offset 0x2C, size 0x4
            float _41; // offset 0x30, size 0x4
            float _42; // offset 0x34, size 0x4
            float _43; // offset 0x38, size 0x4
            float _44; // offset 0x3C, size 0x4
        };
    };
};
struct PXS_NORMALPARAM;
struct PXS_PRMODESET;
// total size: 0x20
struct PXS_SCREENPARAM {
    float width;     // offset 0x0, size 0x4
    float height;    // offset 0x4, size 0x4
    float zmul;      // offset 0x8, size 0x4
    float rsvd0;     // offset 0xC, size 0x4
    float cx;        // offset 0x10, size 0x4
    float cy;        // offset 0x14, size 0x4
    float zbias;     // offset 0x18, size 0x4
    float guardband; // offset 0x1C, size 0x4
};

// total size: 0x10
struct PXS_SHADOWPARAM {
    float x;   // offset 0x0, size 0x4
    float y;   // offset 0x4, size 0x4
    float z;   // offset 0x8, size 0x4
    float len; // offset 0xC, size 0x4
};

struct PXS_WIREPARAM;

extern struct PXS_FXYZW pxgVuClipParam[2];
extern struct PXS_FXYZW pxgLightMatrix[8]; // size: 0x80, address: 0x6E64D0

void PXNormalizeVector(struct PXS_FXYZW* v0, struct PXS_FXYZW* v1);
void PXSetLightColor(enum PXE_LIGHT num, float r, float g, float b, float a);
void PXSetLightVector(enum PXE_LIGHT num, float x, float y, float z);
void PXSetAmbientColor(float r, float g, float b, float a);
void PXPutMaterial(struct PXS_MATERIAL* mat);
void PXPutMaterial2(struct PXS_MATERIAL* mat);
void* PXGetLastShaderConstAddr();
void PXReferMaterial(struct PXS_MATERIAL* mat);
void PXReferMaterial2(struct PXS_MATERIAL* mat);
void PXSetupPrimMode(struct PXS_PRMODESET* prmode, unsigned int prmode0, unsigned int prmode1);
void PXPutPrimMode(struct PXS_PRMODESET* prmode);
void PXPutClipParam(enum PXE_CULL cullmode);
void PXPutNearZ(float nearz);
void PXTransposeMatrix(struct PXS_MATRIX* dst, struct PXS_MATRIX* src);
void PXCalcLightMatrix(struct PXS_MATRIX* p, struct PXS_FXYZW* l, struct PXS_MATRIX* v);
void PXCalcLightMatrix2(struct PXS_MATRIX* p, struct PXS_FXYZW* l, struct PXS_MATRIX* v);
void PXPutLightMatrix(void* mtx, unsigned int flag);
void PXPutLightVector(void* mtx, unsigned int flag);
void PXPutLightColor();
void PXPutShaderConst(unsigned int vumem, void* addr, unsigned int qwc);
void PXReferShaderConst(unsigned int vumem, void* addr, unsigned int qwc);
void PXPutBoneMatrix(struct PXS_MATRIX* mtx, signed int ofs, signed int num);
void PXMakeScreenParam(struct PXS_SCREENPARAM* p,
                       float width,
                       float height,
                       float cx,
                       float cy,
                       float zmul,
                       float zbias);
void PXPutScreenParam(struct PXS_SCREENPARAM* p);
void PXGetScreenParam(struct PXS_SCREENPARAM* p);
void PXPutTransform(enum PXE_TRANSFORM type, void* mtx);
void PXPutViewProjection(void* mtx);
void PXInitSubShaderParam();
void PXSetFogRange(float FogNear, float FogFar, float Fmin, float Fmax);
void PXSetUvParam(float uoffset, float voffset, float uscale, float vscale);
void PXSetScissorMode(signed int mode);
void PXPutSubShaderParam();
void PXMakeNormalParam(struct PXS_NORMALPARAM* param, float len);
void PXPutNormalParam(struct PXS_NORMALPARAM* param);
void PXMakeWireParam(struct PXS_WIREPARAM* param,
                     unsigned int mode,
                     unsigned int colflag,
                     unsigned int prim,
                     unsigned int r,
                     unsigned int g,
                     unsigned int b,
                     unsigned int a);
void PXPutWireParam(struct PXS_WIREPARAM* param);

#endif // PXGEOM_H
