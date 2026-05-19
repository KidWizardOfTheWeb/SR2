#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlPaul.hpp"

f32 clsSvlBtlPaul_Object::t_of32Mass;
f32 clsSvlBtlPaul_Object::t_of32CLIP_DISTx2;
clsGravityGimmickParam clsSvlBtlPaul_Object::t_ocGravityGimmickParam;

hkShape* clsSvlBtlPaul_Object::getShape()
{
    return 0;
}

f32 clsSvlBtlPaul_Object::getMass()
{
    return 0.0f;
}

clsGravityGimmickParam* clsSvlBtlPaul_Object::getGravityGimmickParam()
{
    return &t_ocGravityGimmickParam;
}

clsSvlBtlPaul_Task::clsSvlBtlPaul_Task(u32 u32NumI) : clsSingleModelGimmick_Task(u32NumI, 0x18A88)
{
}

void clsSvlBtlPaul_Task::reset()
{
}

void clsSvlBtlPaul_Task::execute()
{
}

void clsSvlBtlPaul_Task::draw()
{
}

clsSvlBtlPaul_Object::clsSvlBtlPaul_Object()
{
}

clsSvlBtlPaul_Object::~clsSvlBtlPaul_Object()
{
}
