#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PlayAroundSe.hpp"

stcRequestArray clsPlayAroundSe_Obj::m_oasu32RequestArray[2] = {
    {396718, 2.52234e-43f},
    {0, 0.0f},
};

void clsPlayAroundSe_Obj::createData()
{
}

void clsPlayAroundSe_Obj::destroyData()
{
}

void clsPlayAroundSe_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsPlayAroundSe_Obj::contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsPlayAroundSe_Obj::execute()
{
}

clsPlayAroundSe_Task::clsPlayAroundSe_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(0, u32ObjectAreaNum)
{
}

void clsPlayAroundSe_Task::reset()
{
}

void clsPlayAroundSe_Task::execute()
{
}

void clsPlayAroundSe_Task::draw()
{
}

clsPlayAroundSe_Obj::clsPlayAroundSe_Obj()
{
}

clsPlayAroundSe_Obj::~clsPlayAroundSe_Obj()
{
}

nspPackId::enm clsPlayAroundSe_Obj::getPackId() const
{
    return nspPackId::PLAY_AROUND_SE_2180;
}
