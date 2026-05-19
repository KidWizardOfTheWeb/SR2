#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/AdjustGravityAction.hpp"

void clsAdjustGravityAction_Object::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsAdjustGravityAction_Object::contactRemoveEvent(clsPlayerTask* pcPlayer)
{
}

void clsAdjustGravityAction_Object::createData()
{
}

void clsAdjustGravityAction_Object::destroyData()
{
}

void clsAdjustGravityAction_Object::updateSetEditorCollision()
{
}

clsAdjustGravityAction_Task::clsAdjustGravityAction_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickThrough<clsAdjustGravityAction_Task, clsAdjustGravityAction_Object>(
          0, u32ObjectAreaNum)
{
}

void clsAdjustGravityAction_Task::execute()
{
}

void clsAdjustGravityAction_Task::draw()
{
}
