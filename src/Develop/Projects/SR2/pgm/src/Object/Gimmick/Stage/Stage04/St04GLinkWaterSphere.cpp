#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04GLinkWaterSphere.hpp"

NNS_VECTOR clsGLinkWaterSphere_Object::tosCollisionHalfSizeVec = {3.0f, 3.0f, 10.0f};
f32 clsGLinkWaterSphere_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsGLinkWaterSphere_Object::t_ocGravityGimmickParam = {
    /* 0x18 */ 10.0f,         /* m_of32GCtrlRiseRandDelayFrame */
    /* 0x1C */ 1.0f,          /* m_of32GCtrlRiseBaseHeight */
    /* 0x20 */ 1.0f,          /* m_of32GCtrlRiseRandHeight */
    /* 0x24 */ 60.0f,         /* m_of32GCtrlRiseFrame */
    /* 0x28 */ 0.5f,          /* m_of32GCtrlFlightTrackRate */
    /* 0x2C */ 25.0f / 27.0f, /* m_of32GCtrlMoveSpeed */
    /* 0x30 */ 60.0f,         /* m_of32GCtrlMoveBaseFrame */
    /* 0x34 */ 30.0f,         /* m_of32GCtrlMoveRandFrame */
    /* 0x5C */ 0.1f,          /* m_of32GDiveRiseBaseHeight */
    /* 0x60 */ 0.1f,          /* m_of32GDiveRiseRandHeight */
    /* 0x64 */ 25.0f / 72.0f, /* m_of32GDiveMoveSpeed */
    /* 0x68 */ 20.0f,         /* m_of32GDiveMoveFrame */
    /* 0x6C */ 10.0f,         /* m_of32GDiveMoveDist */
    /* 0x70 */ 910,           /* m_oa32GLinkAdjustRotate */
    /* 0x74 */ 0.1f,          /* m_of32GLinkAdjustSlerp */
};

void clsGLinkWaterSphere_Object::draw(clsModelType_OB_TX_MO_MA& rcModel,
                                      f32 (*psMtxPal)[4][4],
                                      u32* psNodeStat,
                                      const f32 (*opaNnViewMtx)[4][4],
                                      f32 (*psMtxWork)[4][4],
                                      u32 u32ViewNo)
{
}

void clsGLinkWaterSphere_Object::reset()
{
}

void clsGLinkWaterSphere_Object::main()
{
}

void clsGLinkWaterSphere_Object::mainGravity()
{
}

void clsGLinkWaterSphere_Object::mainCrash()
{
}

void clsGLinkWaterSphere_Object::requestDrawBreakEffect()
{
}

void clsGLinkWaterSphere_Object::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsGLinkWaterSphere_Object::drawEffect(clsPlayerTask* pParam1)
{
}

void clsGLinkWaterSphere_Object::setData()
{
}

void clsGLinkWaterSphere_Object::createData()
{
}

void clsGLinkWaterSphere_Object::destroyData()
{
}

clsGLinkWaterSphere_Task::clsGLinkWaterSphere_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsGLinkWaterSphere_Task,
                                 clsGLinkWaterSphere_Object,
                                 clsModelType_OB_TX_MO_MA>(u32ObjectAreaNum, 0x18A88)
{
}

void clsGLinkWaterSphere_Task::execute()
{
}

void clsGLinkWaterSphere_Task::draw()
{
}

void clsGLinkWaterSphere_Task::reset()
{
}
