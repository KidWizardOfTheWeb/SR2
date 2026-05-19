#include "Develop/Projects/SR2/pgm/src/Script/ScriptModelManager.hpp"

s32 clsScriptModelManager::m_ts32DebugModelNo = -1;
s32 clsScriptModelManager::m_ts32DebugDataNo = -1;
f32 clsScriptModelManager::m_tf32DebugSphereSize = 0.2f;
s32 clsScriptModelManager::m_ts32DebugNodeNo;
s32 clsScriptModelManager::m_ts32DataNum;
s16 clsScriptModelManager::m_tas16LineID[32];
u8* clsScriptModelManager::m_tapu8DataBuf[64];
clsScriptModel_Task* clsScriptModelManager::m_tapcModelTask[32];
clsModelType_OB_TX_MO_MA_MF clsScriptModelManager::m_tacModel[64];

void clsScriptModelManager::initData()
{
}

void clsScriptModelManager::releaseData()
{
}

s32 clsScriptModelManager::getDataNum()
{
    return 0;
}

void clsScriptModelManager::addData_Ob(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Mo(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Ma(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Mo_Ma(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Tx(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Tx_Mo(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Tx_Ma(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Tx_Mfo(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Tx_Mo_Ma(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Tx_Ma_Mfo(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::addData_Ob_Tx_Mo_Ma_Mfo(u8* puc, u32* pui, u16 us, u32 ui)
{
}

void clsScriptModelManager::playAllModel(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeModel(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeChangeMotion(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeChangeMatMotion(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeChangeMorfMotion(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeDisp(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeBackLineEffect(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeBackLineEffectDisp(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeDelLineEffect(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeFrameTexMdl(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdl_Back(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdl_FrameTex(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlPlay(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlPos(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlRot(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlScale(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlAddPos(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlAddRot(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlAddScale(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlWait(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlClear(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlMofMove(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlAllWait(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlAllClear(u8* puc, clsScript_Task* pcTask)
{
}

void clsScriptModelManager::codeMdlNodeOfs(u8* puc, clsScript_Task* pcTask)
{
}
