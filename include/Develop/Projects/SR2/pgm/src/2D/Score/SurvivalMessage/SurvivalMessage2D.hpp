#ifndef SURVIVALMESSAGE2D_HPP
#define SURVIVALMESSAGE2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Mission/Mission2D.hpp"

// total size: 0x8C
class clsSurvivalMessage2D_Task : public clsTask {
public:
    // Note: enuDrawMode name collision with global enuDrawMode in Mission2D.hpp
    enum enuDrawMode {
        DRAW_MODE__READY = 0,
        DRAW_MODE__MISS = 1,
    };

    virtual ~clsSurvivalMessage2D_Task();

    virtual void execute();

    void init();
    void mainReady();
    void mainMiss();
    void draw();

    // Members
    stcPos2D* m_opsPosVec;          // offset 0x54, size 0x4
    u32 m_u32AnmType;               // offset 0x58, size 0x4
    enum enuDrawMode m_eDrawModeNo; // offset 0x5C, size 0x4
    u8* m_pbEndFlag;                // offset 0x60, size 0x4
    s32 m_s32CenterX;               // offset 0x64, size 0x4
    s32 m_s32CenterY;               // offset 0x68, size 0x4
    f32 m_f32Alpha;                 // offset 0x6C, size 0x4
    f32 m_f32AnmAlpha;              // offset 0x70, size 0x4
    f32 m_f32AnmFrame;              // offset 0x74, size 0x4
    f32 m_f32MoveX;                 // offset 0x78, size 0x4
    f32 m_f32MoveY;                 // offset 0x7C, size 0x4
    f32 m_f32Scale;                 // offset 0x80, size 0x4
    s32 m_s32Count;                 // offset 0x84, size 0x4
    u32 m_u32ViewNo;                // offset 0x88, size 0x4
};

#endif // SURVIVALMESSAGE2D_HPP
