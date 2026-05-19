#ifndef SR2_PS2_MEMORYCARD_HPP
#define SR2_PS2_MEMORYCARD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/IO/SR2_Base_MemoryCard.hpp"
#include "usr/local/sce/ee/lib/libmc/libmc.h"

// total size: 0xDC
class clsMemoryCard_Task : public clsBaseMemoryCard_Task {
public:
    virtual ~clsMemoryCard_Task() {}
    virtual void setSaveData(void* param_1) {}
    virtual void
    setNextTaskMode(enmPollingMc_Ret eExecUnionRetI, s32 s32NextCursorNoI, s32 s32CancelCursorNoI);
    virtual void setReturnOs() {}
    virtual void exec_SEQ_REQ___BOOT();
    virtual void draw_SEQ_REQ___BOOT();
    virtual void exec_SEQ_REQ___FILE_SELECT();
    virtual void draw_SEQ_REQ___FILE_SELECT();
    virtual void exec_SEQ_REQ___CREATE() {}
    virtual void draw_SEQ_REQ___CREATE() {}
    virtual void exec_SEQ_REQ___DELETE();
    virtual void draw_SEQ_REQ___DELETE();
    virtual void exec_SEQ_REQ___SAVE();
    virtual void draw_SEQ_REQ___SAVE();
    virtual void exec_SEQ_REQ___LOAD();
    virtual void draw_SEQ_REQ___LOAD();
    virtual void exec_SEQ_REQ___END();
    virtual void draw_SEQ_REQ___END();
    virtual void exec_SEQ_REQ___FORMAT();
    virtual void draw_SEQ_REQ___FORMAT();
    virtual void exec_SEQ_REQ___GHOST_START();
    virtual void draw_SEQ_REQ___GHOST_START();
    virtual void exec_SEQ_REQ___CHANGE_CHK();
    virtual void draw_SEQ_REQ___CHANGE_CHK();
    virtual void exec_SEQ_REQ___UNFORMAT_DEBUG();
    virtual void draw_SEQ_REQ___UNFORMAT_DEBUG();
    virtual void pollingMc_Pf();
    virtual void pollingMc_Pf_End();
    virtual void draw_UnionError();
    virtual void initCursorNo(s32 s32NextI, s32 s32CancelI);

    clsMemoryCard_Task(enmSeqReq eSeqReqI, enmDataType eDataTypeI, s32 s32FileNoI, s32 s32StageNoI);

    void draw_NormalMsg();
    void setCmdUnionError();
    void setCmdNormalMsg();
    u8 checkOldGhostSaveData(const void* pvDataBuff);
    u8 checkOldGameSaveData(const void* pvDataBuff);
    void createOldDataBuff();

    static void* m_tpvOldLoadDataBuff;  // address: 0x00BFB388
    static void* m_tpvOldGhostDataBuff; // address: 0x00BFB390
    static u8 m_tbOldLoadData;          // address: 0x00BFB398
    static u8 m_tbOldGhostData;         // address: 0x00BFB3A0
    static u8 m_tbEndFlag;              // address: 0x00BFB3A8
    static u8 m_tbInitGhostInsertChk;   // address: 0x00BFB3B0

    u8 (*m_fncDataCheck)(void*);   // offset 0xA4, size 0x4
    s8 m_ac8DirName[21];           // offset 0xA8, size 0x15
    s32 m_s32McCheckMode;          // offset 0xC0, size 0x4
    u8 m_bMcCheck;                 // offset 0xC4, size 0x1
    s32 m_s32DrawType;             // offset 0xC8, size 0x4
    s32 m_s32LoopCnt;              // offset 0xCC, size 0x4
    u8 m_bDeleteBreakChk;          // offset 0xD0, size 0x1
    void* m_pvIconBuff;            // offset 0xD4, size 0x4
    sceMcIconSys* m_psIconSysBuff; // offset 0xD8, size 0x4
};

#endif // SR2_PS2_MEMORYCARD_HPP
