#include "Develop/Projects/SR2/pgm/src/Debug/DebugTask.hpp"

clsDebugTask_Task::clsDebugTask_Task(s32 s32xI,
                                     s32 s32yI,
                                     u32 u32FrameI,
                                     u32 u32DpColorI,
                                     u32 u32BgColorI,
                                     clsDebugTask_Task::enmFlash eFlashI,
                                     c8* pc8FmtI,
                                     ...)
    : clsTask(0, 0)
{
}

clsDebugTask_Task::clsDebugTask_Task(s32 s32xI,
                                     s32 s32yI,
                                     u32 u32FrameI,
                                     u32 u32DpColorI,
                                     u32 u32BgColorI,
                                     clsDebugTask_Task::enmFlash eFlashI,
                                     const c8* opc8StrI)
    : clsTask(0, 0)
{
}

void clsDebugTask_Task::execute()
{
}

void clsDebugTask_Task::draw()
{
}
