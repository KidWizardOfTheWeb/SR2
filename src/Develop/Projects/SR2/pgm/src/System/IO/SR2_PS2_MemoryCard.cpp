#include "Develop/Projects/SR2/pgm/src/System/IO/SR2_PS2_MemoryCard.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/IO/PS2MemoryCard.hpp"

namespace {
sceMcIconSys sIconSysGame;
sceMcIconSys sIconSysGhost;
clsPfMemoryCard::stcIconData tsMcGameIcon;
clsPfMemoryCard::stcIconData tsMcGhostIcon;
static u32 tau32GameIconSize[3] = {47972, 44438, 42096};
u32 tau32GhostIconSize[3][16];
c8* taoc8oGameTitleName[6];
c8* taoc8oGhostTitleName[6];
c8* taoc8oNumberTbl[16];
} // namespace

void* clsMemoryCard_Task::m_tpvOldLoadDataBuff;
void* clsMemoryCard_Task::m_tpvOldGhostDataBuff;
u8 clsMemoryCard_Task::m_tbOldLoadData;
u8 clsMemoryCard_Task::m_tbOldGhostData;
u8 clsMemoryCard_Task::m_tbEndFlag;
u8 clsMemoryCard_Task::m_tbInitGhostInsertChk;

void clsMemoryCard_Task::createOldDataBuff()
{
}

u8 clsMemoryCard_Task::checkOldGameSaveData(const void* pvDataBuff)
{
    return 0;
}

u8 clsMemoryCard_Task::checkOldGhostSaveData(const void* pvDataBuff)
{
    return 0;
}

clsMemoryCard_Task::clsMemoryCard_Task(enmSeqReq eSeqReqI,
                                       enmDataType eDataTypeI,
                                       s32 s32FileNoI,
                                       s32 s32StageNoI)
    : clsBaseMemoryCard_Task(eSeqReqI, eDataTypeI, s32FileNoI, s32StageNoI)
{
}

void clsMemoryCard_Task::pollingMc_Pf()
{
}

void clsMemoryCard_Task::pollingMc_Pf_End()
{
}

void clsMemoryCard_Task::setCmdNormalMsg()
{
}

void clsMemoryCard_Task::setCmdUnionError()
{
}

void clsMemoryCard_Task::draw_NormalMsg()
{
}

void clsMemoryCard_Task::draw_UnionError()
{
}

void clsMemoryCard_Task::initCursorNo(s32 s32NextI, s32 s32CancelI)
{
}

void clsMemoryCard_Task::setNextTaskMode(enmPollingMc_Ret eExecUnionRetI,
                                         s32 s32NextCursorNoI,
                                         s32 s32CancelCursorNoI)
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___BOOT()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___BOOT()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___FILE_SELECT()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___FILE_SELECT()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___DELETE()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___DELETE()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___SAVE()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___SAVE()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___LOAD()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___LOAD()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___END()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___END()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___FORMAT()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___FORMAT()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___GHOST_START()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___GHOST_START()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___CHANGE_CHK()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___CHANGE_CHK()
{
}

void clsMemoryCard_Task::exec_SEQ_REQ___UNFORMAT_DEBUG()
{
}

void clsMemoryCard_Task::draw_SEQ_REQ___UNFORMAT_DEBUG()
{
}
