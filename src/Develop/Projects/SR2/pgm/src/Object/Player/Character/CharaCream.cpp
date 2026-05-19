#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaCream.hpp"

f32 tof32AliveFrame;
f32 tof32MaxScaleFrame;
f32 tof32MaxScale;
f32 clsCharaCream::tof32CollisionRadius = 0.6f;

void clsCharaCream::behavior()
{
}

void clsCharaCream::initAttack00()
{
}

void clsCharaCream::initAttack01()
{
}

void clsCharaCream::actionAttack00()
{
}

void clsCharaCream::actionAttack01()
{
}

void clsCharaCream::draw(u32 u32AddDrawFlagI)
{
}

void clsCharaCream::loadAdditionalData(stcBinInfo& rsBinInfo)
{
}

clsCreamAttackEffectTask::clsCreamAttackEffectTask(u32 u32Param1, u32 u32Param2) : clsTask(0, 0)
{
}

clsCreamAttackEffectTask::~clsCreamAttackEffectTask()
{
}

void clsCreamAttackEffectTask::execute()
{
}

void clsCreamAttackEffectTask::draw()
{
}

clsCharaCream::clsCharaCream(clsPlayerTask* pcPlayer, u8 u8ModelType)
    : clsCharaNodeBase(pcPlayer, u8ModelType, 0)
{
}
