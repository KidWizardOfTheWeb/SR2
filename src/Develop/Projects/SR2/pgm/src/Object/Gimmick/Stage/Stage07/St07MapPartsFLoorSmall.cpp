#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorSmall.hpp"

f32 clsMapPartsFloorSmall_Object::tof32ClipSqDist;
NNS_VECTOR clsMapPartsFloorSmall_Task::tosCollisionHalfSizeVec = {5.0f, 1.5f, 5.0f};

void clsMapPartsFloorSmall_Object::createData()
{
}

clsMapPartsFloorSmall_Task::clsMapPartsFloorSmall_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMapPartsFloorSmall_Task,
                                 clsMapPartsFloorSmall_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18702)
{
}

void clsMapPartsFloorSmall_Task::reset()
{
}

void clsMapPartsFloorSmall_Task::execute()
{
}

void clsMapPartsFloorSmall_Task::draw()
{
}

clsMapPartsFloorSmall_Object::clsMapPartsFloorSmall_Object()
{
}

clsMapPartsFloorSmall_Object::~clsMapPartsFloorSmall_Object()
{
}
