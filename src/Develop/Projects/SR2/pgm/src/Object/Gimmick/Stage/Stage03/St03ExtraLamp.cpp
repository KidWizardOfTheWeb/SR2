#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03ExtraLamp.hpp"

_stcColorParam clsExtraLamp_Task::m_tosColorParam[5];

void clsExtraLamp_Obj::createData()
{
}

void clsExtraLamp_Obj::destroyData()
{
}

void clsExtraLamp_Obj::draw(clsModelType_OB_TX& rcModel,
                            NNS_MATRIX* psMtxPal,
                            u32* psNodeStat,
                            const NNS_MATRIX* opaNnViewMtx,
                            NNS_MATRIX* psMtxWork,
                            u32 u32ViewNo,
                            u32 NodeFlg)
{
}

clsExtraLamp_Task::clsExtraLamp_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 101000)
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
