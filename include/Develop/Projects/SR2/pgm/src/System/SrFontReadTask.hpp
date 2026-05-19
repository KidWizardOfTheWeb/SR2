#ifndef SRFONTREADTASK_HPP
#define SRFONTREADTASK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/SrFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFileMgr.hpp"

class clsSrFontRead_Task : public clsTask {
public:
    clsSrFontRead_Task() : clsTask(0, 0) {}
    virtual ~clsSrFontRead_Task() {}

    void createFontReadTask(u32 u32Param1,
                            s32 s32Param2,
                            clsSrFontSystem* pParam3,
                            nspSrFontSystem::enmFontNo,
                            s32 s32Param5,
                            void* pvParam6,
                            bool bParam7,
                            void* pvParam8);
    void execute();
    void cancelRead(nspSrFontSystem::enmFontNo);

    static clsSrFontRead_Task* m_tapcTask[21];

    clsSrFontSystem* m_pcFontSystem;          // offset 0x54, size 0x4
    nspSrFontSystem::enmFontNo m_enFontNo;    // offset 0x58, size 0x4
    s32 m_s32FontFileNo;                      // offset 0x5C, size 0x4
    u8 m_bBtnLoad;                            // offset 0x60, size 0x1
    u8 m_bFontBuffDelFlag;                    // offset 0x61, size 0x1
    void* m_pvFontDataBuff;                   // offset 0x64, size 0x4
    nspOOFileMgr::enmRet m_eFontDataBuff_Ret; // offset 0x68, size 0x4
    void* m_pvBtnDataBuff;                    // offset 0x6C, size 0x4
    nspOOFileMgr::enmRet m_eBtnDataBuff_Ret;  // offset 0x70, size 0x4
};

#endif // SRFONTREADTASK_HPP
