#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalMessage/SurvivalMessage2D.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

namespace nspTexData_SurvivalMessage2D {
static stcPoint2D_s16 oasUnionTextureSize = {256, 128};
static stcTexUV TexData2D[4] = {{{0.0f, 0.0f}, {244.0f, 45.0f}},
                                {{0.0f, 45.0f}, {128.0f, 33.0f}},
                                {{128.0f, 45.0f}, {128.0f, 33.0f}},
                                {{0.0f, 78.0f}, {244.0f, 45.0f}}};
} // namespace nspTexData_SurvivalMessage2D

namespace {
s32 scof32ReadyAnmWaitFrame = 30;
s32 scof32MissAnmWaitFrame = 60;
s32 scof32MissScaleWaitFrame = 30;
} // namespace

void clsSurvivalMessage2D_Task::init()
{
}

void clsSurvivalMessage2D_Task::mainReady()
{
}

void clsSurvivalMessage2D_Task::mainMiss()
{
}

void clsSurvivalMessage2D_Task::execute()
{
}

void clsSurvivalMessage2D_Task::draw()
{
}

clsSurvivalMessage2D_Task::~clsSurvivalMessage2D_Task()
{
}
