#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"
#include "Develop/Projects/SR2/pgm/src/Config/nspWheel.hpp"

static nspMotion::enmMotion toeWheelDriftMotionTable[2][2] = {
    {nspMotion::GEAR_CURVE_R1, nspMotion::GEAR_CURVE_L1},
    {nspMotion::GEAR_CURVE_R2, nspMotion::GEAR_CURVE_L2},
};
