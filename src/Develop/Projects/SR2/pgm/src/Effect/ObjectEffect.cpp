#include "Develop/Projects/SR2/pgm/src/Effect/ObjectEffect.hpp"

clsObjectEffect_Task::clsObjectEffect_Task(u32 u32TpI,
                                           s32 s32TypeI,
                                           clsModelType_OB_TX_MO_MA* pcModelI,
                                           u32 eFlagI,
                                           const NNS_VECTORFAST* opsFollowPosFast,
                                           const f32 (*opsFollowMtx)[4][4],
                                           u32 u32ViewNo,
                                           f32 f32WaitFrame)
    : clsBaseEffect_Task(
          u32TpI, s32TypeI, pcModelI, eFlagI, u32ViewNo, PLAYER_00, NODE_POS_MAX, f32WaitFrame)
{
    m_opsFollowPosVecFast = const_cast<NNS_VECTORFAST*>(opsFollowPosFast);
    m_opsFollowMatrix = const_cast<f32(*)[4][4]>(opsFollowMtx);
}

clsObjectEffect_Task::~clsObjectEffect_Task()
{
}

void clsObjectEffect_Task::draw()
{
}
