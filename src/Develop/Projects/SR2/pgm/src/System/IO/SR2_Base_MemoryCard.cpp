#include "Develop/Projects/SR2/pgm/src/System/IO/SR2_Base_MemoryCard.hpp"

static u8 chk__clsBaseMemoryCard_Task_m_opc8SeqReqName_Debug_SizeCheck_[1];

s8* clsBaseMemoryCard_Task::m_opc8SeqReqName_Debug[15];
u8 clsBaseMemoryCard_Task::m_tbSaveFlag;
u8 clsBaseMemoryCard_Task::m_tbGhostSaveFlag;
enmRtnCode clsBaseMemoryCard_Task::m_tenRtnCode;

clsBaseMemoryCard_Task::clsBaseMemoryCard_Task(enmSeqReq eSeqReqI,
                                               enmDataType eDataTypeI,
                                               s32 s32FileNoI,
                                               s32 s32StageNoI)
    : clsTask(0, 0)
{
}

void clsBaseMemoryCard_Task::reinit(
    enmSeqReq eSeqReqI, enmDataType eDataTypeI, s32 s32FileNoI, s32 s32StageNoI, u8 eTaskModeI)
{
}

void clsBaseMemoryCard_Task::setNextSeq(enmSeqReq eSeqReqI)
{
}

void clsBaseMemoryCard_Task::setBackSeq()
{
}

void clsBaseMemoryCard_Task::setNextTaskMode(enmPollingMc_Ret eExecUnionRetI,
                                             s32 s32NextCursorNoI,
                                             s32 s32CancelCursorNoI)
{
}

void clsBaseMemoryCard_Task::setSelCmd(u32 eSelCmdI)
{
}

u8 clsBaseMemoryCard_Task::exec_UnionCursor(u32 bOnlyOkI)
{
    return 0;
}

enmPollingMc_Ret clsBaseMemoryCard_Task::deleteTask_And_setAutoSave(
    enmdeleteTask_And_setAutoSave_Arg edeleteTask_And_setAutoSave_ArgI, enmRtnCode enRtnCode)
{
    return POLLING_MC_RET___WAIT;
}

enmPollingMc_Ret clsBaseMemoryCard_Task::pollingMc(enmMcMovin eMcMovinI)
{
    return POLLING_MC_RET___WAIT;
}

enm_N_SelCmd clsBaseMemoryCard_Task::exec_UnionSelCmd(enm_N_SelCmd e_N_SelCmd_IgnoreI)
{
    return clsMsgWnd_Task::B_N_NONE;
}

void clsBaseMemoryCard_Task::execute()
{
}

void clsBaseMemoryCard_Task::draw_UnionFont(s32 s32FontTblNoI,
                                            enmdraw_UnionFont_Arg edraw_UnionFont_ArgI,
                                            s32 s32Arg3I,
                                            s32 s32Arg4I)
{
}

void clsBaseMemoryCard_Task::draw()
{
}

void clsBaseMemoryCard_Task::initCursorNo(s32 s32NextI, s32 s32CancelI)
{
}
