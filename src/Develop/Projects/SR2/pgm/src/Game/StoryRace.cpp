#include "Develop/Projects/SR2/pgm/src/Game/StoryRace.hpp"

u8 clsStoryRace_Task::checkGoalPlayer()
{
    return 0;
}

void clsStoryRace_Task::restart()
{
}

void clsStoryRace_Task::execute()
{
}

void clsStoryRace_Task::draw()
{
}

u32 clsStoryRace_Task::getStartTimeMilliSec() const
{
    return 0;
}

clsStoryRace_Task::clsStoryRace_Task(clsStoryMgr& rStoryMgr,
                                     s32 param1,
                                     s32 param2,
                                     s32 param3,
                                     s32 param4,
                                     const stcSendAdv* param5,
                                     void** param6,
                                     enmMode param7,
                                     s32 param8)
    : clsBaseRace_Task(param1, param2, param3, param4, 0, param5, param6, param7, param8),
      m_rcStoryMgr(rStoryMgr)
{
}

clsStoryRace_Task::~clsStoryRace_Task()
{
}
