#ifndef MODESELECT_HPP
#define MODESELECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/MsgWnd2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsModeSelect_Task : public clsTask {
public:
    virtual ~clsModeSelect_Task();

    clsModeSelect_Task(clsAdvertiseMgr_Task* pcAdvertiseMgr_Task);

    virtual void execute();
    virtual void draw();

    void checkGameData();
    void setReturnMode(u32 Param1, u32 Param2, u32 Param3, u32 Param4);
    void execTutorialCheck();
    u8 drawRuleParam();
    void drawStoryMessage();
    void drawMissionMessage();
    void checkFont();
    void drawSubTime();
    void drawMissionTime();
    void drawMissionScore();
    void drawWgpMenu();

    void setButtonFrame(f32 f32Param) { m_f32ButtonDrawWait = f32Param; }

    // Members
    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
    u8 m_u8ReadMode;                             // offset 0x58, size 0x1
    u8 m_u8LapType;                              // offset 0x59, size 0x1
    u8 m_u8LapColor;                             // offset 0x5A, size 0x1
    u8 m_u8TutorialCheck;                        // offset 0x5B, size 0x1
    u8 m_bTutorialCheck;                         // offset 0x5C, size 0x1
    f32 m_f32ButtonDrawWait;                     // offset 0x60, size 0x4
    clsMsgWnd_Task* m_pcMsgWndTask;              // offset 0x64, size 0x4
};

#endif // MODESELECT_HPP
