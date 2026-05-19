#include "Develop/Projects/SR2/pgm/src/Effect/Attack/ElectricDamage.hpp"

clsElectricDamageEffect_Task::~clsElectricDamageEffect_Task()
{
}

clsElectricDamageEffect_Task::clsElectricDamageEffect_Task(f32 f32LifeFrame,
                                                           u32 u32Type,
                                                           s32 s32SeId,
                                                           clsModelType_OB_TX_MO_MA* pcModel,
                                                           u32 u32StageNo,
                                                           enmNo eNo,
                                                           enmCalcNodePos eNodePos)
    : clsBaseEffect_Task(u32Type, s32SeId, pcModel, u32StageNo, 0, eNo, eNodePos, f32LifeFrame)
{
}

void clsElectricDamageEffect_Task::execute()
{
}

void clsElectricDamageEffect_Task::draw()
{
}
