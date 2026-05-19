#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13PT_Wall.hpp"

f32 clsPT_Wall_Parts::tof32ClipSqDist = 0.0f;

void clsPT_Wall_Parts::reset()
{
}

void clsPT_Wall_Parts::createData()
{
}

void clsPT_Wall_Parts::destroyData()
{
}

void clsPT_Wall_Parts::main()
{
}

void clsPT_Wall_Parts::draw(
    clsModelType_OB_TX& rParam1, f32 (*)[4][4], u32* pParam3, const f32 (*)[4][4], f32 (*)[4][4])
{
}

void clsPT_Wall_Parts::callbackGravityEvent()
{
}

void clsPT_Wall_Parts::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsPT_Wall_Parts::requestDrawBreakEffect()
{
}

void clsPT_Wall_Obj::reset()
{
}

void clsPT_Wall_Obj::setData()
{
}

void clsPT_Wall_Obj::createData()
{
}

void clsPT_Wall_Obj::destroyData()
{
}

clsPT_Wall_Task::clsPT_Wall_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsPT_Wall_Task, clsPT_Wall_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsPT_Wall_Task::reset()
{
}

void clsPT_Wall_Task::execute()
{
}

void clsPT_Wall_Task::draw()
{
}
