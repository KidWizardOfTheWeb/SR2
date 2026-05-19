#ifndef NNDRAWMULTIOBJECTEXT_H
#define NNDRAWMULTIOBJECTEXT_H

#include "usr/local/sega/nn/src/DrawObj/nndrawcommonvertices.h"
#include "usr/local/sega/nn/src/DrawObj/nntexmtxps2.h"
#include "usr/local/sega/nn/src/Light/nnlight.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

enum NNE_LIGHTSET_PS2_SPECSWITCH {
    NNE_LIGHTSET_PS2_SPECSWITCH_OFF = 0,
    NNE_LIGHTSET_PS2_SPECSWITCH_ON = 1,
    NNE_LIGHTSET_PS2_SPECSWITCH_MAX = 2,
    NNE_LIGHTSET_PS2_SPECSWITCH_ALWAYS = 2,
};

enum NNE_LIGHTTYPE_PS2 {
    NNE_LIGHTTYPE_PS2_PARALLEL = 0,
    NNE_LIGHTTYPE_PS2_POINT = 1,
    NNE_LIGHTTYPE_PS2_SPOT = 2,
    NNE_LIGHTTYPE_PS2_SPECULAR = 3,
    NNE_LIGHTTYPE_PS2_MAX = 4,
};

// total size: 0x84
struct NNS_PS2_LIGHT_DATA {
    enum NNE_BOOL fSw;               // offset 0x0, size 0x4
    unsigned int fType;              // offset 0x4, size 0x4
    enum NNE_LIGHTTYPE_PS2 fTypePs2; // offset 0x8, size 0x4
    struct NNS_RGBA sCol;            // offset 0xC, size 0x10
    struct NNS_RGBA Col;             // offset 0x1C, size 0x10
    float Inten;                     // offset 0x2C, size 0x4
    struct NNS_VECTOR Dir;           // offset 0x30, size 0xC
    struct NNS_VECTOR Pos;           // offset 0x3C, size 0xC
    struct NNS_VECTOR SrcTgt;        // offset 0x48, size 0xC
    struct NNS_VECTOR Tgt;           // offset 0x54, size 0xC
    struct NNS_ROTATE_A32 Rot;       // offset 0x60, size 0xC
    enum NNE_ROTATETYPE fRotType;    // offset 0x6C, size 0x4
    signed short InnerAng;           // offset 0x70, size 0x2
    signed short OuterAng;           // offset 0x72, size 0x2
    float InnerRange;                // offset 0x74, size 0x4
    float OuterRange;                // offset 0x78, size 0x4
    float FallOffStart;              // offset 0x7C, size 0x4
    float FallOffEnd;                // offset 0x80, size 0x4
};

// total size: 0x510
struct NNS_PS2_LIGHT {
    struct NNS_PS2_LIGHT_DATA LightData[9];        // offset 0x0, size 0x4A4
    struct NNS_PS2_LIGHT_DATA* pOnLightData[4][4]; // offset 0x4A4, size 0x40
    signed int nOnLight[4];                        // offset 0x4E4, size 0x10
    enum NNE_LIGHTSET_PS2_SPECSWITCH fSpeclarSw;   // offset 0x4F4, size 0x4
    struct NNS_RGBA AmbiCol;                       // offset 0x4F8, size 0x10
    enum NNE_BOOL fReqPutVector;                   // offset 0x508, size 0x4
    enum NNE_BOOL fReqPutColor;                    // offset 0x50C, size 0x4
};

extern struct NNS_PS2_LIGHT nngLight;
extern float nngLightMatrix[4][4];
extern struct NNS_OBJECT_FLAG_PS2 nngObjectFlag;
extern float nngProjectionMatrix[4][4];
extern void (*nngPutEnvTextureMatrixFunc)(float (*)[4][4], enum PXE_TRANSFORM);
extern enum NNE_BOOL nngfDrew;
extern float (*nngpTextureMatrix)[4][4];

enum NNE_BOOL nnCheckMultiSubObjectFlagExt(unsigned int nodestat);
void nnDrawMultiObjectExt(struct NNS_OBJECT* obj,
                          float (**mtxpalptrlist)[4][4],
                          unsigned int** nodestatlistptrlist,
                          unsigned int subobjtype,
                          unsigned int flag,
                          signed int num);

#endif // NNDRAWMULTIOBJECTEXT_H
