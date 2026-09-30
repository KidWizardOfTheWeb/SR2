#include "Develop/Projects/SR2/pgm/src/Effect/CurveAir/RoboCurv.hpp"

clsRoboCurvEffect_Task::clsRoboCurvEffect_Task(clsModelType_OB_TX_MO_MA* pcModelI,
                                               const NNS_VECTORFAST* opsPosVecFast,
                                               const NNS_QUATERNION* opsQuat)
    : clsBaseEffect_Task(
          0, 0, pcModelI, 0, 0, nspPlayer::PLAYER_00, clsPlayerTask::NODE_POS_MAX, 0.0f)
{
    m_opsFollowPosVecFast = opsPosVecFast;
    m_opsFollowQuat = opsQuat;
}

void clsRoboCurvEffect_Task::execute()
{
}

void clsRoboCurvEffect_Task::draw()
{
}

clsRoboCurvEffect_Task::~clsRoboCurvEffect_Task()
{
}
