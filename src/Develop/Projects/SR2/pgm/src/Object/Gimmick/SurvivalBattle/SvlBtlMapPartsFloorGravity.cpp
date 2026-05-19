#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlMapPartsFloorGravity.hpp"

clsGravityGimmickParam clsSvlBtlMapPartsFloorGravity_Object::t_ocGravityGimmickParam = {};

void clsSvlBtlMapPartsFloorGravity_Object::setData()
{
}

void clsSvlBtlMapPartsFloorGravity_Object::createData()
{
}

void clsSvlBtlMapPartsFloorGravity_Object::contactTriggerEvent(hkContactPoint* pcContact,
                                                               clsObject* pcObject)
{
}

clsSvlBtlMapPartsFloorGravity_Task::clsSvlBtlMapPartsFloorGravity_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSvlBtlMapPartsFloorGravity_Task,
                                 clsSvlBtlMapPartsFloorGravity_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18702)
{
}

void clsSvlBtlMapPartsFloorGravity_Task::reset()
{
}

void clsSvlBtlMapPartsFloorGravity_Task::execute()
{
}

void clsSvlBtlMapPartsFloorGravity_Task::draw()
{
}
