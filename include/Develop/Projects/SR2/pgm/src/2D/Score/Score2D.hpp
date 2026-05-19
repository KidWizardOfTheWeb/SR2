#ifndef SCORE2D_HPP
#define SCORE2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOSystem.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Screen2D.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsScoreAttentionAttack2D;
class clsScoreCom2D;
class clsScoreHint2D;
class clsScoreInfo2D;
class clsScoreMap2D;
class clsScoreMeter2D;
class clsScoreParts2D;
class clsScoreRecord2D;
class clsScoreTimer2D;

// total size: 0x120
class clsScore2D_Task : public clsTask, public clsScreen2D {
public:
    clsScore2D_Task(s32 s32Arg0);
    virtual ~clsScore2D_Task();
    virtual void execute();
    virtual void draw();

    u8 getAlpha() const { return m_u8Alpha; }

    void setRecordTime(s32 s32Arg0, f32 f32Arg1);
    void setStartPos(f32 f32Arg0, f32 f32Arg1, f32 f32Arg2);
    void setStartRot(f32 f32Arg0, f32 f32Arg1, f32 f32Arg2);
    void drawReverseMark();

    static f32 DrawRecordTime;
    static NNS_VECTOR m_tsStartPosVec;
    static NNS_VECTOR m_tsStartRotVec;

    s32 m_s32ViewNum;                              // offset 0x94, size 0x4
    u8 m_u8Alpha;                                  // offset 0x98, size 0x1
    s8 m_s8MoveX;                                  // offset 0x99, size 0x1
    s8 m_s8MoveY;                                  // offset 0x9A, size 0x1
    s8 m_s8MoveXMax;                               // offset 0x9B, size 0x1
    s8 m_s8MoveYMax;                               // offset 0x9C, size 0x1
    s8 m_s8PauseFrame;                             // offset 0x9D, size 0x1
    stcViewRect m_asRect[5];                       // offset 0xA0, size 0x50
    u8 m_au8Flg[5];                                // offset 0xF0, size 0x5
    u16 m_u16ReverseAlpha;                         // offset 0xF6, size 0x2
    u8 m_u8ReverseWidth;                           // offset 0xF8, size 0x1
    u8 m_u8ReverseHeight;                          // offset 0xF9, size 0x1
    s8 m_s8ReversePosXDiff;                        // offset 0xFA, size 0x1
    s8 m_s8ReversePosYDiff;                        // offset 0xFB, size 0x1
    clsScoreMeter2D* m_pcMeter;                    // offset 0xFC, size 0x4
    clsScoreParts2D* m_pcParts;                    // offset 0x100, size 0x4
    clsScoreInfo2D* m_pcInfo;                      // offset 0x104, size 0x4
    clsScoreMap2D* m_pcMap;                        // offset 0x108, size 0x4
    clsScoreTimer2D* m_pcTimer;                    // offset 0x10C, size 0x4
    clsScoreRecord2D* m_pcRecord;                  // offset 0x110, size 0x4
    clsScoreHint2D* m_pcHint;                      // offset 0x114, size 0x4
    clsScoreAttentionAttack2D* m_pcAtentionAttack; // offset 0x118, size 0x4
    clsScoreCom2D* m_pcCom;                        // offset 0x11C, size 0x4
};

#endif // SCORE2D_HPP
