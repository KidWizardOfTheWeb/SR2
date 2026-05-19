#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15GLinkFloorBoard.hpp"

NNS_VECTOR clsGLinkFloorBoard_Object::tosCollisionHalfSizeVec = {3.1f, 0.6f, 11.6f};
f32 clsGLinkFloorBoard_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsGLinkFloorBoard_Object::t_ocGravityGimmickParam;

void clsGLinkFloorBoard_Object::draw(NNS_OBJECT* psObject,
                                     f32 (*psMtxPal)[4][4],
                                     u32* psNodeStat,
                                     const f32 (*opaNnViewMtx)[4][4],
                                     f32 (*psMtxWork)[4][4],
                                     u32 u32ViewNo)
{
}

void clsGLinkFloorBoard_Object::reset()
{
}

void clsGLinkFloorBoard_Object::main()
{
}

void clsGLinkFloorBoard_Object::mainGravity()
{
}

void clsGLinkFloorBoard_Object::requestDrawBreakEffect()
{
}

void clsGLinkFloorBoard_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsGLinkFloorBoard_Object::setData()
{
}

void clsGLinkFloorBoard_Object::createData()
{
}

void clsGLinkFloorBoard_Object::destroyData()
{
}

clsGLinkFloorBoard_Task::clsGLinkFloorBoard_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsGLinkFloorBoard_Task::execute()
{
}

void clsGLinkFloorBoard_Task::draw()
{
}

void clsGLinkFloorBoard_Task::reset()
{
}

void clsGLinkFloorBoard_Task::startGActionCheck(s32 os32HP)
{
}

void clsGLinkFloorBoard_Task::endGActionCheck()
{
}

void clsGLinkFloorBoard_Task::rebirthSetFloorBoard()
{
}
