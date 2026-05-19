#ifndef SR2_BASE_MEMORYCARD_HPP
#define SR2_BASE_MEMORYCARD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OORetry.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/MsgWnd2D.hpp"
#include "Develop/Projects/SR2/pgm/src/System/IO/SR2_MemoryCardFile.hpp"

class clsBaseMemoryCardFile;

// total size: 0xA4
class clsBaseMemoryCard_Task : public clsTask {
public:
    enum enmSeqReq {
        SEQ_REQ___BOOT = 0,
        SEQ_REQ___FILE_SELECT = 1,
        SEQ_REQ___CREATE = 2,
        SEQ_REQ___DELETE = 3,
        SEQ_REQ___SAVE = 4,
        SEQ_REQ___LOAD = 5,
        SEQ_REQ___GHOST_START = 6,
        SEQ_REQ___CHANGE_CHK = 7,
        SEQ_REQ___UNFORMAT_DEBUG = 8,
        SEQ_REQ___ALL_DELETE_DEBUG = 9,
        SEQ_REQ___NONE = 10,
        SEQ_REQ___END = 11,
        SEQ_REQ___FORMAT = 12,
        SEQ_REQ___FILE_BROKEN = 13,
        SEQ_REQ___CREATE_BANNER = 14,
        SEQ_REQ___MAX = 15,
    };

    enum enmPollingMc_Ret {
        POLLING_MC_RET___SUCCESS = 0,
        POLLING_MC_RET___FAILED = 1,
        POLLING_MC_RET___WAIT = 2,
    };

    enum enmMcMovin {
        MC_MOVIN___NONE = 0,
        MC_MOVIN___CHECK_MC_EXIST_1 = 1,
        MC_MOVIN___CHECK_MC_EXIST_2 = 2,
        MC_MOVIN___CHECK_MC_EXIST_3 = 3,
        MC_MOVIN___CHECK_FORMAT_1 = 4,
        MC_MOVIN___CHECK_FORMAT_2 = 5,
        MC_MOVIN___FORMAT = 6,
        MC_MOVIN___CHECK_FILE_EXIST_GAMES_BOOT = 7,
        MC_MOVIN___CHECK_FILE_EXIST_GAMES_FILE_SELECT = 8,
        MC_MOVIN___CHECK_FREE_AREA = 9,
        MC_MOVIN___CHECK_ID = 10,
        MC_MOVIN___CREATE = 11,
        MC_MOVIN___DELETE = 12,
        MC_MOVIN___SAVE = 13,
        MC_MOVIN___LOAD = 14,
        MC_MOVIN___UNFORMAT = 15,
    };

    enum enmRtnCode {
        RTNCODE_WAIT = 0,
        RTNCODE_NO_ERROR = 1,
        RTNCODE_ERROR = 2,
        RTNCODE_RETRY = 3,
        RTNCODE_END = 4,
        RTNCODE_NO_SAVE = 5,
        RTNCODE_TASK_EMPTY = -1,
    };

    enum enmdeleteTask_And_setAutoSave_Arg {
        AUTOSAVE_ARG___OFF = 0,
        AUTOSAVE_ARG___ON = 1,
        AUTOSAVE_ARG___IGNORE = 2,
    };

    enum enmdraw_UnionFont_Arg {
        DRAW_SEL___OFF = 0,
        DRAW_SEL___ON = 1,
    };

    virtual ~clsBaseMemoryCard_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void setMode(u32 param_1) {}
    virtual void addMode() {}
    virtual void addMode(u32 param_1) {}
    virtual void subMode() {}
    virtual void subMode(u32 param_1) {}
    virtual void reinitMode() {}
    // [11] reset — inherited from clsTask
    virtual void setSaveData(void* param_1) {}
    virtual void setLoadDataBuff(u32 param_1, void* param_2) {}
    virtual void setCrcCheckFunc(bool (*param_1)(const void*)) {}
    virtual void freeAccessBuffer() {}
    virtual void
    setNextTaskMode(enmPollingMc_Ret eExecUnionRetI, s32 s32NextCursorNoI, s32 s32CancelCursorNoI);
    virtual void setReturnOs() = 0;
    virtual void exec_SEQ_REQ___BOOT() {}
    virtual void draw_SEQ_REQ___BOOT() {}
    virtual void exec_SEQ_REQ___FILE_SELECT() {}
    virtual void draw_SEQ_REQ___FILE_SELECT() {}
    virtual void exec_SEQ_REQ___CREATE() {}
    virtual void draw_SEQ_REQ___CREATE() {}
    virtual void exec_SEQ_REQ___DELETE() {}
    virtual void draw_SEQ_REQ___DELETE() {}
    virtual void exec_SEQ_REQ___SAVE() {}
    virtual void draw_SEQ_REQ___SAVE() {}
    virtual void exec_SEQ_REQ___LOAD() {}
    virtual void draw_SEQ_REQ___LOAD() {}
    virtual void exec_SEQ_REQ___END() {}
    virtual void draw_SEQ_REQ___END() {}
    virtual void exec_SEQ_REQ___FORMAT() {}
    virtual void draw_SEQ_REQ___FORMAT() {}
    virtual void exec_SEQ_REQ___FILE_BROKEN() {}
    virtual void draw_SEQ_REQ___FILE_BROKEN() {}
    virtual void exec_SEQ_REQ___CREATE_BANNER() {}
    virtual void draw_SEQ_REQ___CREATE_BANNER() {}
    virtual void exec_SEQ_REQ___GHOST_START() {}
    virtual void draw_SEQ_REQ___GHOST_START() {}
    virtual void exec_SEQ_REQ___CHANGE_CHK() {}
    virtual void draw_SEQ_REQ___CHANGE_CHK() {}
    virtual void exec_SEQ_REQ___UNFORMAT_DEBUG() {}
    virtual void draw_SEQ_REQ___UNFORMAT_DEBUG() {}
    virtual void exec_SEQ_REQ___ALL_DELETE_DEBUG() {}
    virtual void draw_SEQ_REQ___ALL_DELETE_DEBUG() {}
    virtual void pollingMc_Pf() = 0;
    virtual void pollingMc_Pf_End() = 0;
    virtual enm_N_SelCmd exec_UnionSelCmd(enm_N_SelCmd e_N_SelCmd_IgnoreI);
    virtual void draw_UnionError() = 0;
    virtual void initCursorNo(s32 s32NextI, s32 s32CancelI);
    virtual void backMode() {}
    virtual void backMode(u32 param_1) {}
    virtual void setBackMode(u32 param_1) {}

    clsBaseMemoryCard_Task(enmSeqReq eSeqReqI,
                           enmDataType eDataTypeI,
                           s32 s32FileNoI,
                           s32 s32StageNoI);

    void setSelCmd(u32 eSelCmdI);
    void setBackSeq();
    void setNextSeq(enmSeqReq eSeqReqI);
    void reinit(
        enmSeqReq eSeqReqI, enmDataType eDataTypeI, s32 s32FileNoI, s32 s32StageNoI, u8 eTaskModeI);
    enmPollingMc_Ret pollingMc(enmMcMovin eMcMovinI);
    enmPollingMc_Ret
    deleteTask_And_setAutoSave(enmdeleteTask_And_setAutoSave_Arg edeleteTask_And_setAutoSave_ArgI,
                               enmRtnCode enRtnCode);
    u8 exec_UnionCursor(u32 bOnlyOkI);
    void draw_UnionFont(s32 s32FontTblNoI,
                        enmdraw_UnionFont_Arg edraw_UnionFont_ArgI,
                        s32 s32Arg3I,
                        s32 s32Arg4I);

    static s8* m_opc8SeqReqName_Debug[15]; // address: 0x653B00
    static u8 m_tbSaveFlag;                // address: 0x653B40
    static u8 m_tbGhostSaveFlag;           // address: 0x653B48
    static enmRtnCode m_tenRtnCode;        // address: 0x653B50

    clsOORetry m_cApiRetry;                        // offset 0x54, size 0x10
    enmSeqReq m_eSeqReq;                           // offset 0x64, size 0x4
    enmSeqReq m_eSeqReq_Old;                       // offset 0x68, size 0x4
    enmSeqReq m_eSeqReq_WakeUp;                    // offset 0x6C, size 0x4
    enmSeqReq m_eSeqReq_Next;                      // offset 0x70, size 0x4
    enmMcMovin m_eMcMovin;                         // offset 0x74, size 0x4
    enmDataType m_eDataType;                       // offset 0x78, size 0x4
    bool (*m_fncCrcCheck)(const void*);            // offset 0x7C, size 0x4
    clsMsgWnd_Task* m_pcMsgWnd;                    // offset 0x80, size 0x4
    enm_N_SelCmd m_enRtnCode;                      // offset 0x84, size 0x4
    s32 m_s32StatusReturn;                         // offset 0x88, size 0x4
    f32 m_f32PollingTime;                          // offset 0x8C, size 0x4
    clsBaseMemoryCardFile* m_pcBaseMemoryCardFile; // offset 0x90, size 0x4
    s32 m_s32FileNo;                               // offset 0x94, size 0x4
    s32 m_s32StageNo;                              // offset 0x98, size 0x4
    s8 m_s8SelCmdNum;                              // offset 0x9C, size 0x1
    u8 m_bPolling;                                 // offset 0x9D, size 0x1
    u8 m_bEndExec;                                 // offset 0x9E, size 0x1
    u8 m_bAutoSaveLock;                            // offset 0x9F, size 0x1
    s8 m_s8NextMcMovinCnt;                         // offset 0xA0, size 0x1
    s8 m_s8CursorNo;                               // offset 0xA1, size 0x1
    s8 m_s8CancelCursorNo;                         // offset 0xA2, size 0x1
    u8 m_u8Mode_Old;                               // offset 0xA3, size 0x1
};

typedef clsBaseMemoryCard_Task::enmSeqReq enmSeqReq;
typedef clsBaseMemoryCard_Task::enmPollingMc_Ret enmPollingMc_Ret;
typedef clsBaseMemoryCard_Task::enmMcMovin enmMcMovin;
typedef clsBaseMemoryCard_Task::enmRtnCode enmRtnCode;
typedef clsBaseMemoryCard_Task::enmdeleteTask_And_setAutoSave_Arg enmdeleteTask_And_setAutoSave_Arg;
typedef clsBaseMemoryCard_Task::enmdraw_UnionFont_Arg enmdraw_UnionFont_Arg;

#endif // SR2_BASE_MEMORYCARD_HPP
