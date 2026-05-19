#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Turbulence.hpp"

f32 clsTurbulence_Obj::CLIP_DISTx2 = 0.0f;
f32 clsPutTurbulence_Obj::CLIP_DISTx2 = 0.0f;
f32 clsPutTurbulence_Obj::tf32TrickDeg = 5.0f;
u32 TURB_PARAM;
f32 tf32AdjustY;
f32 tf32BodyLength;
f32 tf32EndLength;
f32 tf32StartLength;
f32 tf32StartModelOKMotionFrm;

void clsTurbThroughColli::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsTurbThroughColli::contactRemoveEvent(clsPlayerTask* pcPlayer)
{
}

void clsTurbThroughColli::contactAlwaysEvent(clsPlayerTask* pcPlayer)
{
}

void clsTurbulence_Obj::init(
    u32 u32Num,
    clsModelType_OB_TX_MO_MA* pcModel,
    std::vector<clsRigidBody*, std::allocator<clsRigidBody*> >* pvecpcRigid,
    std::vector<clsRigidBody*, std::allocator<clsRigidBody*> >* pvecpcWallRigid)
{
}

void clsTurbulence_Obj::trigThroughTurb(clsPlayerTask* pcPlayer, u32 u32ColIdx)
{
}

void clsTurbulence_Obj::addTurbThroughColli(clsRigidBody* pcRigid, u32 u32Index)
{
}

void clsTurbulence_Obj::execute()
{
}

void clsTurbulence_Obj::draw(clsModelType_OB_TX_MO_MA& rcObj,
                             clsModelType_OB_TX_MO_MA& rcAObj,
                             f32 (*psMtxPal)[4][4],
                             u32* psNodeStat,
                             const f32 (*opaNnViewMtx)[4][4])
{
}

void clsTurbulence_Obj::createData()
{
}

void clsTurbulence_Obj::destroyData()
{
}

clsRigidBody* clsTurbulence_Task::create(hkShape* pcShape,
                                         const clsGroundCollision::stcInfo* psInfo,
                                         clsTurbulence_Obj::stcTurbInfo* psTurbInfo,
                                         u8 u8IsCreateThrough)
{
    return 0;
}

void clsTurbulence_Task::parseColliData(const clsGroundCollision::stcBinBody* psBody,
                                        u32 u32Num,
                                        clsTurbulence_Obj* pcTurbObj,
                                        u32 u32Idx)
{
}

void clsTurbulence_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsTurbulence_Task::execute()
{
}

void clsTurbulence_Task::draw()
{
}

void clsPutTurbulence_Obj::init(u32 u32Num, stcSt04TurbModel* psModels, clsRigidBody*** ppcRigid)
{
}

void clsPutTurbulence_Obj::startTurb(const NNS_VECTORFAST* psNowPosVF)
{
}

void clsPutTurbulence_Obj::finishTurb()
{
}

void clsPutTurbulence_Obj::updateCol()
{
}

void clsPutTurbulence_Obj::clearCol()
{
}

void clsPutTurbulence_Obj::execute()
{
}

void clsPutTurbulence_Obj::draw(stcSt04TurbModel& rcObj,
                                f32 (*psMtxPal)[4][4],
                                u32* psNodeStat,
                                const f32 (*opaNnViewMtx)[4][4])
{
}

void clsPutTurbulence_Obj::createData()
{
}

void clsPutTurbulence_Obj::destroyData()
{
}

void clsPutTurbulence_Task::parseColliData(const clsGroundCollision::stcBinBody* psBody,
                                           u32 u32Num,
                                           u32 u32Idx)
{
}

void clsPutTurbulence_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsPutTurbulence_Task::execute()
{
}

void clsPutTurbulence_Task::draw()
{
}

void clsTurbulence_Task::reset()
{
}

void clsPutTurbulence_Obj::reset()
{
}

void clsPutTurbulence_Task::reset()
{
}

clsPutTurbulence_Task::clsPutTurbulence_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody(u32ObjectAreaNum, 0)
{
}
