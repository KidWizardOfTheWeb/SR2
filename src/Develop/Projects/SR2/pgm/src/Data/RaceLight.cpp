#include "Develop/Projects/SR2/pgm/src/Data/RaceLight.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

namespace {
struct stcRgbF32 {
    f32 f32r;
    f32 f32g;
    f32 f32b;
};

struct stcRgbaF32 {
    f32 f32r;
    f32 f32g;
    f32 f32b;
    f32 f32a;
};

struct stcBinDataDetail {
    stcRgbF32 sAmbientRgb;
    stcRgbaF32 sParallelRgba;
    f32 f32ParallelInten;
    NNS_VECTOR sParallelDir;
    NNS_VECTOR sParallelPos;
    stcRgbaF32 sSpecularRgba;
    NNS_VECTOR sSpecularDir;
};
} // namespace

namespace nspDefaultLightData {
static stcBinDataDetail otasDefaultDataDetail = {{1.0f, 1.0f, 1.0f},
                                                 {1.0f, 1.0f, 1.0f, 1.0f},
                                                 1.0f,
                                                 {0.0f, -1.0f, 0.0f},
                                                 {0.0f, 1000.0f, 0.0f},
                                                 {0.5f, 0.5f, 0.5f, 1.0f},
                                                 {0.0f, -1.0f, 0.0f}};
} // namespace nspDefaultLightData

clsRaceLight_Task::clsRaceLight_Task() : clsTask(0, 0)
{
}

void clsRaceLight_Task::draw()
{
}
