#ifndef SCRIPTMOTION_HPP
#define SCRIPTMOTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

class clsScriptMotion {
public:
    static void initData();
    static void setMotionData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4);
    static void setMatMotionData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4);
    static void setMorfMotionData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4);
    static void setMotion(s32 s32Param1, NNS_MOTION** ppsParam2);
    static void setMatMotion(s32 s32Param1,
                             clsModelType_OB_TX_MO_MA_MF* pcParam2,
                             NNS_MOTION** ppsParam3,
                             NNS_OBJECT** ppsParam4,
                             u32** ppu32Param5);
    static void setMorphMotion(s32 s32Param1,
                               clsModelType_OB_TX_MO_MA_MF* pcParam2,
                               NNS_MOTION** ppsParam3,
                               NNS_OBJECT* psParam4,
                               NNS_OBJECT** ppsParam5,
                               f32** ppf32Param6);

    static s32 m_ts32MotionNum;
    static u8* m_tapu8MotionData[256];
    static s32 m_ts32MatMotionNum;
    static u8* m_tapu8MatMotionData[256];
    static s32 m_ts32MorfMotionNum;
    static u8* m_tapu8MorfMotionData[256];
};

#endif // SCRIPTMOTION_HPP
