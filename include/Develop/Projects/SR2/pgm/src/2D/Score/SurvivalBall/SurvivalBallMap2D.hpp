#ifndef SURVIVALBALLMAP2D_HPP
#define SURVIVALBALLMAP2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMap2D.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsScore2D_Task;

// total size: 0x80
class clsSurvivalBallMap2D : public clsScoreMap2D {
public:
    clsSurvivalBallMap2D(clsScore2D_Task* pcParent);
    virtual ~clsSurvivalBallMap2D() {}

    virtual void drawEtc(f32 (*psClipMtx)[4][4], u8 u8DrawAlpha);
    virtual void clip2Screen(nspOOMisc::stcPoint2D_s16& rsDstScreenO,
                             s32 s32vI,
                             const f32 (&orsMtx44I)[4][4],
                             const NNS_VECTORFAST& orsSrcVecI);
    virtual void drawMapMini(s16 s16BackX, s16 s16BackY, u8 u8DrawAlpha);
};

#endif // SURVIVALBALLMAP2D_HPP
