#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/GravityControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Config/nspGCtrl.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static clsBackLineEffectTask::stcParam oasGCtrlLineParam = {2,
                                                            1,
                                                            0xFF,
                                                            0xFF,
                                                            37,
                                                            16,
                                                            0xFFFFFFFF,
                                                            0.0f,
                                                            1.0f,
                                                            {0.15f, 0.15f, 0.0f, 0.0f},
                                                            {0.0f, 0.05f, 0.0f, 0.0f}};
} // namespace

stcCommonSetting clsGravityControl::t_sCommonSetting;

void clsGravityControl::setCommonSetting()
{
}

void clsGravityControl::cancel()
{
}

void clsGravityControl::reset()
{
}

void clsGravityControl::init()
{
}

void clsGravityControl::execute()
{
}

f32 clsGravityControl::calcUsePoint(f32 f32Point)
{
    return 0.0f;
}

void clsGravityControl::calcWeightParam()
{
}

void clsGravityControl::initCommon()
{
}

void clsGravityControl::initMoveCommon()
{
}

void clsGravityControl::initFallCommon()
{
}

void clsGravityControl::endCommon()
{
}

void clsGravityControl::stopEffect()
{
}

void clsGravityControl::selectAngle()
{
}

void clsGravityControl::settingAngle()
{
}

void clsGravityControl::setDashParam(f32 f32BaseSpeed, f32 f32MaxSpeed, f32 f32DashFrame)
{
}

void clsGravityControl::checkChangeGravity()
{
}

void clsGravityControl::adjustVelocity()
{
}

void clsGravityControl::calcRotateMatrix(f32 (*psDstMtx)[4][4])
{
}

void clsGravityControl::calcRotateQuaternion(NNS_QUATERNION* psDstQuat)
{
}

void clsGravityControl::setKeyTable(enmKeyTable eKeyTable, clsPlayerTask* pcPlayer)
{
}
