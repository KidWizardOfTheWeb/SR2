#ifndef SAVEDATA2D_HPP
#define SAVEDATA2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/MsgWnd2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/System/IO/SR2_PS2_MemoryCard.hpp"
class clsKeyboard2D_Task;

// total size: 0x20
struct stcDrawSaveData {
    s16 s16Width;          // offset 0x0, size 0x2
    s16 s16NextDataWidth;  // offset 0x2, size 0x2
    s16 s16TopHeight;      // offset 0x4, size 0x2
    s16 s16AnderHeight;    // offset 0x6, size 0x2
    s16 s16TopX;           // offset 0x8, size 0x2
    s16 s16TopY;           // offset 0xA, size 0x2
    s16 s16TopWMargin;     // offset 0xC, size 0x2
    s16 s16TopLineDiffY;   // offset 0xE, size 0x2
    s16 s16TopNumX;        // offset 0x10, size 0x2
    s16 s16TopNumY;        // offset 0x12, size 0x2
    s16 s16ItemX;          // offset 0x14, size 0x2
    s16 s16ItemY;          // offset 0x16, size 0x2
    s16 s16ItemSpace;      // offset 0x18, size 0x2
    s16 s16ItemMargin;     // offset 0x1A, size 0x2
    s16 s16ItemInX;        // offset 0x1C, size 0x2
    s16 s16ItemMarginText; // offset 0x1E, size 0x2
};

// total size: 0x74
class clsSaveData2D_Task : public clsTask {
public:
    virtual ~clsSaveData2D_Task() {}
    virtual void execute();
    virtual void draw();

    clsSaveData2D_Task(clsAdvertiseMgr_Task* pcAdvertiseMgr_Task, bool bCancel, bool bOptionCheck);

    void drawWindow(s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color, u32 u32DecoType);
    void drawSelectWindow(s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color);
    void drawTopConsole(u32 u32No, s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color);
    void drawAnderConsole(u32 u32No, s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color);
    void drawTime(u32 u32TotalTime, f32 f32X, f32 f32Y, u32 u32Color);
    void drawMisson(u32 u32MissonNum, f32 f32X, f32 f32Y, u32 u32Color);
    void drawGear(u32 u32GearNum, f32 f32X, f32 f32Y, u32 u32Color);
    void drawDate(u16 u16Year, u8 u8Month, u8 u8Day, f32 f32X, f32 f32Y, u32 u32Color);
    void drawRing(u32 u32RingNum, f32 f32X, f32 f32Y, u32 u32Color);
    void drawData(u32 u32No);

    // Members
    u8 m_bCancel;                                // offset 0x54, size 0x1
    u8 m_bOptionCheck;                           // offset 0x55, size 0x1
    u8 m_bLoadData;                              // offset 0x56, size 0x1
    u8 m_bCanceled;                              // offset 0x57, size 0x1
    u32 m_u32SelectNo;                           // offset 0x58, size 0x4
    s16 m_s16LeftX;                              // offset 0x5C, size 0x2
    s16 m_s16TopY;                               // offset 0x5E, size 0x2
    u32 m_u32OldMessage;                         // offset 0x60, size 0x4
    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x64, size 0x4
    clsMemoryCard_Task* m_pcMemocaTask;          // offset 0x68, size 0x4
    clsKeyboard2D_Task* m_pcKeyBoardTask;        // offset 0x6C, size 0x4
    clsMsgWnd_Task* m_pcMsgWndTask;              // offset 0x70, size 0x4
};

#endif // SAVEDATA2D_HPP
