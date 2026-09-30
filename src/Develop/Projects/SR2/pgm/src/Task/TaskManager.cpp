#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCamera.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCameraMgr.hpp"
#include "usr/local/sce/ee/lib/libkernl/kprintf2.h"
#include "macros.h"

clsTaskManager::clsTaskManager(clsOOHeapFragment& rcWorkHeap)
    : clsOOTaskManager(rcWorkHeap), m_u32CurViewNo(0)
{
    registExecFunc(4, &clsOOTask::execute);
    registExecFunc(1, &clsOOTask::draw);
    registExecFunc(2, static_cast<ExecFunc>(&clsTask::reset));
}

clsTaskManager::~clsTaskManager()
{
}

void clsTaskManager::beginTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum)
{
    switch (u32GroupId) {
    case 4:
        m_u32PauseFlags = (m_u32PauseFlags & ~4) | ((clsPfSystem::GS()->m_bPause ? 4 : 0) & 4);
        break;
    case 1:
        m_u32CurViewNo = u32LoopNum;
        clsPfSystem::GS()->setViewPort(u32LoopNum);
        break;
    case 2:
        clsPfSystem::GS()->setViewPort(4);
        break;
    default:
        SUPER_ASSERT(0x30250201, "TaskManager.cpp", 112, "不明なグループＩＤです。\n");
        break;
    }
}

u8 clsTaskManager::endTaskExecuteGroup(u32 u32GroupId, u32 u32LoopNum)
{
    u8 bRet = 0;

    switch (u32GroupId) {
    case 4:
        clsPfCameraMgr::GS()->updateAllCamera();
        bRet = 0;
        break;
    case 1:
        clsPfCameraMgr::GS()->getCamera(u32LoopNum)->m_cCamDebug.draw();
        if (u32LoopNum + 1 >= clsPfSystem::GS()->getViewportNum()) {
            m_u32CurViewNo = 0;
        } else {
            bRet = 1;
        }
        break;
    case 2:
        break;
    default:
        SUPER_ASSERT(0x30250201, "TaskManager.cpp", 168, "不明なグループＩＤです。\n");
        break;
    }

    return bRet;
}
