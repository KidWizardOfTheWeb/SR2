#ifndef SURVIVALBALLEFFECT_HPP
#define SURVIVALBALLEFFECT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsPlaySe_2D;

enum enmDrawType {
    DRAW_TYPE__DRAW = 0,
    DRAW_TYPE__STOP = 1,
    DRAW_TYPE__NOT = 2,
    DRAW_TYPE__END = 3,
    AFTERIMAGE_COUNT = 20,
};

// total size: 0x240
class clsSurvivalBallBallEffect_Task : public clsTask {
public:
    clsSurvivalBallBallEffect_Task(u32 eEffectType,
                                   enmDrawType* peDrawFlag,
                                   NNS_VECTORFAST* psPosVec,
                                   u32* pu32EffectFlag,
                                   u32 u32TaskNo);
    virtual ~clsSurvivalBallBallEffect_Task() {}
    virtual void execute();
    virtual void draw();

    void executeAfterimage();
    void drawRange();
    void drawLookOn();
    void drawGetPlayerEffect();
    void drawAfterimage();

    enmDrawType* m_peDrawFlag;  // offset 0x54, size 0x4
    u32 m_eEffectType;          // offset 0x58, size 0x4
    u32* m_pu32EffectFlag;      // offset 0x5C, size 0x4
    NNS_VECTORFAST* m_psPosVec; // offset 0x60, size 0x4
    // gap 0x64–0x6F (alignment padding for NNS_VECTORFAST 16-byte alignment)
    NNS_VECTORFAST m_asAfterimagePosVec[20]; // offset 0x70, size 0x140
    f32 m_asMatMotionFrame[20];              // offset 0x1B0, size 0x50
    clsPlaySe_2D* m_pcPlaySe2D;              // offset 0x200, size 0x4
    s32 m_s32SePlayFrame;                    // offset 0x204, size 0x4
    u32 m_u32BreakPlayerFlag;                // offset 0x208, size 0x4
    f32 m_f32Scale;                          // offset 0x20C, size 0x4
    f32 m_f32AddScale;                       // offset 0x210, size 0x4
    f32 m_f32MotionFrame;                    // offset 0x214, size 0x4
    f32 m_f32MotionAddFrame;                 // offset 0x218, size 0x4
    f32 m_f32MatMotionFrame;                 // offset 0x21C, size 0x4
    s32 m_s32ViewNo;                         // offset 0x220, size 0x4
    s32 m_s32Count;                          // offset 0x224, size 0x4
    s32 m_s32GetPosCount;                    // offset 0x228, size 0x4
    s32 m_s32AfterimageCountMax;             // offset 0x22C, size 0x4
    f32 m_f32Speed;                          // offset 0x230, size 0x4
};

#endif // SURVIVALBALLEFFECT_HPP
