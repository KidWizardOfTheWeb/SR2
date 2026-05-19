#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFileMgr.hpp"

namespace {
static clsOOFileQueue tcTempAsyncQueue;
static clsOOFileQueue tcTempBlockQueue;
} // namespace

void (*clsOOFileMgr::m_tpRenderNowLoading_CallBack)() = 0;

clsOOFileMgr::clsOOFileMgr(u8 bInit)
{
}

clsOOFileMgr::~clsOOFileMgr()
{
}

void* clsOOFileMgr::thread_read(const clsOOThread::_EntryArg* psArg)
{
    return 0;
}

void clsOOFileMgr::setChangeBuffer(const c8* pcName, void** ppvBuf, nspOOFileMgr::enmRet* peRet)
{
}

s32 clsOOFileMgr::requestRead(const c8* pcName,
                              void** ppvBuf,
                              u32 uSize,
                              volatile nspOOFileMgr::enmRet* peRet)
{
    return 0;
}

void clsOOFileMgr::cancel(const c8* pcName)
{
}

void clsOOFileMgr::cancel()
{
}

void clsOOFileMgr::tRenderNowLoading()
{
}

void clsOOFileMgr::execNowLoading(bool bExec)
{
}

void clsOOFileMgr::thread_Exec()
{
}
