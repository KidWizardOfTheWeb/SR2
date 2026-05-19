#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMap2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotGround.hpp"

namespace {
static stcRotGroundPath asRotPath[10] = {{0.0f, -1, 39},
                                         {0.18f, -13, 42},
                                         {0.33f, -25, 37},
                                         {0.46f, -31, 31},
                                         {0.56f, -33, 26},
                                         {0.66f, -40, 15},
                                         {0.76f, -46, 2},
                                         {0.85f, -53, -10},
                                         {0.93f, -49, -23},
                                         {1.0f, -44, -28}};
} // namespace

namespace nspScoreMap2DData {
static stcDrawParam oasStageParam1v[17];
static stcDrawParam oasStageParam2v[17];
static stcDrawParam oasStageParam4v[17];
} // namespace nspScoreMap2DData

NNS_OBJECT* clsScoreMap2D::m_tpsMapObject;
stcDrawParam clsScoreMap2D::tsDebugMap;

clsScoreMap2D::clsScoreMap2D(clsScore2D_Task* pParent)
{
}

clsScoreMap2D::~clsScoreMap2D()
{
}

void clsScoreMap2D::execute()
{
}

void clsScoreMap2D::clip2Screen(nspOOMisc::stcPoint2D_s16& pt,
                                s32 idx,
                                const f32 (&mtx)[4][4],
                                const NNS_VECTORFAST& vec)
{
}

void clsScoreMap2D::draw()
{
}

void clsScoreMap2D::drawMapBg(s16 x, s16 y, u8 alpha)
{
}

void clsScoreMap2D::drawMapMini(s16 x, s16 y, u8 alpha)
{
}

void clsScoreMap2D::drawEtc(f32 (*pMtx)[4][4], u8 flags)
{
}
