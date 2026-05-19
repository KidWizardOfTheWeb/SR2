#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PlayLoopSe.hpp"

u32 clsPlayLoopSe_Obj::m_oau32RequestArray[8] = {
    0x114A9, 0x115A9, 0x215A9, 0x616A9, 0x19A9, 0x711A9, 0xA01A9, 0xEA9};

void clsPlayLoopSe_Obj::createData()
{
}

void clsPlayLoopSe_Obj::destroyData()
{
}

void clsPlayLoopSe_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsPlayLoopSe_Obj::contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

clsPlayLoopSe_Task::clsPlayLoopSe_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsPlayLoopSe_Task, clsPlayLoopSe_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsPlayLoopSe_Task::reset()
{
}

void clsPlayLoopSe_Task::execute()
{
}

void clsPlayLoopSe_Task::draw()
{
}

clsPlayLoopSe_Obj::~clsPlayLoopSe_Obj()
{
}

clsPlayLoopSe_Obj::clsPlayLoopSe_Obj()
{
}

nspPackId::enm clsPlayLoopSe_Obj::getPackId() const
{
    return nspPackId::PLAY_LOOP_SE_2200;
}
