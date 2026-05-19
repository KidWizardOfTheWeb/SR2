#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

clsTaskManager::clsTaskManager(clsOOHeapFragment& rcWorkHeap) : clsOOTaskManager(rcWorkHeap)
{
}

clsTaskManager::~clsTaskManager()
{
}

void clsTaskManager::beginTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum)
{
}

u8 clsTaskManager::endTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum)
{
    return 0;
}
