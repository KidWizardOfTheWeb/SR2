#ifndef SURVIVALBATTLEMAP2D_HPP
#define SURVIVALBATTLEMAP2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMap2D.hpp"

struct _NNS_TEXLIST;

namespace nspSurvivalBattleMap2D {
extern _NNS_TEXLIST* psTexList_SurvivalBattleMap2D;
} // namespace nspSurvivalBattleMap2D

// total size: 0x80
class clsSurvivalBattleMap2D : public clsScoreMap2D {
public:
    virtual ~clsSurvivalBattleMap2D() {}

    virtual void clip2Screen(nspOOMisc::stcPoint2D_s16& rsDstScreenO,
                             s32 orsSrcVecI,
                             const f32 (&sParam3)[4][4],
                             const NNS_VECTORFAST& rParam4);
    virtual void drawMapMini(s16 s16BackX, s16 s16BackY, u8 u8DrawAlpha);
};

#endif // SURVIVALBATTLEMAP2D_HPP
