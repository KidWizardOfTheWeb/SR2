#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14GLinkBigFan.hpp"

NNS_VECTOR clsGLinkFan_Blade::tosCollisionHalfSizeVec = {4.5f, 1.0f, 7.5f};
f32 clsGLinkFan_Blade::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsGLinkFan_Blade::t_ocSt14GravityGimmickParam;

f32 clsGLinkFan_Object::tof32ClipSqDist = 0.0f;

u8 clsGLinkFan_Blade::draw(NNS_OBJECT* psObject,
                           f32 (*psMtxPal)[4][4],
                           u32* psNodeStat,
                           const f32 (*opaNnViewMtx)[4][4],
                           f32 (*psMtxWork)[4][4],
                           u32 u32ViewNo)
{
    return 0;
}

void clsGLinkFan_Blade::initParam()
{
}

void clsGLinkFan_Blade::reset()
{
}

void clsGLinkFan_Blade::main()
{
}

void clsGLinkFan_Blade::mainGravity()
{
}

void clsGLinkFan_Blade::callbackGravityEvent()
{
}

void clsGLinkFan_Blade::requestDrawBreakEffect()
{
}

void clsGLinkFan_Blade::contactTriggerCallback(hkContactPointConfirmedEvent& cEvent)
{
}

void clsGLinkFan_Blade::createData()
{
}

void clsGLinkFan_Blade::destroyData()
{
}

void clsGLinkFan_Object::draw(clsModelType_OB_TX* psModel,
                              f32 (*psMtxPal)[4][4],
                              u32* psNodeStat,
                              const f32 (*opaNnViewMtx)[4][4],
                              f32 (*psMtxWork)[4][4],
                              u32 u32ViewNo)
{
}

void clsGLinkFan_Object::setData()
{
}

void clsGLinkFan_Object::createData()
{
}

void clsGLinkFan_Object::destroyData()
{
}

clsGLinkFan_Task::clsGLinkFan_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsGLinkFan_Task, clsGLinkFan_Object, clsGLinkFanModel>(u32ObjectAreaNum,
                                                                                 u32ObjectAreaNum)
{
}

void clsGLinkFan_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsGLinkFan_Task::reset()
{
}

void clsGLinkFan_Task::execute()
{
}

void clsGLinkFan_Task::draw()
{
}

clsGLinkFan_Task::~clsGLinkFan_Task()
{
}
