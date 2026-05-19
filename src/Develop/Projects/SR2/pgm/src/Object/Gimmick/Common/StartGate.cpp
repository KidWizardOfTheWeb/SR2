#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/StartGate.hpp"

f32 STGATE_DENKI_HIT_SCALE;
f32 STGATE_LINE_Y_OFFSET;
f32 STGATE_MOVELINE_SPOS;
f32 STGATE_DENKI_SUB_FRAME;

namespace {
static f32 tof32BonusSpeedTable[10] = {0.25463f,
                                       0.277778f,
                                       0.300926f,
                                       0.324074f,
                                       0.347222f,
                                       0.37037f,
                                       0.393519f,
                                       0.416667f,
                                       0.439815f,
                                       0.462963f};
static f32 tof32BonusAgpTable[10] = {
    10.0f, 15.0f, 20.0f, 25.0f, 30.0f, 35.0f, 40.0f, 45.0f, 50.0f, 55.0f};
static f32 tof32BonusRateTable[10] = {0.0f, 0.0f, 0.0f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f};
} // namespace

void clsStartGate_Obj::createData()
{
}

void clsStartGate_Obj::destroyData()
{
}

void clsStartGate_Obj::setBonus(clsPlayerTask* pcPlayer, u32 u32RaceMSec)
{
}

void clsStartGate_Task::createModel(stcBinInfo& rParam1)
{
}

void clsStartGate_Task::execute()
{
}

void clsStartGate_Task::draw()
{
}
