#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorChange.hpp"

NNS_VECTOR clsMapPartsFloorChange_Task::tosCollisionHalfSizeVec = {5.0f, 1.5f, 5.0f};
f32 clsMapPartsFloorChange_Object::tof32ClipSqDist = 0.0f;

void clsMapPartsFloorChange_Object::execute()
{
}

void clsMapPartsFloorChange_Object::StepMotionFrame()
{
}

void clsMapPartsFloorChange_Object::createData()
{
}

void clsMapPartsFloorChange_Object::reset()
{
}

u8 clsMapPartsFloorChange_Object::checkObj(f32 f32Num, bool bPowerFlag)
{
    return 0;
}

u8 clsMapPartsFloorChange_Object::checkObj_Reverse(f32 f32Num, bool bPowerFlag)
{
    return 0;
}

u8 clsMapPartsFloorChange_Object::set_Kicker(f32 f32Num)
{
    return 0;
}

void clsMapPartsFloorChange_Object::destroyData()
{
}

clsMapPartsFloorChange_Task::clsMapPartsFloorChange_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMapPartsFloorChange_Task,
                                 clsMapPartsFloorChange_Object,
                                 clsModelType_OB_TX_MO>(u32ObjectAreaNum, 0x18702)
{
}

void clsMapPartsFloorChange_Task::reset()
{
}

void clsMapPartsFloorChange_Task::execute()
{
}

void clsMapPartsFloorChange_Task::draw()
{
}
