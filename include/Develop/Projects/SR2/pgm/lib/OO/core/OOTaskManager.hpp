#ifndef OOTASKMANAGER_HPP
#define OOTASKMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTask.hpp"

// total size: 0x138
class clsOOTaskManager {
public:
    typedef void (clsOOTask::*ExecFunc)();

    // total size: 0x10
    class _stcExecListData {
    public:
        ExecFunc pfFunc;   // offset 0x0, size 0xC
        clsOOList* pcList; // offset 0xC, size 0x4
    };

    static clsOOTaskManager* t_pcInstance;

    clsOOTaskManager(clsOOHeapFragment& rcWorkHeap);
    virtual ~clsOOTaskManager();
    virtual void beginTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum) {}
    virtual u8 endTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum) { return 0; }

    u8 execute();
    void deadTaskWithChildTask(clsOOTask* pcTask) {}
    void insertList(clsOOTask* pcTask) {}
    void deadTaskWithChildTaskLoop(clsOOTask* pcTask);
    void deleteAllTask();
    void deleteTask(clsOOTask* pcTask);
    void registTask(clsOOTask* pcTask, clsOOTask* pcParent);
    void registTask(clsOOTask* pcTask);
    void registExecFunc(u32 u32Id, ExecFunc pfExecFunc);

    clsOOHeapFragment& m_rcMainWorkHeap;  // offset 0x4, size 0x4
    clsOOHeapFragment m_cHeapStlList_4;   // offset 0x8, size 0x34
    clsOOHeapFragment m_cHeapStlMap_4_4;  // offset 0x3C, size 0x34
    clsOOHeapFragment m_cDefaultWorkHeap; // offset 0x70, size 0x34
    void* m_pvWorkStartAddr;              // offset 0xA4, size 0x4
    clsOOList m_lstTask;                  // offset 0xA8, size 0x14
    clsOOList m_lstTaskNewcomer;          // offset 0xBC, size 0x14
    clsOOMap m_mapExecList;               // offset 0xD0, size 0x18
    clsOOList m_lstFirstTask;             // offset 0xE8, size 0x14
    clsOOMMap m_mmapReservedDeadTask;     // offset 0xFC, size 0x18
    clsOOList m_lstDeadTask;              // offset 0x114, size 0x14
    clsOOTask* m_pcCurrentTask;           // offset 0x128, size 0x4
    u32 m_u32PauseFlags;                  // offset 0x12C, size 0x4
    u8 m_u8AllDeadMode;                   // offset 0x130, size 0x1
    u8 m_au8LoopUpdate[5];                // offset 0x131, size 0x5
};

#endif // OOTASKMANAGER_HPP
