#include "Develop/Projects/SR2/pgm/src/Script/ScriptLight.hpp"

namespace nspDefaultScriptLightData {
struct stcRgbaF32 {
    f32 f32r;
    f32 f32g;
    f32 f32b;
    f32 f32a;
};

struct stcBinDataDetail {
    stcRgbF32 sAmbientRgb;
    stcRgbaF32 sParallelRgba;
    f32 f32ParallelInten;
    NNS_VECTOR sParallelDir;
    NNS_VECTOR sParallelPos;
    stcRgbaF32 sSpecularRgba;
    NNS_VECTOR sSpecularDir;
};

static stcBinDataDetail otasDefaultDataDetail = {{1.0f, 1.0f, 1.0f},
                                                 {1.0f, 1.0f, 1.0f, 1.0f},
                                                 1.0f,
                                                 {0.0f, -1.0f, 0.0f},
                                                 {0.0f, 1000.0f, 0.0f},
                                                 {0.5f, 0.5f, 0.5f, 1.0f},
                                                 {0.0f, -1.0f, 0.0f}};
} // namespace nspDefaultScriptLightData

clsScriptLight::clsScriptLight()
{
}

void clsScriptLight::setupBinLightMotion(NNS_LIGHTPTR** pParam1,
                                         NNS_MOTION** pParam2,
                                         void* pvParam3)
{
}

void clsScriptLight::setSpecureLight(NNE_LIGHT, NNS_LIGHTPTR* pParam2)
{
}

void clsScriptLight::setLightAll()
{
}

void clsScriptLight::setLight()
{
}

void clsScriptLight::setLightAmb(f32 f32Param1, f32 f32Param2, f32 f32Param3)
{
}

void clsScriptLight::setLightPar(s32 s32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4)
{
}

void clsScriptLight::setLightParInten(s32 s32Param1, f32 f32Param2)
{
}

void clsScriptLight::setLightParDir(s32 s32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4)
{
}

void clsScriptLight::setLightSpe(f32 f32Param1, f32 f32Param2, f32 f32Param3)
{
}

void clsScriptLight::setLightSpeDir(f32 f32Param1, f32 f32Param2, f32 f32Param3)
{
}

void clsScriptLight::setLightData(u32 u32Param1, u32 u32Param2)
{
}

void clsScriptLight::setLightDisp(u32 u32Param1, bool bParam2)
{
}

clsScriptLight::~clsScriptLight()
{
}
