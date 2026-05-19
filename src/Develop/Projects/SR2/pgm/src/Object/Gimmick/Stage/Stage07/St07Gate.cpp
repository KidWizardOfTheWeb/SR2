#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07Gate.hpp"

f32 clsSt07Gate_Obj::tof32ClipSqDist = 0.0f;

static NNS_VECTORFAST tosPartsOffsetFast[10] = {
    {0.0f, -5.0f, 0.0f, 1.0f},
    {7.0f, -8.5f, 0.0f, 1.0f},
    {-7.0f, -8.5f, 0.0f, 1.0f},
    {14.0f, -12.0f, 0.0f, 1.0f},
    {-14.0f, -12.0f, 0.0f, 1.0f},
    {0.0f, 13.5f, 0.0f, 1.0f},
    {7.0f, 10.0f, 0.0f, 1.0f},
    {-7.0f, 10.0f, 0.0f, 1.0f},
    {14.0f, 6.5f, 0.0f, 1.0f},
    {-14.0f, 6.5f, 0.0f, 1.0f},
};

static f32 f32MoveParam[10][4] = {
    {0.0f, 20.0f, 20.0f, -20.0f},
    {10.0f, 10.0f, 15.0f, -15.0f},
    {10.0f, 10.0f, 15.0f, -15.0f},
    {20.0f, 0.0f, 15.0f, -15.0f},
    {20.0f, 0.0f, 15.0f, -15.0f},
    {0.0f, 20.0f, 20.0f, 10.0f},
    {10.0f, 10.0f, 15.0f, 15.0f},
    {10.0f, 10.0f, 15.0f, 15.0f},
    {20.0f, 0.0f, 15.0f, 15.0f},
    {20.0f, 0.0f, 15.0f, 15.0f},
};

void clsSt07GateThroughCollision::contactTriggerEvent(clsPlayerTask* pParam1)
{
}

void clsSt07GateThroughCollision::contactRemoveEvent(clsPlayerTask* pParam1)
{
}

void clsSt07Gate_Parts::reset()
{
}

void clsSt07Gate_Parts::createData()
{
}

void clsSt07Gate_Parts::destroyData()
{
}

void clsSt07Gate_Parts::main()
{
}

void clsSt07Gate_Parts::setOpen()
{
}

void clsSt07Gate_Parts::setClose()
{
}

void clsSt07Gate_Obj::reset()
{
}

void clsSt07Gate_Obj::main()
{
}

void clsSt07Gate_Obj::setData()
{
}

void clsSt07Gate_Obj::createData()
{
}

void clsSt07Gate_Obj::destroyData()
{
}

u8 clsSt07Gate_Obj::stepMotionFrame()
{
    return 0;
}

clsSt07Gate_Task::clsSt07Gate_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18A88)
{
}

void clsSt07Gate_Task::reset()
{
}

void clsSt07Gate_Task::execute()
{
}

void clsSt07Gate_Task::draw()
{
}
