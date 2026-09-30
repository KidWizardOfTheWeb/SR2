#ifndef SURVIVALBATTLEPARTS2D_HPP
#define SURVIVALBATTLEPARTS2D_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

// RECONSTRUCTED: header placement.
namespace nspSurvivalBattle2D {
extern _NNS_TEXLIST* psTexList_SurvivalBattle2D;
}

class clsSurvivalBattleParts2D : public clsScoreParts2D {
public:
    virtual ~clsSurvivalBattleParts2D() {}

    virtual void drawRingWindow(s32 s32PlayerNo,
                                s32 s32View,
                                stcUnionStatus* psUnionSt,
                                s32 s32PosX,
                                s32 s32PosY,
                                s32 s32Dir,
                                u32 ou32CharaColor);

    void drawPt(s32 s32PosX, s32 s32PosY, s32 s32Dir);
};

#endif // SURVIVALBATTLEPARTS2D_HPP
