#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTaskManager.hpp"

clsOOTaskManager* clsOOTaskManager::t_pcInstance;

clsOOTaskManager::clsOOTaskManager(clsOOHeapFragment& heap) : m_rcMainWorkHeap(heap)
{
}

clsOOTaskManager::~clsOOTaskManager()
{
}

void clsOOTaskManager::registExecFunc(u32 u32Param1, ExecFunc pFunc)
{
}

void clsOOTaskManager::registTask(clsOOTask* pParam1, clsOOTask* pParam2)
{
}

void clsOOTaskManager::registTask(clsOOTask* pParam1)
{
}

void clsOOTaskManager::deleteTask(clsOOTask* pParam1)
{
}

void clsOOTaskManager::deleteAllTask()
{
}

void clsOOTaskManager::deadTaskWithChildTaskLoop(clsOOTask* pParam1)
{
}

u8 clsOOTaskManager::execute()
{
    return 0;
}
