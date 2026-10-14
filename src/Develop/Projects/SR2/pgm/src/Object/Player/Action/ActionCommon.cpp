#include "Develop/Projects/SR2/pgm/src/Object/Player/Action/ActionCommon.hpp"
#include "Develop/Projects/SR2/pgm/src/Config/nspWheel.hpp"

namespace nspAgp {
f32 toaf32BonusPower[6] = {2.5f, 5.0f, 7.5f, 10.0f, 12.5f, 15.0f};
} // namespace nspAgp

static u8 chk__clsPlayerTask_t_sActionFuncTbl_SizeCheck_[1];

void clsPlayerTask::setActionType(clsPlayerTask::enmActionType eType)
{
}

void clsPlayerTask::updateAction()
{
}

void clsPlayerTask::initCommonRun()
{
}

void clsPlayerTask::initCommonFlight()
{
}

void clsPlayerTask::vibrationLanding()
{
}

void clsPlayerTask::vibrationCurve()
{
}

void clsPlayerTask::registanceFlightSpeed()
{
}

void clsPlayerTask::registanceFlightFloating(f32 f32Accele)
{
}

void clsPlayerTask::checkBrake()
{
}

void clsPlayerTask::checkGDive()
{
}

void clsPlayerTask::checkGCtrlSlide()
{
}

void clsPlayerTask::checkGCtrlTrick()
{
}

void clsPlayerTask::checkGCtrlFlight()
{
}

void clsPlayerTask::checkGearChange()
{
}

void clsPlayerTask::requestFlightAction()
{
}

void clsPlayerTask::requestJumpOrTrick()
{
}

void clsPlayerTask::initFixedSpeed(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::initFreeAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::initFrameAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::initRateAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::actionFixedSpeed(const clsPathData::stcLine* pParam1)
{
}

void clsPlayerTask::actionFreeAccele(const clsPathData::stcLine* pParam1)
{
}

void clsPlayerTask::actionFrameAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::actionRateAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::endMovePath()
{
}

void clsPlayerTask::acceleWalk()
{
}

void clsPlayerTask::curveWalk(f32 f32Ratio)
{
}

u32 clsPlayerTask::checkRailAction()
{
    return 0;
}

void clsPlayerTask::setCollisionFilterWalk()
{
}

void clsPlayerTask::clearCollisionFilterWalk()
{
}

void clsPlayerTask::checkDirectionRegulation()
{
}

void clsPlayerTask::clearMoveSubParam()
{
}

void clsPlayerTask::breakObstacle()
{
}

void clsPlayerTask::updateObstacle()
{
}

void clsPlayerTask::useRingGear()
{
}
