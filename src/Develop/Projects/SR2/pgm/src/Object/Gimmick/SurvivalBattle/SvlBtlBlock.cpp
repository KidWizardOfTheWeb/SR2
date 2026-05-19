#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlBlock.hpp"

f32 clsSvlBtlBlock_Object::t_of32Mass = 0.0f;
f32 clsSvlBtlBlock_Object::t_of32CLIP_DISTx2 = 0.0f;
clsGravityGimmickParam clsSvlBtlBlock_Object::t_ocGravityGimmickParam;

hkShape* clsSvlBtlBlock_Object::getShape()
{
    return 0;
}

f32 clsSvlBtlBlock_Object::getMass()
{
    return 0.0f;
}

clsGravityGimmickParam* clsSvlBtlBlock_Object::getGravityGimmickParam()
{
    return &t_ocGravityGimmickParam;
}

void clsSvlBtlBlock_Object::requestDrawBreakEffect()
{
}

clsSvlBtlBlock_Task::clsSvlBtlBlock_Task(u32 u32NumI)
    : clsSingleModelGimmick_Task<clsSvlBtlBlock_Task, clsSvlBtlBlock_Object, clsModelType_OB_TX>(
          u32NumI, 0x18A88)
{
}

void clsSvlBtlBlock_Task::reset()
{
}

void clsSvlBtlBlock_Task::execute()
{
}

void clsSvlBtlBlock_Task::draw()
{
}
