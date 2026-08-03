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
} // namespace nspChara

enum enmModelType getCharaModelType(u16 u16GearCtrlNo)
{
    enmModelType eVar1;
    if (u16GearCtrlNo == 0x38) {
        eVar1 = MODEL_TYPE_SKATE_END;
    } else if (u16GearCtrlNo == 0x26) {
        eVar1 = MODEL_TYPE_SNB;
    } else if (u16GearCtrlNo == 0x28) {
        eVar1 = MODEL_TYPE_RLL;
    } else if (u16GearCtrlNo == 0x17) {
        eVar1 = MODEL_TYPE_CVS;
    } else if (u16GearCtrlNo == 0x1a) {
        eVar1 = MODEL_TYPE_ADS;
    } else {
        eVar1 = MODEL_TYPE_DEF;
    }
    return eVar1;
}
