#include "Develop/Projects/SR2/pgm/src/Effect/GravityFin/GravityFin.hpp"

clsGravityFinEffect_Task::clsGravityFinEffect_Task(u32 u32Param1,
                                                   s32 s32Param2,
                                                   clsModelType_OB_TX_MO_MA* pcModel,
                                                   u32 u32Param5,
                                                   u32 u32Param6,
                                                   nspPlayer::enmNo eNo,
                                                   clsPlayerTask::enmCalcNodePos eNodePos)
    : clsBaseEffect_Task(u32Param1,
                         s32Param2,
                         pcModel,
                         u32Param5,
                         u32Param6,
                         (enmNo)eNo,
                         (enmCalcNodePos)eNodePos,
                         0.0f)
{
}

void clsGravityFinEffect_Task::execute()
{
}

void clsGravityFinEffect_Task::draw()
{
}
