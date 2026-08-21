#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTask.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTaskManager.hpp"

clsOOTask::clsOOTask(u32 u32Priority, u32 u32ExecFlags, u32 u32EnablePauseFlags)
    : m_u32ExecFlags(u32ExecFlags), m_u32EnablePauseFlags(u32EnablePauseFlags),
      m_u32Priority(u32Priority), m_u8Mode(2), m_u32TaskDepth(0), m_pcParentTask(0),
      m_lstChildTask(clsOOTaskManager::t_pcInstance->m_cHeapStlList_4), m_bIsDead(0),
      m_mapMgrExecListIt(clsOOTaskManager::t_pcInstance->m_cHeapStlMap_4_4)
{
    clsOOTaskManager::t_pcInstance->registTask(this);
}

clsOOTask::clsOOTask(u32 u32Priority,
                     clsOOTask* pcParent,
                     u32 u32ExecFlags,
                     u32 u32EnablePauseFlags)
    : m_u32ExecFlags(u32ExecFlags), m_u32EnablePauseFlags(u32EnablePauseFlags),
      m_u32Priority(u32Priority), m_u8Mode(2), m_u32TaskDepth(0), m_pcParentTask(0),
      m_lstChildTask(clsOOTaskManager::t_pcInstance->m_cHeapStlList_4), m_bIsDead(0),
      m_mapMgrExecListIt(clsOOTaskManager::t_pcInstance->m_cHeapStlMap_4_4)
{
    clsOOTaskManager::t_pcInstance->registTask(this, pcParent);
}
