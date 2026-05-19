#ifndef NORMALRACESELECT_HPP
#define NORMALRACESELECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"

// total size: 0x58
class clsNormalRaceSelect_Task : public clsTask {
public:
    virtual ~clsNormalRaceSelect_Task() {}
    virtual void execute();
    virtual void draw();

    static s8 m_teCursorMode;

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
};

#endif // NORMALRACESELECT_HPP
