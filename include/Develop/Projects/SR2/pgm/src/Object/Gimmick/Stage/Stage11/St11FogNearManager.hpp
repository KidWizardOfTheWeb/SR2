#ifndef ST11FOGNEARMANAGER_HPP
#define ST11FOGNEARMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickManager.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/NearData.hpp"

// total size: 0x128
class clsFogNearManager_Task : public clsTask, public clsSingleton<clsFogNearManager_Task> {
public:
    clsFogNearManager_Task() : clsTask(101010, 4)
    {
        memset(m_sNearData, 0, sizeof(m_sNearData));
        clsGmkManager* pcManager = clsGmkManager::GS();
        clsTask* pcTask = this;
        pcManager->m_tdpcGimmick.insert(pcManager->m_tdpcGimmick.end(), pcTask);
    }
    virtual ~clsFogNearManager_Task();

    virtual void execute();
    virtual void reset();

    void request(u32 u32ViewNum, f32 f32Near);
    f32 getDefaultNear(u32 u32ViewNo);

    stcNearData m_sNearData[4]; // offset 0x58, size 0xD0
};

inline clsFogNearManager_Task::~clsFogNearManager_Task()
{
}

#endif // ST11FOGNEARMANAGER_HPP
