#ifndef FREERACESELECT_HPP
#define FREERACESELECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"

// total size: 0x5C
class clsFreeRaceSelect_Task : public clsTask {
public:
    clsFreeRaceSelect_Task() : clsTask(0, 0) {}
    virtual ~clsFreeRaceSelect_Task() {}

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
    s8 m_s8MaxRuleNum;                           // offset 0x58, size 0x1
    u8 m_bUra;                                   // offset 0x59, size 0x1
    s8 m_s8Laps;                                 // offset 0x5A, size 0x1
    u8 m_bGhost;                                 // offset 0x5B, size 0x1

    static s8 m_teCursorMode;
    static s8 m_teCursorModeRule;

    virtual void execute();
    virtual void draw();
    virtual void initRuleSetting();
    virtual void rtdRuleSetting();
    virtual void updateRuleSetting();
    virtual void execRule();
    virtual void drawMainDepend();
    virtual void drawMapDepend(s32 s32CursorNoI);
    virtual void drawRule();
    virtual void tdrawMap(s32 s32CursorNoI, s32 s32CursorNoI2);
};

#endif // FREERACESELECT_HPP
