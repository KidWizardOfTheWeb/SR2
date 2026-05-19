#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03ExtraLamp.hpp"

_stcColorParam clsExtraLamp_Task::m_tosColorParam[5];

void clsExtraLamp_Obj::createData()
{
}

void clsExtraLamp_Obj::destroyData()
{
}

void clsExtraLamp_Obj::draw(clsModelType_OB_TX& rcModel,
                            f32 (*psMtxPal)[4][4],
                            u32* psNodeStat,
                            const f32 (*opaNnViewMtx)[4][4],
                            f32 (*psMtxWork)[4][4],
                            u32 u32ViewNo,
                            u32 NodeFlg)
{
}

clsExtraLamp_Task::clsExtraLamp_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsExtraLamp_Task::reset()
{
}

void clsExtraLamp_Task::execute()
{
}

void clsExtraLamp_Task::draw()
{
}

void clsExtraLampDraw_Task::draw()
{
}

void clsExtraLamp_Task::start()
{
}

void clsExtraLamp_Task::setLampColor(u32 u32ParamNo)
{
}

void clsExtraLamp_Task::stop()
{
}
