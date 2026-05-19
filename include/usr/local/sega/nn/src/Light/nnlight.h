#ifndef NNLIGHT_H
#define NNLIGHT_H

#include "usr/local/sega/nn/src/Camera/nncamera.h"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

enum NNE_LIGHT {
    NNE_LIGHT_0 = 0,
    NNE_LIGHT_1 = 1,
    NNE_LIGHT_2 = 2,
    NNE_LIGHT_3 = 3,
    NNE_LIGHT_4 = 4,
    NNE_LIGHT_5 = 5,
    NNE_LIGHT_6 = 6,
    NNE_LIGHT_7 = 7,
    NNE_LIGHT_MAX = 8,
    NNE_LIGHT_ALL = 9,
};

enum NNE_LIGHTSET_PS2_TYPE {
    NNE_LIGHTSET_PS2_TYPE_PA3_PO0_SPO0_SPE0 = 0,
    NNE_LIGHTSET_PS2_TYPE_PA2_PO0_SPO0_SPE1 = 1,
    NNE_LIGHTSET_PS2_TYPE_PA3_PO4_SPO0_SPE0 = 2,
    NNE_LIGHTSET_PS2_TYPE_PA2_PO4_SPO0_SPE1 = 3,
    NNE_LIGHTSET_PS2_TYPE_PA3_PO2_SPO2_SPE0 = 4,
    NNE_LIGHTSET_PS2_TYPE_PA2_PO2_SPO2_SPE1 = 5,
    NNE_LIGHTSET_PS2_TYPE_MAX = 6,
};

// total size: 0x20
struct NNS_PS2_LIGHTSET {
    enum NNE_LIGHTSET_PS2_TYPE fType; // offset 0x0, size 0x4
    unsigned int nLight[4];           // offset 0x4, size 0x10
    unsigned int nTotal;              // offset 0x14, size 0x4
    enum NNE_BOOL fOk;                // offset 0x18, size 0x4
    enum NNE_BOOL fTmpOk;             // offset 0x1C, size 0x4
};

// total size: 0x8
struct NNS_LIGHTPTR {
    unsigned int fType; // offset 0x0, size 0x4
    void* pLight;       // offset 0x4, size 0x4
};

// total size: 0x24
struct NNS_LIGHT_PARALLEL {
    unsigned int User;           // offset 0x0, size 0x4
    struct NNS_RGBA Color;       // offset 0x4, size 0x10
    float Intensity;             // offset 0x14, size 0x4
    struct NNS_VECTOR Direction; // offset 0x18, size 0xC
};

// total size: 0x2C
struct NNS_LIGHT_POINT {
    unsigned int User;          // offset 0x0, size 0x4
    struct NNS_RGBA Color;      // offset 0x4, size 0x10
    float Intensity;            // offset 0x14, size 0x4
    struct NNS_VECTOR Position; // offset 0x18, size 0xC
    float FallOffStart;         // offset 0x24, size 0x4
    float FallOffEnd;           // offset 0x28, size 0x4
};

// total size: 0x20
struct NNS_LIGHT_SPECULAR_PS2 {
    unsigned int User;           // offset 0x0, size 0x4
    struct NNS_RGBA Color;       // offset 0x4, size 0x10
    struct NNS_VECTOR Direction; // offset 0x14, size 0xC
};

// total size: 0x40
struct NNS_LIGHT_TARGET_DIRECTIONAL {
    unsigned int User;          // offset 0x0, size 0x4
    struct NNS_RGBA Color;      // offset 0x4, size 0x10
    float Intensity;            // offset 0x14, size 0x4
    struct NNS_VECTOR Position; // offset 0x18, size 0xC
    struct NNS_VECTOR Target;   // offset 0x24, size 0xC
    float InnerRange;           // offset 0x30, size 0x4
    float OuterRange;           // offset 0x34, size 0x4
    float FallOffStart;         // offset 0x38, size 0x4
    float FallOffEnd;           // offset 0x3C, size 0x4
};

// total size: 0x44
struct NNS_LIGHT_ROTATION_DIRECTIONAL {
    unsigned int User;              // offset 0x0, size 0x4
    struct NNS_RGBA Color;          // offset 0x4, size 0x10
    float Intensity;                // offset 0x14, size 0x4
    struct NNS_VECTOR Position;     // offset 0x18, size 0xC
    enum NNE_ROTATETYPE RotType;    // offset 0x24, size 0x4
    struct NNS_ROTATE_A32 Rotation; // offset 0x28, size 0xC
    float InnerRange;               // offset 0x34, size 0x4
    float OuterRange;               // offset 0x38, size 0x4
    float FallOffStart;             // offset 0x3C, size 0x4
    float FallOffEnd;               // offset 0x40, size 0x4
};

// total size: 0x44
struct NNS_LIGHT_ROTATION_SPOT {
    unsigned int User;              // offset 0x0, size 0x4
    struct NNS_RGBA Color;          // offset 0x4, size 0x10
    float Intensity;                // offset 0x14, size 0x4
    struct NNS_VECTOR Position;     // offset 0x18, size 0xC
    enum NNE_ROTATETYPE RotType;    // offset 0x24, size 0x4
    struct NNS_ROTATE_A32 Rotation; // offset 0x28, size 0xC
    signed int InnerAngle;          // offset 0x34, size 0x4
    signed int OuterAngle;          // offset 0x38, size 0x4
    float FallOffStart;             // offset 0x3C, size 0x4
    float FallOffEnd;               // offset 0x40, size 0x4
};

// total size: 0x40
struct NNS_LIGHT_TARGET_SPOT {
    unsigned int User;          // offset 0x0, size 0x4
    struct NNS_RGBA Color;      // offset 0x4, size 0x10
    float Intensity;            // offset 0x14, size 0x4
    struct NNS_VECTOR Position; // offset 0x18, size 0xC
    struct NNS_VECTOR Target;   // offset 0x24, size 0xC
    signed int InnerAngle;      // offset 0x30, size 0x4
    signed int OuterAngle;      // offset 0x34, size 0x4
    float FallOffStart;         // offset 0x38, size 0x4
    float FallOffEnd;           // offset 0x3C, size 0x4
};

extern struct NNS_PS2_LIGHTSET nngLightSet[2];
extern float nngUnitMatrix[4][4];

void nnInitLight(void);
void nnSetAmbientColor(float r, float g, float b);
void nnSetLightSwitch(enum NNE_LIGHT no, enum NNE_BOOL on_off);
void nnSetLightColor(enum NNE_LIGHT no, float r, float g, float b);
void nnSetLightPosition(enum NNE_LIGHT no, float x, float y, float z);
void nnSetLightType(enum NNE_LIGHT no, unsigned int type);
void nnSetLightDirection(enum NNE_LIGHT no, float x, float y, float z);
void nnSetLightIntensity(enum NNE_LIGHT no, float intensity);
void nnSetUpParallelLight(struct NNS_LIGHT_PARALLEL* light,
                          struct NNS_RGBA* color,
                          float inten,
                          struct NNS_VECTOR* dir);
void nnSetUpPointLight(struct NNS_LIGHT_POINT* light,
                       struct NNS_RGBA* color,
                       float inten,
                       struct NNS_VECTOR* pos,
                       float falloffstart,
                       float falloffend);
void nnSetUpSpecularLightPS2(struct NNS_LIGHT_SPECULAR_PS2* light,
                             struct NNS_RGBA* color,
                             struct NNS_VECTOR* dir);
void nnSetUpTargetDirectionalLight(struct NNS_LIGHT_TARGET_DIRECTIONAL* light,
                                   struct NNS_RGBA* color,
                                   float inten,
                                   struct NNS_VECTOR* pos,
                                   struct NNS_VECTOR* target,
                                   float innerrange,
                                   float outerrange,
                                   float falloffstart,
                                   float falloffend);
unsigned int nnEstimateLightBufferSize(unsigned int type);
void nnSetLight(enum NNE_LIGHT no, void* light, unsigned int type);
void nnSetLightSpecularLightPS2(enum NNE_LIGHT no,
                                void* light,
                                unsigned int type,
                                unsigned int flag);
void nnSetLightMatrix(float (*mtx)[4][4]);
void nnPutLightSettings(void);

#endif // NNLIGHT_H
