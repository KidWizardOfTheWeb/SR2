#ifndef SCOREATENTIONATTACK2D_HPP
#define SCOREATENTIONATTACK2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/Score2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreHint2D.hpp"
#include "types.h"

// total size: 0x1C
struct stcAttentionData {
    s16 s16OffsetX;     // offset 0x0, size 0x2
    s16 s16OffsetY;     // offset 0x2, size 0x2
    s16 s16AreaWidth;   // offset 0x4, size 0x2
    f32 f32Scale;       // offset 0x8, size 0x4
    f32 f32DefCirScale; // offset 0xC, size 0x4
    f32 f32AddCirScale; // offset 0x10, size 0x4
    f32 f32InLength;    // offset 0x14, size 0x4
    f32 f32OutLength;   // offset 0x18, size 0x4
};

// total size: 0x3C
class clsScoreAttentionAttack2D : public clsScore2D_Task {
    // Members
public:
    clsScore2D_Task* m_pcParent;     // offset 0x4, size 0x4
    u8 m_u8Flg;                      // offset 0x8, size 0x1
    u8 m_u8Mode;                     // offset 0x9, size 0x1
    u8 m_u8Alpha;                    // offset 0xA, size 0x1
    f32 m_f32AttackScale;            // offset 0xC, size 0x4
    f32 m_f32WaitFrame;              // offset 0x10, size 0x4
    f32 m_f32SeDelayFrame;           // offset 0x14, size 0x4
    stcAttentionData* m_opsDrawData; // offset 0x18, size 0x4
    stcUserStatus m_asUserStatus[4]; // offset 0x1C, size 0x20

    // Virtual functions
public:
    clsScoreAttentionAttack2D(clsScore2D_Task* pcParent) : clsScore2D_Task(0) {}
    virtual ~clsScoreAttentionAttack2D();

    virtual void execute();
    virtual void draw();

    void init();
    void drawAtentionAttack(u32 u32View, u32 u32PlayerNo);
};

#endif // SCOREATENTIONATTACK2D_HPP
