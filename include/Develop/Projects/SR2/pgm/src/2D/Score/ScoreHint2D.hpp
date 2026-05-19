#ifndef SCOREHINT2D_HPP
#define SCOREHINT2D_HPP

#include "types.h"

class clsPlayerTask;
class clsScore2D_Task;

// total size: 0x6
struct stcHint2D {
    s16 s16PosX;       // offset 0x0, size 0x2
    s16 s16PosY;       // offset 0x2, size 0x2
    s16 s16ButtonPosY; // offset 0x4, size 0x2
};

// total size: 0x10
struct stcUserStatus {
    u32 u32Flg;       // offset 0x0, size 0x4
    s16 s16PosX;      // offset 0x4
    s16 s16PosY;      // offset 0x6
    f32 f32DiveFrame; // offset 0x8
    f32 f32CtrlFrame; // offset 0xC
};

// total size: 0x54
class clsScoreHint2D {
public:
    clsScoreHint2D(clsScore2D_Task* pcParent);
    virtual ~clsScoreHint2D();
    void init();
    void execute();
    void drawHint(u32 u32Arg0, u32 u32Arg1);
    void _drawHintGearChange(u32 u32Arg0, clsPlayerTask* pcArg1);
    void _drawHintCtrlR(u32 u32Arg0, clsPlayerTask* pcArg1);
    void _drawHintCtrlL(u32 u32Arg0, clsPlayerTask* pcArg1);
    void _drawHintPipe(u32 u32Arg0, clsPlayerTask* pcArg1);
    virtual void draw();

    clsScore2D_Task* m_pcParent;     // offset 0x4, size 0x4
    u8 m_bHideFlg;                   // offset 0x8, size 0x1
    u8 m_u8Alpha;                    // offset 0x9, size 0x1
    s16 m_s16ButtonY;                // offset 0xA, size 0x2
    f32 m_f32CtrlScale;              // offset 0xC, size 0x4
    f32 m_f32ButtonScale;            // offset 0x10, size 0x4
    stcUserStatus m_asUserStatus[4]; // offset 0x14, size 0x40
};

#endif // SCOREHINT2D_HPP
