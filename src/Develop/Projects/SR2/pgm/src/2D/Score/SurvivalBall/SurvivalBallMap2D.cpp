#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBall/SurvivalBallMap2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBall/SurvivalBall2D.hpp"

namespace {
static f32 oas32MapY[17] = {0.0f,
                            -41.0f,
                            0.6f,
                            -2.5f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f,
                            0.0f};
} // namespace

namespace nspSurvivalBallMap2DData {
static stcDrawParam oasStageParam1v[17];
static stcDrawParam oasStageParam2v[17];
static stcDrawParam oasStageParam4v[17];
} // namespace nspSurvivalBallMap2DData

clsSurvivalBallMap2D::clsSurvivalBallMap2D(clsScore2D_Task* pcParent) : clsScoreMap2D(pcParent)
{
}

void clsSurvivalBallMap2D::clip2Screen(nspOOMisc::stcPoint2D_s16& rsDstScreenO,
                                       s32 s32vI,
                                       const f32 (&orsMtx44I)[4][4],
                                       const NNS_VECTORFAST& orsSrcVecI)
{
}

void clsSurvivalBallMap2D::drawMapMini(s16 s16BackX, s16 s16BackY, u8 u8DrawAlpha)
{
}

void clsSurvivalBallMap2D::drawEtc(f32 (*psClipMtx)[4][4], u8 u8DrawAlpha)
{
}
