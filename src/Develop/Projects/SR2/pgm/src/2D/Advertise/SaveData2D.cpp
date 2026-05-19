#include "Develop/Projects/SR2/pgm/src/2D/Advertise/SaveData2D.hpp"

namespace nspSaveData2D {
static stcDrawSaveData osDrawData = {
    192,
    196,
    74,
    314,
    16,
    6,
    4,
    -6,
    20,
    10,
    0,
    6,
    24,
    2,
    4,
    2,
};

static u32 oau32DrawItem[6] = {0, 1, 2, 3, 4, 5};
} // namespace nspSaveData2D

clsSaveData2D_Task::clsSaveData2D_Task(clsAdvertiseMgr_Task* pcAdvertiseMgr_Task,
                                       bool bCancel,
                                       bool bOptionCheck)
    : clsTask(0, 0)
{
}

void clsSaveData2D_Task::execute()
{
}

void clsSaveData2D_Task::drawWindow(
    s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color, u32 u32DecoType)
{
}

void clsSaveData2D_Task::drawSelectWindow(s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color)
{
}

void clsSaveData2D_Task::drawTopConsole(
    u32 u32No, s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color)
{
}

void clsSaveData2D_Task::drawTime(u32 u32TotalTime, f32 f32X, f32 f32Y, u32 u32Color)
{
}

void clsSaveData2D_Task::drawMisson(u32 u32MissonNum, f32 f32X, f32 f32Y, u32 u32Color)
{
}

void clsSaveData2D_Task::drawGear(u32 u32GearNum, f32 f32X, f32 f32Y, u32 u32Color)
{
}

void clsSaveData2D_Task::drawDate(
    u16 u16Year, u8 u8Month, u8 u8Day, f32 f32X, f32 f32Y, u32 u32Color)
{
}

void clsSaveData2D_Task::drawRing(u32 u32RingNum, f32 f32X, f32 f32Y, u32 u32Color)
{
}

void clsSaveData2D_Task::drawAnderConsole(
    u32 u32No, s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color)
{
}

void clsSaveData2D_Task::drawData(u32 u32No)
{
}

void clsSaveData2D_Task::draw()
{
}
