#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/HideKicker.hpp"

f32 clsHideKicker_Obj::m_tof32ClipSqDist;

namespace nspHideKicker {
static stcInfo toasGroundInfo[1];
static NNS_VECTOR toasBoxSize[1] = {{3.1f, 1.0f, 3.8f}};
static f32 toaf32Vertices[16];
static f32 toaf32PlaneEquations[8][4];
static u32 tobFix = 8;
} // namespace nspHideKicker

void clsHideKickerThroughCol::contactAlwaysEvent(clsPlayerTask* pParam1)
{
}

void clsHideKicker_Obj::init()
{
}

void clsHideKicker_Obj::reset()
{
}

void clsHideKicker_Obj::setData()
{
}

void clsHideKicker_Obj::createData()
{
}

void clsHideKicker_Obj::destroyData()
{
}

void clsHideKicker_Obj::contactTriggerEvent(hkContactPoint* pcParam1, clsObject* pcParam2)
{
}

void clsHideKicker_Obj::contactAlwaysEvent(hkContactPoint* pcParam1, clsObject* pcParam2)
{
}

void clsHideKicker_Obj::main()
{
}

clsHideKicker_Task::clsHideKicker_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsHideKicker_Task, clsHideKicker_Obj, clsModelType_OB_TX_MO>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsHideKicker_Task::reset()
{
}

void clsHideKicker_Task::execute()
{
}

void clsHideKicker_Task::draw()
{
}

clsHideKicker_Obj::clsHideKicker_Obj()
{
}

clsHideKicker_Obj::~clsHideKicker_Obj()
{
}

nspPackId::enm clsHideKicker_Obj::getPackId() const
{
    return nspPackId::HIDE_KICKER_2160;
}
