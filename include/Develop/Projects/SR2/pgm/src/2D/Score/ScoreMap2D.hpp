#ifndef SCOREMAP2D_HPP
#define SCOREMAP2D_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

class clsScore2D_Task;
namespace nspOOMisc {
struct stcPoint2D_s16;
}

// total size: 0x2B
struct stcDrawPath {
    s8 s8PathType;        // offset 0x0, size 0x1
    s8 as8LineNo[7];      // offset 0x1, size 0x7
    u8 au8DispFlag[7][5]; // offset 0x8, size 0x23
};

// total size: 0x1C
struct stcDrawParam {
    f32 Scale;      // offset 0x0, size 0x4
    NNS_VECTOR Rot; // offset 0x4, size 0xC
    NNS_VECTOR Pos; // offset 0x10, size 0xC
};

// total size: 0x80
class clsScoreMap2D {
public:
    clsScoreMap2D(clsScore2D_Task* pParam1);
    virtual ~clsScoreMap2D();
    virtual void draw();
    virtual void drawEtc(f32 (*)[4][4], u8 u8Param2);
    virtual void clip2Screen(nspOOMisc::stcPoint2D_s16& rParam1,
                             s32 s32Param2,
                             const f32 (&)[4][4],
                             const NNS_VECTORFAST& rParam4);
    virtual void drawMapBg(s16 s16Param1, s16 s16Param2, u8 u8Param3);
    virtual void drawMapMini(s16 s16Param1, s16 s16Param2, u8 u8Param3);

    void execute();

    static NNS_OBJECT* m_tpsMapObject; // size 0x4
    static stcDrawParam tsDebugMap;    // size 0x1C

    s16 m_s16BackX;              // offset 0x4, size 0x2
    s16 m_s16BackY;              // offset 0x6, size 0x2
    clsScore2D_Task* m_pcParent; // offset 0x8, size 0x4
    u8 m_bDraw;                  // offset 0xC, size 0x1
    u8 m_u8IconAlpha;            // offset 0xD, size 0x1
    s16 m_s16IconXDiff;          // offset 0xE, size 0x2
    s16 m_s16IconYDiff;          // offset 0x10, size 0x2
    f32 m_f32AttackScale;        // offset 0x14, size 0x4
    f32 m_f32UserScale;          // offset 0x18, size 0x4
    s32 m_as32DamageRot[8];      // offset 0x1C, size 0x20
    f32 m_sMtx[4][4];            // offset 0x40, size 0x40
};

#endif // SCOREMAP2D_HPP
