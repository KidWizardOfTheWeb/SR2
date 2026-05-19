#ifndef KEYBOARD2D_HPP
#define KEYBOARD2D_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"

class clsSaveDataCtrl;
struct _NNS_TEXLIST;

namespace nspKeyboard2D {
extern _NNS_TEXLIST* psTexList_Keyboard2D;
} // namespace nspKeyboard2D

// total size: 0x4
struct stcDrawPos_s16 {
    s16 s16x; // offset 0x0, size 0x2
    s16 s16y; // offset 0x2, size 0x2
};

// total size: 0x2
struct stcSupportKeyData {
    u8 u8KeyNo;   // offset 0x0, size 0x1
    s8 s8KeyType; // offset 0x1, size 0x1
};

// total size: 0xC
struct stcPoint3d {
    f32 x; // offset 0x0, size 0x4
    f32 y; // offset 0x4, size 0x4
    f32 z; // offset 0x8, size 0x4
};

// total size: 0x8 (s32 variant)
struct stcPoint2d {
    s32 x; // offset 0x0, size 0x4
    s32 y; // offset 0x4, size 0x4
};

// total size: 0x8 (s32 variant)
struct stcSize2d {
    s32 w; // offset 0x0, size 0x4
    s32 h; // offset 0x4, size 0x4
};

// total size: 0x10
struct stcRect {
    stcPoint2d sPos; // offset 0x0, size 0x8
    stcSize2d sSize; // offset 0x8, size 0x8
};

// total size: 0x1A8
class clsKeyboard2D_Task : public clsTask {
public:
    // Note: enmRet collides with unrelated DWARF enum bodies; this body matches clsKeyboard2D_Task.
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

    virtual ~clsKeyboard2D_Task() {}

    void init();
    virtual void execute();
    virtual void draw();
    void exeCursorMove();
    void deleteOneLetter();
    void drawKey(s32 s32x, s32 s32y);
    void drawNormalKey(s32 s32x, s32 s32y, s32 s32w, s32 s32h, bool bColor, s8 s8Select);
    void drawWideKey(s32 s32x, s32 s32y, s32 s32w, s32 s32h, s8 s8Select);
    void drawMessageWindow(s32 s32x, s32 s32y);
    void drawNameWindow(s32 s32x, s32 s32y);
    void drawKeyText();
    void drawKeyTextEach(s32 s32TextNo,
                         s32 s32TexPos,
                         s32 s32x,
                         s32 s32y,
                         f32 f32w,
                         f32 f32h,
                         s16 s16TexSizeU,
                         s16 s16TexSizeV,
                         s8 s8Select);

    static u32 m_oau32KeyTypeWidth[8];

    void* m_pvKeyboardDataBuff;        // offset 0x54, size 0x4
    enmRet m_eKeyboardDataBuff_Ret;    // offset 0x58, size 0x4
    u8 m_bLoadFlag;                    // offset 0x5C, size 0x1
    u8 m_bCancel;                      // offset 0x5D, size 0x1
    stcDrawPos_s16 m_sDrawPos[44];     // offset 0x5E, size 0xB0
    stcPoint3d sNamePos;               // offset 0x110, size 0xC
    stcRect m_sNameDrawRect;           // offset 0x11C, size 0x10
    s32 m_s32PadNo;                    // offset 0x12C, size 0x4
    f32 m_f32CslB;                     // offset 0x130, size 0x4
    f32 m_f32SelectScale;              // offset 0x134, size 0x4
    s32 m_f32NameBarX;                 // offset 0x138, size 0x4
    s32 m_s32CenterX;                  // offset 0x13C, size 0x4
    f32 m_f32DefFontSize;              // offset 0x140, size 0x4
    u32 m_u32DefCharaSpace;            // offset 0x144, size 0x4
    u16 m_au16UserName[11];            // offset 0x148, size 0x16
    s16 m_s16DrawX;                    // offset 0x15E, size 0x2
    s16 m_s16DrawY;                    // offset 0x160, size 0x2
    s16 m_s16BGLeft;                   // offset 0x162, size 0x2
    s16 m_s16BGRight;                  // offset 0x164, size 0x2
    s16 m_s16BGHeight;                 // offset 0x166, size 0x2
    s8 m_s8DrawKey[44];                // offset 0x168, size 0x2C
    u8 m_u8Alpha;                      // offset 0x194, size 0x1
    u8 m_uPageFlag;                    // offset 0x195, size 0x1
    u8 m_u8NameCount;                  // offset 0x196, size 0x1
    s8 m_s8CursorPos;                  // offset 0x197, size 0x1
    s8 m_s8OldPos;                     // offset 0x198, size 0x1
    s8 m_s8CursorX;                    // offset 0x199, size 0x1
    s8 m_s8CursorY;                    // offset 0x19A, size 0x1
    s8 m_s8OldCursorX;                 // offset 0x19B, size 0x1
    s8 m_s8OldCursorY;                 // offset 0x19C, size 0x1
    s8 m_s8AnimeCount;                 // offset 0x19D, size 0x1
    s8 m_s8AnimeFream;                 // offset 0x19E, size 0x1
    u8 m_bSptKeyOnFlag;                // offset 0x19F, size 0x1
    s8 m_s8BarFream;                   // offset 0x1A0, size 0x1
    u8 m_bBarAnimeEnable;              // offset 0x1A1, size 0x1
    u8 m_bBarDrawFlag;                 // offset 0x1A2, size 0x1
    clsSaveDataCtrl* m_pcSaveDataCtrl; // offset 0x1A4, size 0x4
};

#endif // KEYBOARD2D_HPP
