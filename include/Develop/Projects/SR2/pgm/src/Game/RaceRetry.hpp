#ifndef RACERETRY_HPP
#define RACERETRY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x60
class clsRaceRetry_Task : public clsTask {
public:
    virtual ~clsRaceRetry_Task();

    virtual void execute();
    virtual void draw();

    void drawRetryMenu(s32 s32SelectItem);

    // Members
    u8 m_u8PushPausePadNo;  // offset 0x54, size 0x1
    s32& m_reRacePauseRet;  // offset 0x58, size 0x4
    s8 m_s8StopSeWaitFrame; // offset 0x5C, size 0x1
};

#endif // RACERETRY_HPP
