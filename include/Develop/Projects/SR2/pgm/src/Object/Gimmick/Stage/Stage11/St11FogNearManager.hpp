#ifndef ST11FOGNEARMANAGER_HPP
#define ST11FOGNEARMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/NearData.hpp"

// total size: 0x128
class clsFogNearManager_Task : public clsTask, public clsSingleton<clsFogNearManager_Task> {
public:
    clsFogNearManager_Task() : clsTask(0, 0), clsSingleton<clsFogNearManager_Task>() {}
    virtual ~clsFogNearManager_Task() {}

    virtual void execute();
    virtual void reset();

    void request(u32 u32ViewNum, f32 f32Near);
    f32 getDefaultNear(u32 u32ViewNo);

    stcNearData m_sNearData[4]; // offset 0x58, size 0xD0
};

#endif // ST11FOGNEARMANAGER_HPP
