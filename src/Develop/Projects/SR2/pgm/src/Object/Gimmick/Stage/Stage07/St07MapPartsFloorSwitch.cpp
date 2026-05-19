#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorSwitch.hpp"

f32 clsMapPartsFloorSwitch_Object::tof32ClipSqDist = 0.0f;
NNS_VECTOR clsMapPartsFloorSwitch_Task::tosCollisionHalfSizeVec = {5.0f, 1.5f, 5.0f};

static u8 sco8RateTable8Num[8][13] = {
    {0, 0, 0, 0, 20, 20, 20, 20, 20, 0, 0, 0, 0},
    {0, 0, 0, 0, 25, 20, 15, 15, 20, 0, 0, 0, 5},
    {0, 0, 0, 0, 25, 20, 15, 15, 20, 0, 0, 0, 5},
    {0, 0, 0, 0, 25, 20, 10, 10, 25, 0, 0, 0, 10},
    {0, 0, 0, 0, 25, 20, 5, 10, 25, 5, 0, 0, 10},
    {0, 0, 0, 0, 30, 15, 5, 10, 20, 10, 0, 0, 15},
    {0, 0, 0, 0, 30, 15, 0, 5, 20, 15, 0, 0, 15},
    {0, 0, 0, 0, 30, 10, 0, 5, 15, 20, 0, 0, 20},
};

static u8 sco8RateTableMissionNum[7][13] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 100, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void clsMapPartsFloorSwitch_Object::execute()
{
}

void clsMapPartsFloorSwitch_Object::createData()
{
}

void clsMapPartsFloorSwitch_Object::reset()
{
}

void clsMapPartsFloorSwitch_Object::contactTriggerEvent(hkContactPoint* pcObject,
                                                        clsObject* pcOther)
{
}

void clsMapPartsFloorSwitch_Object::setObject()
{
}

void clsMapPartsFloorSwitch_Object::resetObject()
{
}

void clsMapPartsFloorSwitch_Object::init()
{
}

u32 clsMapPartsFloorSwitch_Object::getType(u32 u32Rank)
{
    return 0;
}

u8 clsMapPartsFloorSwitch_Object::checkPath(u32 u32PathNum)
{
    return 0;
}

void clsMapPartsFloorSwitch_Object::destroyData()
{
}

void clsMapPartsFloorSwitch_Object::extensionActiveFrame()
{
}

clsMapPartsFloorSwitch_Task::clsMapPartsFloorSwitch_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsMapPartsFloorSwitch_Task::reset()
{
}

void clsMapPartsFloorSwitch_Task::execute()
{
}

void clsMapPartsFloorSwitch_Task::draw()
{
}
