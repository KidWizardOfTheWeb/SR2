#ifndef STORYRACE_HPP
#define STORYRACE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Story/StoryMgr.hpp"

enum enmResultType {
    RT___COMPLETE = 0,
    RT___FAILES = 1,
    RT___TIME_UP = 2,
    RT___NONE = 3,
};

// total size: 0xCC0
class clsStoryRace_Task : public clsBaseRace_Task {
public:
    clsStoryRace_Task(clsStoryMgr& rStoryMgr,
                      s32 param1,
                      s32 param2,
                      s32 param3,
                      s32 param4,
                      const stcSendAdv* param5,
                      void** param6,
                      enmMode param7,
                      s32 param8);
    virtual ~clsStoryRace_Task();

    virtual void execute();
    virtual void draw();
    virtual void restart();
    virtual u8 checkGoalPlayer();
    virtual u32 getStartTimeMilliSec() const;

    enum enmResultType m_eResultType; // offset 0xCB0, size 0x4
    clsStoryMgr& m_rcStoryMgr;        // offset 0xCB4, size 0x4
    u32 m_eCondition;                 // offset 0xCB8, size 0x4
    u8 m_bEndFlag2D;                  // offset 0xCBC, size 0x1
    u8 m_bAheadPressStart;            // offset 0xCBD, size 0x1
    u8 m_bDrawLoadingSubject_2D;      // offset 0xCBE, size 0x1
    u8 m_bLoading;                    // offset 0xCBF, size 0x1
};

#endif // STORYRACE_HPP
