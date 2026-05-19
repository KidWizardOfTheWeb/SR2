#ifndef GOAL_SURVIVALRACEPAUSE_HPP
#define GOAL_SURVIVALRACEPAUSE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsGoal_SurvivalRacePause_Task : public clsTask {
public:
    clsGoal_SurvivalRacePause_Task(s32 s32Param1, s32& rParam2);
    virtual ~clsGoal_SurvivalRacePause_Task() {}

    void execute();
    void draw();

    u8 m_u8PushPausePadNo; // offset 0x54, size 0x1
    s32& m_reRacePauseRet; // offset 0x58, size 0x4
    u8 m_bPause;           // offset 0x5C, size 0x1
    s8 m_s8SurvivalMenu;   // offset 0x5D, size 0x1
};

#endif // GOAL_SURVIVALRACEPAUSE_HPP
