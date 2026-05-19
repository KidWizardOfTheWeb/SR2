#ifndef BALLHOLDER2D_HPP
#define BALLHOLDER2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Score2D.hpp"

class clsSurvivalBallBall_Task;
class clsPlayerTask;

// total size: 0x98
class clsBallHolder2D_Task : public clsTask {
public:
    clsBallHolder2D_Task(clsSurvivalBallBall_Task* pcBall);
    virtual ~clsBallHolder2D_Task();
    virtual void execute();
    virtual void draw();
    virtual void reset();

    void moveHolderIcon();
    void resetHolderChara();
    void updateHolderChara(clsPlayerTask* pcHitPlayer);

    clsSurvivalBallBall_Task* m_pcBall; // offset 0x54, size 0x4
    clsScore2D_Task* m_pcScore2D;       // offset 0x58, size 0x4
    stcPoint2D_s16 m_sBallPos;          // offset 0x5C, size 0x4
    stcPoint2D_s16 m_sCharaPos;         // offset 0x60, size 0x4
    stcPoint2D_s16 m_sOldCharaPos;      // offset 0x64, size 0x4
    s32 m_s32BallWidth;                 // offset 0x68, size 0x4
    s32 m_s32BallHeight;                // offset 0x6C, size 0x4
    s32 m_s32Rot;                       // offset 0x70, size 0x4
    s32 m_s32RotAdd;                    // offset 0x74, size 0x4
    s32 m_s32ViewNum;                   // offset 0x78, size 0x4
    f32 m_s32MapHalfWidth;              // offset 0x7C, size 0x4
    f32 m_s32BallRotCenterOffset;       // offset 0x80, size 0x4
    f32 m_f32IconScale;                 // offset 0x84, size 0x4
    s8 m_s8PauseFrame;                  // offset 0x88, size 0x1
    u8 m_u8Alpha;                       // offset 0x89, size 0x1
    s8 m_s8CharaType;                   // offset 0x8A, size 0x1
    s8 m_s8OldCharaType;                // offset 0x8B, size 0x1
    u8 m_u8CharaAlpha;                  // offset 0x8C, size 0x1
    u8 m_u8OldCharaAlpha;               // offset 0x8D, size 0x1
    u8 m_bMoveHolderFlg;                // offset 0x8E, size 0x1
    u8 m_bShotCharaIcon;                // offset 0x8F, size 0x1
    u32 m_u32OldCharaFrame;             // offset 0x90, size 0x4
    s8 m_s8HolderPlayerNo;              // offset 0x94, size 0x1

    static u32 m_oau32IconRotArrayView2[2];
    static u32 m_oau32IconRotArrayView4[4];
};

#endif // BALLHOLDER2D_HPP
