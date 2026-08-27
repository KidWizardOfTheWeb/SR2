#include "Develop/Projects/SR2/pgm/src/Effect/IonMist/IonMist.hpp"

namespace nspIonMist {
static clsIonMist_Task::stcParam StageParam[5];
} // namespace nspIonMist

_NNS_TEXLIST* clsIonMist_Task::m_psTex;
u8 clsIonMist_Task::m_tu8DrawFlg;
u8 clsIonMist_Task::m_tbSpFlg;
clsIonMist_Task::stcParam clsIonMist_Task::m_tsDebugFullParam;
clsIonMist_Task::stcDebugParam clsIonMist_Task::m_tsDebugParam;

clsIonMist_Task::clsIonMist_Task(u8 u8StageNo) : clsTask(0, 0)
{
}

void clsIonMist_Task::setData(u8 u8StageNo)
{
}

s32 clsIonMist_Task::DebugInfo(s32 s32xI, s32 s32yI, s32 s32ActiveNoI, s32 s32Param4)
{
    return 0;
}

void clsIonMist_Task::anmTexArea(stcTexUV* psTex, clsIonMist_Task::stcTexArea* psTexArea)
{
}

void clsIonMist_Task::execute()
{
}

u8 clsIonMist_Task::calcNearAlpha(u32 u32View)
{
    return 0;
}

u8 clsIonMist_Task::calcFarAlpha(u32 u32View, f32* pf32OfsZ)
{
    return 0;
}

void clsIonMist_Task::draw()
{
}
