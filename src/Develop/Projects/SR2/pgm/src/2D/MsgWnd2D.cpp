#include "Develop/Projects/SR2/pgm/src/2D/MsgWnd2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/TextureId.hpp"

namespace {
struct stcPoint2d {
    s16 x;
    s16 y;
};

static u8 chk__oasDrawPos_SizeCheck_[1];

stcPoint2d oasDrawPos[5] = {
    {256, 236},
    {256, 236},
    {256, 236},
    {0, 82},
    {136, 148},
};
} // namespace

u32 clsMsgWnd_Task::toau32BtnColor[2];

clsMsgWnd_Task::clsMsgWnd_Task(s32 s32FontTblNoI,
                               u32 u32BtnType,
                               enm_N_SelCmd enDefBtn,
                               enm_N_SelCmd enCancelBtn,
                               u32 u32FontNo,
                               u32 u32SelFontNo)
    : clsTask(0, 0)
{
}

clsMsgWnd_Task::~clsMsgWnd_Task()
{
}

void clsMsgWnd_Task::execute()
{
}

void clsMsgWnd_Task::draw()
{
}

u8 clsMsgWnd_Task::exec_UnionCursor(bool bOnlyOkI)
{
    return 0;
}

void clsMsgWnd_Task::setBtnType(u32 u32BtnType)
{
}

void clsMsgWnd_Task::setCancelCursorNo(s8 s8CursorNo)
{
}

void clsMsgWnd_Task::setMsgNo(s32 s32FontTblNo, u32 u32FontNo)
{
}

s32 clsMsgWnd_Task::drawMessage(u32 u32FontNo, s32 s32FontTblNoI, s32 s32yI, s32 s32SelectNoI)
{
    return 0;
}

void clsMsgWnd_Task::draw_UnionFont(s32 s32FontTblNoI, s32 s32yI, s32 s32UyI)
{
}
