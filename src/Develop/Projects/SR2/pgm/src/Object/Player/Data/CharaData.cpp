#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/CharaData.hpp"

namespace nspChara {
f32 of32BaseHeight;
const stcBasePrfm oasBasePrfm[5] = {};
const stcBasePrfm osWalkPrfm[4] = {};
stcData oasData[19];
s8* oasCharaCode3[19];
u32 oasImageColor[19];
u32 oasImageColorRgb[19];
void (*afloadAdditionalFuncs[19])(stcBinInfo&);
stcMotionFlgs asMotionFlgsDef[8];
stcMotionFlgs asMotionFlgsEgg[8];
stcMotionFlgs asMotionFlgsOther[8];
stcMotionFlgs asMotionFlgsWave[8];
stcMotionFlgs asMotionFlgsBily[8];
enmModelType getCharaModelType(u16 u16GearCtrlNo)
{
    switch (u16GearCtrlNo) {
    case 0x1a:
        return MODEL_TYPE_ADS;
    case 0x17:
        return MODEL_TYPE_CVS;
    case 0x28:
        return MODEL_TYPE_RLL;
    case 0x26:
        return MODEL_TYPE_SNB;
    case 0x38:
        return MODEL_TYPE_SKATE_END;
    default:
        return MODEL_TYPE_DEF;
    }
}
} // namespace nspChara
