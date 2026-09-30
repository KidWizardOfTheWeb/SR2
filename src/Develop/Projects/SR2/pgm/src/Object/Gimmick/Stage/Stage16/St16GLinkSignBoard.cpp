#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage16/St16GLinkSignBoard.hpp"

f32 clsGLinkSignBoard_Obj::tof32ClipSqDist = 0.0f;
NNS_VECTOR clsGLinkSignBoard_Obj::tosCollisionHalfSizeVec = {1.0f, 10.0f, 18.0f};

void clsGLinkSignBoard_Obj::reset()
{
}

void clsGLinkSignBoard_Obj::requestDrawBreakEffect()
{
}

void clsGLinkSignBoard_Obj::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsGLinkSignBoard_Obj::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsGLinkSignBoard_Obj::setData()
{
}

void clsGLinkSignBoard_Obj::createData()
{
}

void clsGLinkSignBoard_Obj::destroyData()
{
}

void clsGLinkSignBoard_Obj::main()
{
}

void clsGLinkSignBoard_Obj::draw(clsModelType_OB_TX* apcModel,
                                 NNS_MATRIX* psMtxPal,
                                 u32* psNodeStat,
                                 const NNS_MATRIX* opaNnViewMtx,
                                 NNS_MATRIX* psMtxWork,
                                 u32 u32ViewNo)
{
}

clsGLinkSignBoard_Task::clsGLinkSignBoard_Task(u32 u32ObjectAreaNum)
    : clsMultiModelGimmick_Task<clsGLinkSignBoard_Task, clsGLinkSignBoard_Obj, clsSignBoardModel>(
          u32ObjectAreaNum, 99999)
{
}

void clsGLinkSignBoard_Task::reset()
{
}

void clsGLinkSignBoard_Task::execute()
{
}

void clsGLinkSignBoard_Task::draw()
{
}

NNS_VECTOR* clsGLinkSignBoard_Obj::getCollisionHalfSizeVecPtr() const
{
    return &tosCollisionHalfSizeVec;
}
