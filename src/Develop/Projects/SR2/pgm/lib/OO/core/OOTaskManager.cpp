#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTaskManager.hpp"

clsOOTaskManager* clsOOTaskManager::t_pcInstance;

clsOOTaskManager::clsOOTaskManager(clsOOHeapFragment& rcWorkHeap) : m_rcMainWorkHeap(rcWorkHeap)
{
}

clsOOTaskManager::~clsOOTaskManager()
{
}

void clsOOTaskManager::registExecFunc(u32 u32Id, ExecFunc pfExecFunc)
{
}

void clsOOTaskManager::registTask(clsOOTask* pcTask, clsOOTask* pcParent)
{
}

void clsOOTaskManager::registTask(clsOOTask* pcTask)
{
}

void clsOOTaskManager::deleteTask(clsOOTask* pcTask)
{
}

void clsOOTaskManager::deleteAllTask()
{
}

void clsOOTaskManager::deadTaskWithChildTaskLoop(clsOOTask* pcTask)
{
}

u8 clsOOTaskManager::execute()
{
    return 0;
}
