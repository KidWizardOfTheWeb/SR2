#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06Elevator.hpp"

namespace {
u8 toau8StageToPathNo[2] = {8, 9};
}

f32 clsElevator::tof32ClipSqDist = 0.0f;

clsElevator::clsElevator()
{
}

clsElevator::~clsElevator()
{
}

void clsElevator_Obj::setData()
{
}

void clsElevator_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsElevator_Obj::createData()
{
}

void clsElevator_Obj::destroyData()
{
}

clsElevator_Task::clsElevator_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18A88)
{
}

void clsElevator_Task::reset()
{
}

void clsElevator_Task::execute()
{
}

void clsElevator_Task::draw()
{
}

clsElevator_Obj::~clsElevator_Obj()
{
}

clsElevator_Obj::clsElevator_Obj()
{
}

void clsElevator_Obj::setMode(clsElevator_Obj::enmElevatorMode mode)
{
    m_eElevatorMode = mode;
}

clsElevator_Obj::enmElevatorMode clsElevator_Obj::getMode() const
{
    return m_eElevatorMode;
}

void clsElevator_Obj::eraseExexuteElevator(clsElevator* pElevator)
{
}

nspPackId::enm clsElevator_Obj::getPackId() const
{
    return nspPackId::ST06_ELEVATOR_16040;
}

void clsElevator_Obj::controlPlayer()
{
}

void clsElevator::movePlayer()
{
}

void clsElevator::draw(clsModelType_OB_TX& rModel,
                       f32 (*psDrawMtx)[4][4],
                       u32* pu32DrawFlag,
                       const f32 (*psGearMtx)[4][4],
                       f32 (*psDrawMtx2)[4][4],
                       u32 u32DrawFlag)
{
}
