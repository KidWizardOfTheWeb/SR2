#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GearData.hpp"

static u8 chk__oasMotionGearNameCode2_SizeCheck_[1];

namespace nspGear {
c8* oasMotionGearNameCode2[8] = {"wk", "bd", "bk", "sk", "ar", "wh", "sf", "sw"};
f32 tof32OneRingAddSpeed = 0.002314814832061529f;
} // namespace nspGear

c8* getGearCtrlBinName(u16 u16GearCtrlNo)
{
    return 0;
}

u16 getGearCtrlNoForModel(u16 u16GearCtrlNo, u8 u8CharaNo)
{
    return 0;
}

enmDraw2DType getGearDraw2DType(enmGear eGear)
{
    return TYPE_2D_BOARD;
}
