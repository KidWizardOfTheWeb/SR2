#ifndef STORYMAPSELECT_HPP
#define STORYMAPSELECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"

// total size: 0x58
class clsStoryMapSelect_Task : public clsTask {
public:
    virtual ~clsStoryMapSelect_Task();

    virtual void execute();
    void draw();
    void drawMission(s32 param);

    static s8 m_teCursorMode;
    static s8 m_teCursorModeMission;

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
};

#endif // STORYMAPSELECT_HPP
