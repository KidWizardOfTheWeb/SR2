#include "Develop/Projects/SR2/pgm/src/Script/ScriptCamera.hpp"

s32 clsScriptCamera::m_ts32DataNum;
u8* clsScriptCamera::m_tapu8DataBuf[64];

clsScriptCamera::clsScriptCamera()
{
}

void clsScriptCamera::calcCamera(f32 f32Frame,
                                 NNS_CAMERAPTR* psPtr,
                                 NNS_MOTION* psMotion,
                                 NNS_CAMERAPTR* psCalcPtr)
{
}

void clsScriptCamera::codeSetCamera(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScriptCamera::codeAllDelCamera(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScriptCamera::codeViewport(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScriptCamera::playCamera(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScriptCamera::setupCamera()
{
}

void clsScriptCamera::initData()
{
}

void clsScriptCamera::addData(u8* pu8BinTopAddr, u32* pu32OffsetNo, u16 u16BinNum, u32 u32LoopNum)
{
}

u8 clsScriptCamera::update()
{
    return 0;
}

u8 clsScriptCamera::setCamera()
{
    return 0;
}
