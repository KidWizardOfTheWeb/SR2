#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCamera.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCameraMgr.hpp"

extern "C" s32 scePrintf(const c8* pc8Fmt, ...);

#define TASK_MANAGER_ASSERT()                                                                      \
    do {                                                                                           \
        scePrintf("\n■■■■■■■\n");                                                                  \
        scePrintf("SUPER ASSERTION→ <0x%08x> %s(%d) in %s()\n",                                    \
                  0x30250201,                                                                      \
                  "TaskManager.cpp",                                                               \
                  __LINE__,                                                                        \
                  __FUNCTION__);                                                                   \
        scePrintf("[%s] : ", "nakawatari");                                                        \
        scePrintf("不明なグループＩＤです。\n");                                                   \
        scePrintf("■■■■■■■\n");                                                                    \
        ABORT();                                                                                   \
    } while (0)

clsTaskManager::clsTaskManager(clsOOHeapFragment& rcWorkHeap)
    : clsOOTaskManager(rcWorkHeap), m_u32CurViewNo(0)
{
    registExecFunc(4, (ExecFunc)&clsTask::execute);
    registExecFunc(1, (ExecFunc)&clsTask::draw);
    registExecFunc(2, (ExecFunc)&clsTask::reset);
}

clsTaskManager::~clsTaskManager()
{
}

void clsTaskManager::beginTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum)
{
    switch (u32GroupId) {
    case 4:
        m_u32PauseFlags = (m_u32PauseFlags & ~4) |
                          ((clsSingleton<clsPfSystem>::m_tpcSingleton->m_bPause ? 4 : 0) & 4);
        break;
    case 1:
        m_u32CurViewNo = u32LoopNum;
        clsSingleton<clsPfSystem>::m_tpcSingleton->setViewPort(u32LoopNum);
        break;
    case 2:
        clsSingleton<clsPfSystem>::m_tpcSingleton->setViewPort(4);
        break;
    default:
#line 112
        TASK_MANAGER_ASSERT();
        break;
    }
}

u8 clsTaskManager::endTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum)
{
    u8 bRet = 0;

    switch (u32GroupId) {
    case 4:
        clsSingleton<clsPfCameraMgr>::m_tpcSingleton->updateAllCamera();
        bRet = 0;
        break;
    case 1:
        clsSingleton<clsPfCameraMgr>::m_tpcSingleton->getCamera(u32LoopNum)->m_cCamDebug.draw();
        if (u32LoopNum + 1 >= clsSingleton<clsPfSystem>::m_tpcSingleton->getViewportNum()) {
            m_u32CurViewNo = 0;
        } else {
            bRet = 1;
        }
        break;
    case 2:
        break;
    default:
#line 168
        TASK_MANAGER_ASSERT();
        break;
    }

    return bRet;
}

#undef TASK_MANAGER_ASSERT
