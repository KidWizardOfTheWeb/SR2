#include "Develop/Projects/SR2/pgm/lib/OO/PS2_CRI/PS2CriFileMgr.hpp"

s32 clsPfFileMgr::tThread_Exec(void* pvParam1)
{
    return 0;
}

u8 clsPfFileMgr::requestWrite(const c8* opc8NameI, const void* opvBufferI, s32 s32SizeI)
{
    return 0;
}

u8 clsPfFileMgr::thread_Open(clsOOFileQueue& rcQueueI)
{
    return 0;
}

s32 clsPfFileMgr::thread_OpenWait(clsOOFileQueue& rcQueueI)
{
    return 0;
}

void clsPfFileMgr::thread_Close(clsOOFileQueue& rcQueueI)
{
}

s32 clsPfFileMgr::getFileSize_Sector(void* hFile)
{
    return 0;
}

u8 clsPfFileMgr::read_async(void* hFile, s32 s32SectorNum, u8* pu8Buf)
{
    return 0;
}

enmReadStat clsPfFileMgr::getReadStat(void* hFile)
{
    return READ_STOP;
}

s32 clsPfFileMgr::getReadedSector(void* hFile)
{
    return 0;
}

void clsPfFileMgr::stop(void* hFile)
{
}

u8* clsPfFileMgr::allocateReadBuffer(volatile clsOOFileQueue* pcQueueI, s32 s32Size)
{
    return 0;
}

void clsPfFileMgr::thread_DeAllocate(clsOOFileQueue& rcQueueI)
{
}
