#ifndef SCRIPTBLUR_HPP
#define SCRIPTBLUR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/PS2_Blur.hpp"

class clsScript_Task;

class clsScriptBlur_Task : public clsBlur_Task {
public:
    clsScriptBlur_Task(u8 p0, clsTask* p1) : clsBlur_Task(0, 0) {}

    virtual ~clsScriptBlur_Task() {}

    virtual void execute();
    virtual void draw();

    void initSet(u8 p0, u8 p1, f32 p2, f32 p3, f32 p4, u8 p5, u8 p6, f32 p7, f32 p8, f32 p9);
    void codeBlur(u8* p0, clsScript_Task* p1);
    void codeBlurEnd(u8* p0, clsScript_Task* p1);
    s32 ScriptBlur(s32 p0, s32 p1, s32 p2, s32 p3);

    u8 m_u8Type;             // offset 0x7C, size 0x1
    u8 m_u8Alpha;            // offset 0x7D, size 0x1
    u8 m_u8SAlpha;           // offset 0x7E, size 0x1
    u8 m_u8EAlpha;           // offset 0x7F, size 0x1
    s32 m_s32Rand;           // offset 0x80, size 0x4
    f32 m_f32WaitFrame;      // offset 0x84, size 0x4
    f32 m_f32Per;            // offset 0x88, size 0x4
    f32 m_f32Frame;          // offset 0x8C, size 0x4
    f32 m_f32EndFrame;       // offset 0x90, size 0x4
    f32 m_f32SPer;           // offset 0x94, size 0x4
    f32 m_f32EPer;           // offset 0x98, size 0x4
    u8 m_bEndFlg;            // offset 0x9C, size 0x1
    s16 m_s16EndFrame;       // offset 0x9E, size 0x2
    clsTask* m_pcScriptTask; // offset 0xA0, size 0x4
};

// total size: 0x18
struct stcScriptBlur {
    u8 bUsed;         // offset 0x0, size 0x1
    u8 u8Type;        // offset 0x1, size 0x1
    u8 u8Alpha;       // offset 0x2, size 0x1
    f32 f32Per;       // offset 0x4, size 0x4
    f32 f32GPer;      // offset 0x8, size 0x4
    f32 f32WaitFrame; // offset 0xC, size 0x4
    f32 f32GFrame;    // offset 0x10, size 0x4
    u8 u8StartUV;     // offset 0x14, size 0x1
    u8 u8EndUV;       // offset 0x15, size 0x1
};

#endif // SCRIPTBLUR_HPP
