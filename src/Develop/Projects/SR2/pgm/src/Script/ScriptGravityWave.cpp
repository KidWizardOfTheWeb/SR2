#include "Develop/Projects/SR2/pgm/src/Script/ScriptGravityWave.hpp"

clsScriptNega_Task::clsScriptNega_Task(u8 u8PriorityType,
                                       u8 u8Type,
                                       u8 u8rgb,
                                       f32 f32Frame,
                                       f32 f32SubFrame,
                                       f32 f32EndFrame,
                                       f32 f32WaitFrame,
                                       clsTask* pcTask)
    : clsGravityWave_Task(0, 0)
{
}

void clsScriptNega_Task::codeNega(u8* pu8Ptr, clsScript_Task* pParam2)
{
}

void clsScriptNega_Task::codeNegaEnd(u8* pu8Ptr, clsScript_Task* pParam2)
{
}

s32 clsScriptNega_Task::DebugNega(s32 s32xI, s32 s32yI, s32 s32ActiveNoI, s32 s32SpeedI)
{
    return 0;
}

void clsScriptNega_Task::execute()
{
}

void clsScriptNega_Task::draw()
{
}

clsScriptWave_Task::clsScriptWave_Task(u8 u8Param1, f32 fParam1, f32 fParam2, clsTask* pcTask)
    : clsGravityWave_Task(0, 0)
{
}

void clsScriptWave_Task::codeWave(u8* pu8Ptr, clsScript_Task* pParam2)
{
}

void clsScriptWave_Task::codeWaveEnd(u8* pu8Ptr, clsScript_Task* pParam2)
{
}

s32 clsScriptWave_Task::DebugWave(s32 s32Param1, s32 s32Param2, s32 s32Param3, s32 s32Param4)
{
    return 0;
}

void clsScriptWave_Task::execute()
{
}

void clsScriptWave_Task::draw()
{
}
