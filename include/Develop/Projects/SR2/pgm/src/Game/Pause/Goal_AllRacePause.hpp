#ifndef GOAL_ALLRACEPAUSE_HPP
#define GOAL_ALLRACEPAUSE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x60
class clsGoal_AllRacePause_Task : public clsTask {
public:
    virtual ~clsGoal_AllRacePause_Task();

    virtual void execute();
    virtual void draw();

    u8 m_u8PushPausePadNo; // offset 0x54, size 0x1
    s32& m_reRacePauseRet; // offset 0x58, size 0x4
    u8 m_bChkCancel;       // offset 0x5C, size 0x1
    u8 m_bPauseFlag;       // offset 0x5D, size 0x1
    s8 m_s8SurvivalMenu;   // offset 0x5E, size 0x1
};

#endif // GOAL_ALLRACEPAUSE_HPP
