#include "Develop/Projects/SR2/pgm/src/Script/ScriptMotion.hpp"

s32 clsScriptMotion::m_ts32MotionNum;
u8* clsScriptMotion::m_tapu8MotionData[256];
s32 clsScriptMotion::m_ts32MatMotionNum;
u8* clsScriptMotion::m_tapu8MatMotionData[256];
s32 clsScriptMotion::m_ts32MorfMotionNum;
u8* clsScriptMotion::m_tapu8MorfMotionData[256];

void clsScriptMotion::initData()
{
}

void clsScriptMotion::setMotionData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4)
{
}

void clsScriptMotion::setMatMotionData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4)
{
}

void clsScriptMotion::setMorfMotionData(u8* pu8Param1,
                                        u32* pu32Param2,
                                        u16 u16Param3,
                                        u32 u32Param4)
{
}

void clsScriptMotion::setMotion(s32 s32Param1, NNS_MOTION** ppsParam2)
{
}

void clsScriptMotion::setMatMotion(s32 s32Param1,
                                   clsModelType_OB_TX_MO_MA_MF* pcParam2,
                                   NNS_MOTION** ppsParam3,
                                   NNS_OBJECT** ppsParam4,
                                   u32** ppu32Param5)
{
}

void clsScriptMotion::setMorphMotion(s32 s32Param1,
                                     clsModelType_OB_TX_MO_MA_MF* pcParam2,
                                     NNS_MOTION** ppsParam3,
                                     NNS_OBJECT* psParam4,
                                     NNS_OBJECT** ppsParam5,
                                     f32** ppf32Param6)
{
}
