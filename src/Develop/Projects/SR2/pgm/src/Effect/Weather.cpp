#include "Develop/Projects/SR2/pgm/src/Effect/Weather.hpp"

namespace nspWeatherData {
clsWeather_Task::stcStatus oasStatus[6];
clsWeather_Task::stcStatus oasStatusMulti[6];
stcWaterDropStatus oasWaterDropStatus[2];
} // namespace nspWeatherData

namespace nspWeather {
NNS_VECTOR osWindyVec[8];
}

static NNS_VECTOR DefArea;
static NNS_VECTOR tsTestColPos;
static NNS_VECTOR tsTestColRot;
static NNS_VECTOR tsTestColScale = {10.0f, 10.0f, 10.0f};
static void (*m_oasexeWeather[9])(clsWeather_Task::stcStatus*,
                                  clsWeather_Task::stcSeed*,
                                  f32 (*)[4][4]);

stcDebugWeather clsWeather_Task::sDebugInfo;

clsWeather_Task::clsWeather_Task(u32 u32A, u8 u8B) : clsTask(0, 0)
{
}

void clsWeather_Task::setDeafaultInfo(u8 u8A)
{
}

s32 clsWeather_Task::DebugInfo(s32 s32A, s32 s32B, s32 s32C, s32 s32D)
{
    return 0;
}

void clsWeather_Task::setWeather(u8 u8Weather)
{
}

void clsWeather_Task::execute()
{
}

void clsWeather_Task::drawNotBill()
{
}

void clsWeather_Task::drawBill()
{
}

void clsWeather_Task::draw()
{
}
