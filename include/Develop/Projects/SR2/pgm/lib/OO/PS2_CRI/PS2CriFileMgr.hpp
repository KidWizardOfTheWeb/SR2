#ifndef PS2CRIFILEMGR_HPP
#define PS2CRIFILEMGR_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFileMgr.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

enum enmReadStat {
    READ_STOP = 0,
    READ_END = 1,
    READ_READING = 2,
    READ_ERROR = 3,
};

// total size: 0xFC
class clsPfFileMgr : public clsSingleton<clsPfFileMgr>, public clsOOFileMgr {
public:
    clsPfFileMgr(u8 u8Param1) : clsOOFileMgr(u8Param1) {}
    virtual ~clsPfFileMgr();

    virtual u8 requestWrite(const c8* opc8NameI, const void* opvBufferI, s32 s32SizeI);
    virtual s32 getFileSize_Sector(void* hFile);
    virtual u8 thread_Open(clsOOFileQueue& rcQueueI);
    virtual s32 thread_OpenWait(clsOOFileQueue& rcQueueI);
    virtual void thread_Close(clsOOFileQueue& rcQueueI);
    virtual void thread_DeAllocate(clsOOFileQueue& rcQueueI);
    virtual u8* allocateReadBuffer(volatile clsOOFileQueue* pcQueueI, s32 s32Size);
    virtual u8 read_async(void* hFile, s32 s32SectorNum, u8* pu8Buf);
    virtual enmReadStat getReadStat(void* hFile);
    virtual s32 getReadedSector(void* hFile);
    virtual void stop(void* hFile);
    virtual void vwait() const;

    static s32 tThread_Exec(void* pvParam1);
};

#endif // PS2CRIFILEMGR_HPP
