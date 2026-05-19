#include "Develop/Projects/SR2/pgm/src/2D/Score/Mission/MissionMssage2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/TexData2D/MissionMessage2D_TexData.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"

namespace {
static s32 scof32CompAnmWaitFrame = 30;
static s32 scof32FailAnmWaitFrame = 60;
static s32 scof32GoAnmWaitFrame = 30;
} // namespace

namespace nspTexData_Loading2D {
stcPoint2D_s16 oasUnionTextureSize[2] = {{256, 256}, {256, 256}};

stcTexUV TexData2D[25] = {{{0.0f, 0.0f}, {256.0f, 256.0f}},   {{1.0f, 1.0f}, {132.0f, 35.0f}},
                          {{145.0f, 1.0f}, {34.0f, 35.0f}},   {{181.0f, 1.0f}, {34.0f, 35.0f}},
                          {{217.0f, 1.0f}, {34.0f, 35.0f}},   {{1.0f, 38.0f}, {34.0f, 35.0f}},
                          {{37.0f, 38.0f}, {34.0f, 35.0f}},   {{73.0f, 38.0f}, {34.0f, 35.0f}},
                          {{109.0f, 38.0f}, {34.0f, 35.0f}},  {{145.0f, 38.0f}, {34.0f, 35.0f}},
                          {{181.0f, 38.0f}, {34.0f, 35.0f}},  {{217.0f, 38.0f}, {34.0f, 35.0f}},
                          {{1.0f, 75.0f}, {255.0f, 25.0f}},   {{131.0f, 102.0f}, {125.0f, 154.0f}},
                          {{36.0f, 217.0f}, {2.0f, 37.0f}},   {{40.0f, 217.0f}, {56.0f, 37.0f}},
                          {{91.0f, 217.0f}, {2.0f, 37.0f}},   {{1.0f, 217.0f}, {28.0f, 28.0f}},
                          {{27.0f, 217.0f}, {2.0f, 28.0f}},   {{1.0f, 243.0f}, {28.0f, 2.0f}},
                          {{102.0f, 219.0f}, {6.0f, 6.0f}},   {{1.0f, 102.0f}, {34.0f, 113.0f}},
                          {{46.0f, 102.0f}, {51.0f, 113.0f}}, {{99.0f, 102.0f}, {30.0f, 113.0f}},
                          {{40.0f, 102.0f}, {2.0f, 113.0f}}};
} // namespace nspTexData_Loading2D

void clsMissionMessage2D_Task::init()
{
}

void clsMissionMessage2D_Task::mainComplete()
{
}

void clsMissionMessage2D_Task::mainFailedTimeUp()
{
}

void clsMissionMessage2D_Task::mainGo()
{
}

void clsMissionMessage2D_Task::mainFastMission()
{
}

void clsMissionMessage2D_Task::execute()
{
}

void clsMissionMessage2D_Task::draw()
{
}

void clsMissionMessage2D_Task::drawNowLoading()
{
}

void clsMissionMessage2D_Task::drawFastMission()
{
}
