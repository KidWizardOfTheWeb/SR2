#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"
#include "Develop/Projects/SR2/pgm/src/Config/nspCurve.hpp"

void clsGearBasePrototype::clearChangeActionParam()
{
}

enmChangeRes clsGearBasePrototype::changeRide(clsGear** ppcPartsGears,
                                              clsGear* pcBaseGear,
                                              f32 f32LinkFrame,
                                              nspMotion::enmMotion eMotion)
{
    return CTRL_RES_END;
}

enmChangeRes clsGearBasePrototype::changeWalk(clsGear** apcEquipsGears,
                                              f32 f32LinkFrame,
                                              nspMotion::enmMotion eMotion)
{
    return CTRL_RES_END;
}

enmChangeRes clsGearBasePrototype::changeHideWalk(clsGear** apcEquipsGears)
{
    return CTRL_RES_END;
}

enmChangeRes clsGearBasePrototype::initRideChangeAction(clsGear** pParam1, clsGear* pParam2)
{
    return CTRL_RES_END;
}

enmChangeRes clsGearBasePrototype::execRideChangeAction(clsGear** pParam1, clsGear* pParam2)
{
    return CTRL_RES_END;
}

enmChangeRes clsGearBasePrototype::initWalkChangeAction(clsGear** pParam1)
{
    return CTRL_RES_END;
}

enmChangeRes clsGearBasePrototype::execWalkChangeAction(clsGear** pParam1)
{
    return CTRL_RES_END;
}

enmChangeRes clsGearBasePrototype::initGearChange(clsGear** pcOldGear, clsGear* pParam2)
{
    return CTRL_RES_END;
}

enmChangeRes clsGearBasePrototype::execGearChange(clsGear** pcOldGear, clsGear* pParam2)
{
    return CTRL_RES_END;
}

void clsGearBasePrototype::controlMotion()
{
}

void clsGearBasePrototype::controlMotionCurve00()
{
}

void clsGearBasePrototype::controlMotionCurve01()
{
}

void clsGearBasePrototype::controlMotionFlyCurve()
{
}

f32 clsGearBasePrototype::calcCurveRadResult(f32 f32Rate)
{
    return 0.0f;
}

void clsGearBasePrototype::Accele()
{
}

void clsGearBasePrototype::Brake()
{
}

void clsGearBasePrototype::Curve(f32 f32Ratio)
{
}

void clsGearBasePrototype::setCurveEffect()
{
}

void clsGearBasePrototype::rebuildGearRunSe()
{
}

u8 clsGearBasePrototype::rebuildGearFlySe()
{
    return 0;
}
