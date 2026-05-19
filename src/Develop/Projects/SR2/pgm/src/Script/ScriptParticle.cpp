#include "Develop/Projects/SR2/pgm/src/Script/ScriptParticle.hpp"

clsScriptParticle_Task::clsScriptParticle_Task(u32 u32View,
                                               u32 u32Code,
                                               f32 f32OfsX,
                                               f32 f32OfsY,
                                               f32 f32OfsZ,
                                               u32 u32ModelNo,
                                               u32 u32NodeNo,
                                               f32 f32InterFrame,
                                               f32 f32StartFrame,
                                               f32 f32EndFrame,
                                               f32 f32Wait)
    : clsTask(0, 0)
{
    m_u32View = u32View;
    m_u32Code = u32Code;
    m_u32ModelNo = u32ModelNo;
    m_u32NodeNo = u32NodeNo;
    m_sOfsVec.x = f32OfsX;
    m_sOfsVec.y = f32OfsY;
    m_sOfsVec.z = f32OfsZ;
    m_f32InterFrame = f32InterFrame;
    m_f32PlayFrame = f32StartFrame;
    m_f32Frame = f32StartFrame;
    m_f32EndFrame = f32EndFrame;
    m_f32WaitFrame = f32Wait;
}

void clsScriptParticle_Task::codeParticle(u8* pu8Ptr, clsScript_Task* pParam2)
{
}

void clsScriptParticle_Task::execute()
{
}

clsScriptParticle_Task::~clsScriptParticle_Task()
{
}
