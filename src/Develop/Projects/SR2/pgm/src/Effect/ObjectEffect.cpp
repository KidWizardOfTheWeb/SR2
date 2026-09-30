#include "Develop/Projects/SR2/pgm/src/Effect/ObjectEffect.hpp"

clsObjectEffect_Task::clsObjectEffect_Task(u32 u32TpI,
                                           s32 s32TypeI,
                                           clsModelType_OB_TX_MO_MA* pcModelI,
                                           u32 eFlagI,
                                           const NNS_VECTORFAST* opsFollowPosFast,
                                           const NNS_MATRIX* opsFollowMtx,
                                           u32 u32ViewNo,
                                           f32 f32WaitFrame)
    : clsBaseEffect_Task(u32TpI,
                         s32TypeI,
                         pcModelI,
                         eFlagI,
                         u32ViewNo,
                         nspPlayer::PLAYER_00,
                         clsPlayerTask::NODE_POS_MAX,
                         f32WaitFrame)
{
    m_opsFollowPosVecFast = opsFollowPosFast;
    m_opsFollowMatrix = opsFollowMtx;
}

clsObjectEffect_Task::~clsObjectEffect_Task()
{
}

void clsObjectEffect_Task::draw()
{
}
