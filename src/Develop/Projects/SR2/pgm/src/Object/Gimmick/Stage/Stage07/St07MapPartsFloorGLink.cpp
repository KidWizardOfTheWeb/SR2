#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorGLink.hpp"

NNS_VECTOR clsMapPartsFloorGLink_Object::tosCollisionHalfSizeVec = {5.0f, 5.0f, 11.5f};
f32 clsMapPartsFloorGLink_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsMapPartsFloorGLink_Object::t_ocGravityGimmickParam;

void clsMapPartsFloorGLink_Object::draw(NNS_OBJECT* psObject,
                                        f32 (*psMtxPal)[4][4],
                                        u32* psNodeStat,
                                        const f32 (*opaNnViewMtx)[4][4],
                                        f32 (*psMtxWork)[4][4],
                                        u32 u32ViewNo)
{
}

void clsMapPartsFloorGLink_Object::reset()
{
}

void clsMapPartsFloorGLink_Object::main()
{
}

void clsMapPartsFloorGLink_Object::requestDrawBreakEffect()
{
}

void clsMapPartsFloorGLink_Object::callbackGravityEvent()
{
}

void clsMapPartsFloorGLink_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsMapPartsFloorGLink_Object::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsMapPartsFloorGLink_Object::setData()
{
}

void clsMapPartsFloorGLink_Object::createData()
{
}

void clsMapPartsFloorGLink_Object::destroyData()
{
}

clsMapPartsFloorGLink_Task::clsMapPartsFloorGLink_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMapPartsFloorGLink_Task,
                                 clsMapPartsFloorGLink_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18702)
{
}

void clsMapPartsFloorGLink_Task::reset()
{
}

void clsMapPartsFloorGLink_Task::execute()
{
}

void clsMapPartsFloorGLink_Task::draw()
{
}
