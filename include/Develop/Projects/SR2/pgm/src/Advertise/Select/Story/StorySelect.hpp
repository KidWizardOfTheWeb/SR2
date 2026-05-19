#ifndef STORYSELECT_HPP
#define STORYSELECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x58
class clsStorySelect_Task : public clsTask {
public:
    virtual ~clsStorySelect_Task() {}
    virtual void execute();
    virtual void draw();

    static s8 m_teCursorMode;

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
};

#endif // STORYSELECT_HPP
