#ifndef OOFILEMGR_HPP
#define OOFILEMGR_HPP
#include "types.h"
#include "usr/local/cri/mwlib/ee/lib/cri_libs.h"
#include "usr/local/metrowerks/PS2_Support/stl/deque.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOThread.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Compression/OOCompression.hpp"

// enmRet: file operation return code.
// MWCC mangles this as nspOOFileMgr::enmRet — declared inside the namespace.
// Note: do NOT guard with ENMRET_DECLARED — that macro is already used by GimmickObj.hpp,
// Gear.hpp and CharaData.hpp for a completely different global enum enmRet {VISIBLE_CLIP,...}.
// Sharing that guard would silently skip this namespace definition when those headers are
// included first. The file-level include guard (LIB_OO_CORE_OOFILEMGR_HPP) is sufficient.
namespace nspOOFileMgr {
enum enmRet {
    RET___UN_USE = 0,
    RET___INIT = 1,
    RET___EXEC = 2,
    RET___ERROR_DEF = 3,
    RET___ERROR_DIFFERENT_DISC = 4,
    RET___ERROR_OPENED_COVER = 5,
    RET___FINISH = 6,
    RET___CANCEL_EXEC = 7,
    RET___CANCEL_FINISH = 8,
};
} // namespace nspOOFileMgr

// total size: 0x64
// Note: offset 0x0 is vtable pointer (no virtual functions visible in DWARF)
class clsOOFileQueue {
public:
    virtual ~clsOOFileQueue() {}

    _adx_fs* m_psADXF;             // offset 0x4, size 0x4
    s8 m_ac8Name[64];              // offset 0x8, size 0x40
    u8* m_pu8Buffer;               // offset 0x48, size 0x4
    u8** m_ppu8FinishAddr;         // offset 0x4C, size 0x4
    f32 m_f32Progress;             // offset 0x50, size 0x4
    u32 m_eRequestFlag;            // offset 0x54, size 0x4
    nspOOFileMgr::enmRet* m_peRet; // offset 0x58, size 0x4
    s16 m_s16Sector;               // offset 0x5C, size 0x2
    s16 m_s16ReadedSector;         // offset 0x5E, size 0x2
    u8 m_u8Mode;                   // offset 0x60, size 0x1
};

// total size: 0xF8
class clsOOFileMgr {
public:
    virtual void thread_Exec();
    virtual void vwait() const {}
    void setRenderNowLoding(bool bEnable) { m_bEnableRenderNowLoding = bEnable; }

    clsOOFileQueue m_cQueue_Debug;        // offset 0x4, size 0x64
    deque m_cExecDeque;                   // offset 0x68, size 0x18
    deque m_cRequestDeque;                // offset 0x80, size 0x18
    u8 m_bEnableRenderNowLoding;          // offset 0x98, size 0x1
    clsOOCompression m_cCompression;      // offset 0x9C, size 0x4C
    clsOOThread* m_pcReadThread;          // offset 0xE8, size 0x4
    clsOOFileQueue* m_pcCurrentReadQueue; // offset 0xEC, size 0x4
    u8 m_bReadThreadDone;                 // offset 0xF0, size 0x1
    u8 m_bReadCancel;                     // offset 0xF1, size 0x1
    u8* m_pu8ReadWorkBuf;                 // offset 0xF4, size 0x4

    clsOOFileMgr(u8 bInit);
    ~clsOOFileMgr();

    void execNowLoading(bool bExec);
    void tRenderNowLoading();
    void cancel(const c8* pcName);
    void cancel();
    s32
    requestRead(const c8* pcName, void** ppvBuf, u32 uSize, volatile nspOOFileMgr::enmRet* peRet);
    void setChangeBuffer(const c8* pcName, void** ppvBuf, nspOOFileMgr::enmRet* peRet);
    void* thread_read(const clsOOThread::_EntryArg* psArg);

    static void (*m_tpRenderNowLoading_CallBack)();
};

#endif // OOFILEMGR_HPP
