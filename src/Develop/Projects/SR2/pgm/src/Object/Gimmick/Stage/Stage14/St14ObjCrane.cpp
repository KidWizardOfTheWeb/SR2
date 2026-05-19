#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14ObjCrane.hpp"

f32 clsObjCrane_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsObjCrane_Object::t_ocGravityGimmickParam;

namespace {
static NNS_VECTORFAST toasPointVecFast[6][2] = {
    {{337.0f, 277.0f, -105.0f, 1.0f}, {337.0f, 277.0f, -164.0f, 1.0f}},
    {{341.0f, 278.0f, -194.0f, 1.0f}, {341.0f, 278.0f, -101.0f, 1.0f}},
    {{-229.0f, 349.0f, -14.0f, 1.0f}, {-229.0f, 435.0f, -14.0f, 1.0f}},
    {{-228.0f, 435.0f, -24.0f, 1.0f}, {-228.0f, 349.0f, -24.0f, 1.0f}},
    {{108.0f, 19.0f, 14.0f, 1.0f}, {204.0f, 19.0f, 14.0f, 1.0f}},
    {{204.0f, 19.0f, 10.0f, 1.0f}, {108.0f, 19.0f, 10.0f, 1.0f}},
};
}

void clsObjCrane_Object::draw(NNS_OBJECT* psObject,
                              f32 (*psMtxPal)[4][4],
                              u32* psNodeStat,
                              const f32 (*opaNnViewMtx)[4][4],
                              f32 (*psMtxWork)[4][4],
                              u32 u32ViewNo)
{
}

void clsObjCrane_Object::reset()
{
}

void clsObjCrane_Object::main()
{
}

void clsObjCrane_Object::requestDrawBreakEffect()
{
}

void clsObjCrane_Object::setData()
{
}

void clsObjCrane_Object::createData()
{
}

void clsObjCrane_Object::destroyData()
{
}

hkShape* clsObjCrane_Object::getShape()
{
    return 0;
}

clsObjCrane_Task::clsObjCrane_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsObjCrane_Task::reset()
{
}

void clsObjCrane_Task::execute()
{
}

void clsObjCrane_Task::draw()
{
}
