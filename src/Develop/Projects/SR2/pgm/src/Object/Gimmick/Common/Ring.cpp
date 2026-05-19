#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Ring.hpp"

namespace {
static f32 tof32LowPolyDist = 0.0f;
} // namespace

// clsRingBase

void clsRingBase::wakeup()
{
}

void clsRing_Obj::reset()
{
}

void clsRing_Obj::setSleep()
{
}

void clsRing_Obj::createData()
{
}

void clsRing_Obj::destroyData()
{
}

void clsRing_Obj::setPositionPhantom()
{
}

void clsRing_Obj::contactAlwaysEvent(hkContactPoint* pParam1, clsObject* pcObject)
{
}

void clsRing_Obj::requestFollow(clsPlayerTask* pcPlayer, enmFollowType eFollowType)
{
}

u8 clsRing_Obj::execute()
{
    return 0;
}

void clsRingCrash_Obj::setSleep()
{
}

void clsRingCrash_Obj::createData()
{
}

void clsRingCrash_Obj::destroyData()
{
}

void clsRingCrash_Obj::setPositionRigid()
{
}

void clsRingCrash_Obj::setCrushParam(const NNS_VECTORFAST& rsPosVecFast,
                                     const NNS_QUATERNION& rsRotQuat,
                                     const NNS_VECTORFAST& rsVelocityFast)
{
}

void clsRingCrash_Obj::contactAlwaysEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsRingCrash_Obj::requestFollow(clsPlayerTask* pcPlayer, enmFollowType eFollowType)
{
}

u8 clsRingCrash_Obj::execute()
{
    return 0;
}

void clsRingCrash_Obj::draw(clsModelType_OB_TX& rParam1,
                            f32 (*)[4][4],
                            u32* pParam3,
                            const f32 (*)[4][4],
                            u32 u32Param5,
                            f32 (*)[4][4],
                            u32 u32Param7)
{
}

void clsRingFollow_Obj::regist(clsPlayerTask* pcPlayer,
                               enmFollowType eFollowType,
                               const NNS_VECTORFAST& rcPosVecFast,
                               f32 f32WaitFrame,
                               clsRingBase* pcParent)
{
}

u8 clsRingFollow_Obj::followLine()
{
    return 0;
}

u8 clsRingFollow_Obj::followCircel()
{
    return 0;
}

u8 clsRingFollow_Obj::execute()
{
    return 0;
}

void clsRingFollow_Obj::draw(clsModelType_OB_TX& rcObj,
                             f32 (*psMtxPal)[4][4],
                             u32* psNodeStat,
                             const f32 (*opaNnViewMtx)[4][4],
                             u32 u32RotY,
                             f32 (*psMtxWork)[4][4],
                             u32 u32ViewNo)
{
}

void clsRing_Task::reset()
{
}

void clsRing_Task::execute()
{
}

void clsRing_Task::draw()
{
}

void clsRing_Task::createDrawRingWork()
{
}

void clsRing_Task::setCrashRing(clsPlayerTask* pcPlayerTask)
{
}

void clsRing_Task::setFollowRing(clsPlayerTask* pcPlayerTask,
                                 u8 u8Num,
                                 enmFollowType eFollowType,
                                 f32 f32WaitIntervalFrame,
                                 const NNS_VECTORFAST& rsPosVecFast,
                                 clsRingBase* pcRingObj)
{
}

void clsRingCrash_Obj::drawCollision()
{
}

void clsRingCrash_Obj::destroyCollision()
{
}

void clsRingCrash_Obj::updateSetEditorCollision()
{
}

void clsRing_Obj::draw(clsModelType_OB_TX& rParam1,
                       f32 (*)[4][4],
                       u32* pParam3,
                       const f32 (*)[4][4],
                       u32 u32Param5,
                       f32 (*)[4][4],
                       u32 u32Param7)
{
}

void clsRing_Obj::drawCollision()
{
}

void clsRing_Obj::destroyCollision()
{
}

void clsRing_Obj::updateSetEditorCollision()
{
}
