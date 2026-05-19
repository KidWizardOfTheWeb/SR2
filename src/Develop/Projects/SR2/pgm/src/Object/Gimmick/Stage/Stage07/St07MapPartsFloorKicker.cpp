#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorKicker.hpp"

f32 clsMapPartsFloorKicker_Object::tof32ClipSqDist;
NNS_VECTOR clsMapPartsFloorKicker_Task::tosCollisionHalfSizeVec = {36.0f, 1.5f, 6.5f};

void clsMapPartsFloorKicker_Object::createData()
{
}

clsMapPartsFloorKicker_Task::clsMapPartsFloorKicker_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMapPartsFloorKicker_Task,
                                 clsMapPartsFloorKicker_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18702)
{
}

void clsMapPartsFloorKicker_Task::reset()
{
}

void clsMapPartsFloorKicker_Task::execute()
{
}

void clsMapPartsFloorKicker_Task::draw()
{
}

clsMapPartsFloorKicker_Object::clsMapPartsFloorKicker_Object()
{
}

clsMapPartsFloorKicker_Object::~clsMapPartsFloorKicker_Object()
{
}
