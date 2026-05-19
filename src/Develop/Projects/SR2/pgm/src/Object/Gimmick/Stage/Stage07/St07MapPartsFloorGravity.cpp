#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorGravity.hpp"

NNS_VECTOR clsMapPartsFloorGravity_Task::tosCollisionHalfSizeVec = {5.0f, 1.5f, 5.0f};
f32 clsMapPartsFloorGravity_Object::tof32ClipSqDist = 0.0f;

void clsMapPartsFloorGravity_Object::reset()
{
}

void clsMapPartsFloorGravity_Object::main()
{
}

u8 clsMapPartsFloorGravity_Object::draw(clsModelType_OB_TX& rcObj,
                                        f32 (*psMtxPal)[4][4],
                                        u32* psNodeStat,
                                        const f32 (*opaNnViewMtx)[4][4],
                                        f32 (*psMtxWork)[4][4])
{
    return 0;
}

void clsMapPartsFloorGravity_Object::callbackGravityEvent()
{
}

void clsMapPartsFloorGravity_Object::setData()
{
}

void clsMapPartsFloorGravity_Object::createData()
{
}

void clsMapPartsFloorGravity_Object::countEffect()
{
}

void clsMapPartsFloorGravity_Object::requestDrawBreakEffect()
{
}

void clsMapPartsFloorGravity_Object::destroyData()
{
}

void clsMapPartsFloorGravity_Object::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

clsMapPartsFloorGravity_Task::clsMapPartsFloorGravity_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMapPartsFloorGravity_Task,
                                 clsMapPartsFloorGravity_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18702)
{
}

void clsMapPartsFloorGravity_Task::reset()
{
}

void clsMapPartsFloorGravity_Task::execute()
{
}

void clsMapPartsFloorGravity_Task::draw()
{
}
