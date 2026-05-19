#include "Develop/Projects/SR2/pgm/src/Script/ScriptEffect.hpp"

clsModelType_OB_TX_MO_MA_MF clsScriptEffect_Task::m_tacEffect[32];
s32 clsScriptEffect_Task::m_ts32DataNum;

clsScriptEffect_Task::clsScriptEffect_Task(u32 u32View,
                                           u32 u32Effect,
                                           u32 u32Tp,
                                           u32 u32Flg,
                                           f32 f32OfsX,
                                           f32 f32OfsY,
                                           f32 f32OfsZ,
                                           u32 u32ModelNo,
                                           u32 u32NodeNo,
                                           f32 f32StartFrame,
                                           f32 f32EndFrame,
                                           f32 f32WaitFrame)
    : clsTask(0, 0)
{
}

void clsScriptEffect_Task::codeEffect(u8* pu8Ptr, clsScript_Task* pParam2)
{
}

void clsScriptEffect_Task::execute()
{
}

void clsScriptEffect_Task::draw()
{
}
