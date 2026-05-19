#ifndef BASERACEPAUSE_HPP
#define BASERACEPAUSE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x60
class clsBaseRacePause_Task : public clsTask {
public:
    enum enmPadConnectDraw {
        PAD_CONNECTDRAW_NO_DRAW = 0,
        PAD_CONNECTDRAW_DISCONNECT = 1,
        PAD_CONNECTDRAW_DISCONNECT_WII = 2,
        PAD_CONNECTDRAW_BATTERY = 3,
    };

    clsBaseRacePause_Task();
    virtual ~clsBaseRacePause_Task() {}

    s32& m_reRacePauseRet;             // offset 0x54, size 0x4
    u8 m_u8PushPausePadNo;             // offset 0x58, size 0x1
    s8 m_s8AddExtExist;                // offset 0x59, size 0x1
    u8 m_bDisableDraw;                 // offset 0x5A, size 0x1
    enmPadConnectDraw m_enConnectDraw; // offset 0x5C, size 0x4

    virtual void execute();
    virtual void draw();
    virtual void setCancel();
    virtual void chkEnd();
    virtual u8 chkCancel();
    virtual u8 chkOk();
    virtual void playCursor();
    virtual void stopSound();
    virtual void drawConnectReport();
    virtual u8 checkPadConnect();
};

typedef clsBaseRacePause_Task::enmPadConnectDraw enmPadConnectDraw;

#endif // BASERACEPAUSE_HPP
