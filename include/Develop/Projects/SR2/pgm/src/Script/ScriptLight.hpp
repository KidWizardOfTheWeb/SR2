#ifndef SCRIPTLIGHT_HPP
#define SCRIPTLIGHT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Light/nnlight.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

// total size: 0xC
struct stcRgbF32 {
    f32 f32r; // offset 0x0, size 0x4
    f32 f32g; // offset 0x4, size 0x4
    f32 f32b; // offset 0x8, size 0x4
};

// total size: 0x24
struct stcParallelLight {
    u8 bUsed;        // offset 0x0, size 0x1
    u8 bDisabled;    // offset 0x1, size 0x1
    NNS_RGBA sRgba;  // offset 0x4, size 0x10
    f32 f32Inten;    // offset 0x14, size 0x4
    NNS_VECTOR sDir; // offset 0x18, size 0xC
};

// total size: 0x48
struct stcLight {
    u8 bUsed;           // offset 0x0, size 0x1
    s32 s32No;          // offset 0x4, size 0x4
    stcRgbF32 sAmb;     // offset 0x8, size 0xC
    stcRgbF32 sPar;     // offset 0x14, size 0xC
    f32 f32ParInten;    // offset 0x20, size 0x4
    NNS_VECTOR sParDir; // offset 0x24, size 0xC
    stcRgbF32 sSpe;     // offset 0x30, size 0xC
    NNS_VECTOR sSpeDir; // offset 0x3C, size 0xC
};

// total size: 0x14
struct stcSunLenz {
    u8 bUsed;        // offset 0x0, size 0x1
    u8 bEnd;         // offset 0x1, size 0x1
    NNS_VECTOR sPos; // offset 0x4, size 0xC
    f32 f32Scale;    // offset 0x10, size 0x4
};

// total size: 0x128
struct stcLightValue {
    u8 u8Flg;                       // offset 0x0, size 0x1
    stcRgbF32 sAmb;                 // offset 0x4, size 0xC
    NNS_RGBA sSpe;                  // offset 0x10, size 0x10
    NNS_VECTOR sSpeDir;             // offset 0x20, size 0xC
    stcParallelLight asParLight[7]; // offset 0x2C, size 0xFC
};

// total size: 0x10
struct stcLightData {
    u8 bUsed;                // offset 0x0, size 0x1
    u8 u8LightNo;            // offset 0x1, size 0x1
    f32 f32Frame;            // offset 0x4, size 0x4
    NNS_LIGHTPTR* psDataPtr; // offset 0x8, size 0x4
    NNS_MOTION* psMotion;    // offset 0xC, size 0x4
};

// total size: 0x560
class clsScriptLight {
public:
    inline clsScriptLight();
    virtual ~clsScriptLight();

    stcLightValue m_asLightValue[2];  // offset 0x4, size 0x250
    stcLightData m_asLightData[2][8]; // offset 0x254, size 0x100
    void* m_pavLightData[128];        // offset 0x354, size 0x200
    u8 m_u8ValueType;                 // offset 0x554, size 0x1
    s32 m_s32DataNum;                 // offset 0x558, size 0x4
    NNS_LIGHTPTR* m_psCalcLight;      // offset 0x55C, size 0x4

    void setupBinLightMotion(NNS_LIGHTPTR** pParam1, NNS_MOTION** pParam2, void* pvParam3);
    void setSpecureLight(NNE_LIGHT, NNS_LIGHTPTR* pParam2);
    void setLightAll();
    void setLight();
    void setLightAmb(f32 f32Param1, f32 f32Param2, f32 f32Param3);
    void setLightPar(s32 s32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4);
    void setLightParInten(s32 s32Param1, f32 f32Param2);
    void setLightParDir(s32 s32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4);
    void setLightSpe(f32 f32Param1, f32 f32Param2, f32 f32Param3);
    void setLightSpeDir(f32 f32Param1, f32 f32Param2, f32 f32Param3);
    void setLightData(u32 u32Param1, u32 u32Param2);
    void setLightDisp(u32 u32Param1, bool bParam2);
};

#endif // SCRIPTLIGHT_HPP
