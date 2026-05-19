#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorBig.hpp"

f32 clsMapPartsFloorBig_Object::tof32ClipSqDist;
NNS_VECTOR clsMapPartsFloorBig_Task::tosCollisionHalfSizeVec = {18.0f, 1.5f, 18.0f};

void clsMapPartsFloorBig_Object::createData()
{
}

clsMapPartsFloorBig_Task::clsMapPartsFloorBig_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMapPartsFloorBig_Task,
                                 clsMapPartsFloorBig_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18702)
{
}

void clsMapPartsFloorBig_Task::reset()
{
}

void clsMapPartsFloorBig_Task::execute()
{
}

void clsMapPartsFloorBig_Task::draw()
{
}

nspPackId::enm clsMapPartsFloorBig_Object::getPackId() const
{
    return nspPackId::ST07_FLOOR_B_17001;
}

clsMapPartsFloorBig_Object::clsMapPartsFloorBig_Object()
{
}

clsMapPartsFloorBig_Object::~clsMapPartsFloorBig_Object()
{
}
