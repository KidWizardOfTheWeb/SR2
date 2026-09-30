#ifndef GEARDATA_HPP
#define GEARDATA_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnDraw2d.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/IonMist/IonMist.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/CtrlData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/Gear.hpp"

namespace nspGear {
extern c8* oasMotionGearNameCode2[8];
extern f32 tof32OneRingAddSpeed;

c8* getGearCtrlBinName(u16 u16GearCtrlNo);
u16 getGearCtrlNoForModel(u16 u16GearCtrlNo, u8 u8CharaNo);
enmDraw2DType getGearDraw2DType(enmGear eGear);
} // namespace nspGear

#endif // GEARDATA_HPP
