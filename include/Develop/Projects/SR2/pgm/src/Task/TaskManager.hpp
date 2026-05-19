#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTask.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTaskManager.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

class clsBaseRace_Task;
class clsBaseStage_Task;
class clsPlayerTask;
class clsScore2D_Task;
class clsScript_Task;

// total size: 0x30
struct stcTask {
    clsBaseRace_Task* pcBaseRace;   // offset 0x0, size 0x4
    clsPlayerTask* apcPlayer[8];    // offset 0x4, size 0x20
    clsBaseStage_Task* pcBaseStage; // offset 0x24, size 0x4
    clsScript_Task* pcBaseScript;   // offset 0x28, size 0x4
    clsScore2D_Task* pcScore2D;     // offset 0x2C, size 0x4
};

// total size: 0x54
class clsTask : public clsOOTask {
public:
    virtual ~clsTask() {}
    virtual void execute() {}
    virtual void draw() {}
    virtual void reset() {}

    clsTask(u32 u32Priority, s32 s32Flags)
        : clsOOTask(u32Priority,
                    (u32)s32Flags & 0x7,
                    ((u32)s32Flags & 0x8) != 0 ? 0 : ((u32)s32Flags & 0x4))
    {
    }
    clsTask(u32 u32Priority, s32 s32Flags, clsTask* pcParent)
        : clsOOTask(u32Priority,
                    (clsOOTask*)pcParent,
                    (u32)s32Flags & 0x7,
                    ((u32)s32Flags & 0x8) != 0 ? 0 : ((u32)s32Flags & 0x4))
    {
    }
};

// total size: 0x140
class clsTaskManager : public clsSingleton<clsTaskManager>, public clsOOTaskManager {
public:
    clsTaskManager(clsOOHeapFragment& rcWorkHeap);
    virtual ~clsTaskManager();

    virtual void beginTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum);
    virtual u8 endTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum);
    u32 getCurViewNo() const { return m_u32CurViewNo; }

    // Members
    u32 m_u32CurViewNo; // offset 0x13C, size 0x4
};

#endif // TASKMANAGER_HPP
