#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/TrickData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/TrickMotionTable/TrickMotionTableFlip.hpp"

namespace nspAgp {
static f32 toaf32BonusTrick[7] = {20.0f, 25.0f, 30.0f, 35.0f, 40.0f, 50.0f, 60.0f};
}

void clsBaseTrickAction::settingTrickParam(clsTrickParam& rcParam)
{
}

enmKickerRankZone clsBaseTrickAction::checkTrickRankZone(clsTrickParam& rcParam)
{
    return FAILURE__ZONE;
}

u8 clsBaseTrickAction::calcKickerType(clsTrickParam& rcParam)
{
    return 0;
}

void clsBaseTrickAction::calcTrickRank(clsTrickParam& rcParam, f32 of32LengthRate)
{
}

s32 clsBaseTrickAction::setKeyRecord(clsTrickParam& rcParam)
{
    return 0;
}

void clsBaseTrickAction::initCommon(clsTrickParam& rcParam)
{
}

void clsBaseTrickAction::exitCommon(clsTrickParam& rcParam)
{
}

void clsBaseTrickAction::calcRotateRad(clsTrickParam& rcParam,
                                       f32 of32ActionFrame,
                                       s16 os16RotateDeg,
                                       s8 os8RotDir)
{
}

void clsBaseTrickAction::setTrickMotion(clsTrickParam& rcParam,
                                        f32 of32MotionFrame,
                                        f32 of32LinkFrame)
{
}

void clsBaseTrickAction::setFallMotion(clsTrickParam& rcParam)
{
}

void clsBaseTrickAction::actionRotateMotion(clsTrickParam& rcParam,
                                            f32 of32Frame,
                                            f32 of32TotalFrame)
{
}

void clsBaseTrickAction::applyGearAbility(clsTrickParam& rcParam)
{
}

void clsBaseTrickAction::updateBingoConrol(clsTrickParam& rcParam)
{
}
