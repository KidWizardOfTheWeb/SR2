#ifndef MSGWND2D_HPP
#define MSGWND2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

enum enmMsgWndMode {
    MSGWND_MODE_NORMAL = 0,
    MSGWND_MODE_WAIT = 1,
    MSGWND_MODE_NEXT = 2,
};

// total size: 0x84
class clsMsgWnd_Task : public clsTask {
public:
    enum enm_N_SelCmd {
        B_N_NONE = 0,
        B_N_YES = 1,
        B_N_NO = 2,
        B_N_FORMAT = 3,
        B_N_DELETE = 4,
        B_N_EXIT = 5,
        B_N_REWRITE = 6,
        B_N_DELETE2 = 7,
        B_N_RETRY = 8,
        B_N_RETURN_OS = 9,
        B_N_NO_SAVE_EXIT = 10,
        B_N_CANCEL = 11,
        B_N_OK = 12,
        B_N_MAX = 13,
    };

    virtual ~clsMsgWnd_Task();
    virtual void execute();
    virtual void draw();
    virtual void end() {}
    virtual enum enm_N_SelCmd rtnCode() const { return m_enRtnCode; }

    clsMsgWnd_Task(s32 s32FontTblNoI,
                   u32 u32BtnType,
                   enm_N_SelCmd enDefBtn,
                   enm_N_SelCmd enCancelBtn,
                   u32 u32FontNo,
                   u32 u32SelFontNo);

    void draw_UnionFont(s32 s32FontTblNoI, s32 s32yI, s32 s32UyI);
    s32 drawMessage(u32 u32FontNo, s32 s32FontTblNoI, s32 s32yI, s32 s32SelectNoI);
    void setMsgNo(s32 s32FontTblNo, u32 u32FontNo);
    void setCancelCursorNo(s8 s8CursorNo);
    void setBtnType(u32 u32BtnType);
    u8 exec_UnionCursor(bool bOnlyOkI);

    enm_N_SelCmd m_enRtnCode;      // offset 0x54, size 0x4
    enm_N_SelCmd m_enCancelBtn;    // offset 0x58, size 0x4
    u32 m_u32FontNo;               // offset 0x5C, size 0x4
    u32 m_u32SelFontNo;            // offset 0x60, size 0x4
    s32 m_s32FontTblNo;            // offset 0x64, size 0x4
    u32 m_u32BtnType;              // offset 0x68, size 0x4
    enm_N_SelCmd m_ae_N_SelCmd[3]; // offset 0x6C, size 0xC
    enmMsgWndMode m_enMsgWndMode;  // offset 0x78, size 0x4
    s8 m_s8SelCmdNum;              // offset 0x7C, size 0x1
    s8 m_s8CursorNo;               // offset 0x7D, size 0x1
    u8 m_bDrawEnable;              // offset 0x7E, size 0x1
    u8 m_bDrawSelBtn;              // offset 0x7F, size 0x1
    u8 m_bOnlyOk;                  // offset 0x80, size 0x1
    u8 m_bCancelEnd;               // offset 0x81, size 0x1

    static u32 toau32BtnColor[2]; // address: 0x0069A648
};

typedef clsMsgWnd_Task::enm_N_SelCmd enm_N_SelCmd;

#endif // MSGWND2D_HPP
