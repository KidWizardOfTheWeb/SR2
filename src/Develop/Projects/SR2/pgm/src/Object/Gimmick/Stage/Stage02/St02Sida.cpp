#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Sida.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/KickerParam.hpp"

static stcKickerParam tosJumpParam = {1.6166667f, 0.018279569f, 0.56666666f};

NNS_VECTORFAST clsSida_Obj::m_tosLeafPosFast = {5.5f, -59.9f, 55.0f, 1.0f};

void clsSida_Obj::createData()
{
}

void clsSida_Obj::destroyData()
{
}

void clsSida_Obj::contactAlwaysEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

clsSida_Task::clsSida_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSida_Task, clsSida_Obj, clsModelType_OB_TX>(u32ObjectAreaNum,
                                                                                0x18A88)
{
}

void clsSida_Task::reset()
{
}

void clsSida_Task::execute()
{
}

void clsSida_Task::draw()
{
}
