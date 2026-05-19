#ifndef NNMATDATA_H
#define NNMATDATA_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"

// total size: 0x40
struct NNS_MATERIAL_COLOR_PXPLUS {
    struct NNS_RGB Diffuse;   // offset 0x0, size 0xC
    float Specular;           // offset 0xC, size 0x4
    struct NNS_RGB Ambient;   // offset 0x10, size 0xC
    float Alpha;              // offset 0x1C, size 0x4
    struct NNS_RGBA Emissive; // offset 0x20, size 0x10
    struct NNS_RGBA Clamp;    // offset 0x30, size 0x10
};

// total size: 0x20
struct NNS_MATERIAL_TEXMAP_DESC {
    unsigned int fTexMapType;    // offset 0x0, size 0x4
    unsigned short fTexWrapMode; // offset 0x4, size 0x2
    unsigned short iTexIdx;      // offset 0x6, size 0x2
    struct NNS_TEXCOORD Offset;  // offset 0x8, size 0x8
    unsigned int GsTexA;         // offset 0x10, size 0x4
    unsigned short GsTexLODL;    // offset 0x14, size 0x2
    signed short GsTexLODK;      // offset 0x16, size 0x2
    unsigned short GsClampMINU;  // offset 0x18, size 0x2
    unsigned short GsClampMAXU;  // offset 0x1A, size 0x2
    unsigned short GsClampMINV;  // offset 0x1C, size 0x2
    unsigned short GsClampMAXV;  // offset 0x1E, size 0x2
};

// total size: 0x70
struct NNS_MATERIAL_SINGLE {
    struct NNS_RGB Diffuse;                     // offset 0x0, size 0xC
    float Specular;                             // offset 0xC, size 0x4
    struct NNS_RGB Ambient;                     // offset 0x10, size 0xC
    float Alpha;                                // offset 0x1C, size 0x4
    struct NNS_RGBA Emissive;                   // offset 0x20, size 0x10
    float Power;                                // offset 0x30, size 0x4
    float ColorClamp;                           // offset 0x34, size 0x4
    float AlphaClamp;                           // offset 0x38, size 0x4
    unsigned int GsTest;                        // offset 0x3C, size 0x4
    unsigned int fMatFlag;                      // offset 0x40, size 0x4
    unsigned int fGsPrimMode;                   // offset 0x44, size 0x4
    unsigned int GsAlpha;                       // offset 0x48, size 0x4
    unsigned int User;                          // offset 0x4C, size 0x4
    struct NNS_MATERIAL_TEXMAP_DESC TexDesc[1]; // offset 0x50, size 0x20
};

extern struct NNS_MATERIAL_SINGLE nngPrim3dMaterial[1];
extern struct NNS_MATERIALPTR nngPrim3dMatptrlist[1];
extern struct NNS_MATERIAL_SINGLE nngMatCtrlMaterial[2];
extern struct NNS_MATERIALPTR nngMatCtrlMatptrlist[1];
extern struct NNS_MATERIAL_SINGLE nngMonoWireMaterial[1];

#endif // NNMATDATA_H
