#ifndef CREDIT_HPP
#define CREDIT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x58
class clsCredit_Task : public clsTask {
public:
    virtual ~clsCredit_Task() {}

    enmHbMode m_eHbMode; // offset 0x54, size 0x4
};

#endif // CREDIT_HPP
