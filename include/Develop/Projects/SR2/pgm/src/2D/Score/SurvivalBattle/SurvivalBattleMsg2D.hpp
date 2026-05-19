#ifndef SURVIVALBATTLEMSG2D_HPP
#define SURVIVALBATTLEMSG2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x8C
class clsSurvivalBattleMsg2D_Task : public clsTask {
public:
    // Note: enmDrawType name collision with global enmDrawType in
    // SurvivalBallEffect.hpp — verify correct enum body during implementation
    enum enmDrawType {
        DRAW_MODE__HIT = 0,
        DRAW_MODE__MISSILE_DISTANCE = 1,
    };

    virtual ~clsSurvivalBattleMsg2D_Task();

    clsSurvivalBattleMsg2D_Task(u32 u32ViewNo, enmDrawType enmType, u32 u32DrawNum);

    virtual void execute();
    virtual void draw();

    void setDrawNum(u32 param_1) { m_u32DrawNum = param_1; }

    void executeHit();
    void drawHit();

    // Members
    u32 m_u32AnmType;             // offset 0x54, size 0x4
    u32 m_u32ViewNo;              // offset 0x58, size 0x4
    enum enmDrawType m_eDrawType; // offset 0x5C, size 0x4
    u32 m_u32DrawNum;             // offset 0x60, size 0x4
    s32 m_s32CenterX;             // offset 0x64, size 0x4
    s32 m_s32CenterY;             // offset 0x68, size 0x4
    s32 m_s32DrawX;               // offset 0x6C, size 0x4
    s32 m_s32DrawY;               // offset 0x70, size 0x4
    f32 m_f32Alpha;               // offset 0x74, size 0x4
    f32 m_f32AnmAlpha;            // offset 0x78, size 0x4
    f32 m_f32AnmFrame;            // offset 0x7C, size 0x4
    f32 m_f32MoveX;               // offset 0x80, size 0x4
    f32 m_f32Scale;               // offset 0x84, size 0x4
    s32 m_s32Count;               // offset 0x88, size 0x4
};

#endif // SURVIVALBATTLEMSG2D_HPP
