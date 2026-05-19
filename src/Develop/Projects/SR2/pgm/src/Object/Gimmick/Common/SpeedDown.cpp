#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/SpeedDown.hpp"

namespace nspSpeedDown {
static u8 chk__toasGearOffset_SizeCheck_[1];
static u8 chk__toau32GearNodeNo_SizeCheck_[1];

static NNS_VECTORFAST toasGearOffset[9] = {{0.0f, 0.0f, 0.1f, 1.0f},
                                           {0.0f, -0.2f, -0.35f, 1.0f},
                                           {0.0f, 0.0f, -0.25f, 1.0f},
                                           {0.0f, 0.0f, 0.0f, 1.0f},
                                           {0.0f, 0.1f, 0.0f, 1.0f},
                                           {0.0f, 0.0f, 0.0f, 1.0f},
                                           {0.0f, 0.0f, -0.2f, 1.0f},
                                           {0.0f, 0.0f, 0.0f, 1.0f},
                                           {0.0f, 0.0f, 0.0f, 1.0f}};
static u32 toau32GearNodeNo[9] = {2, 2, 2, 0, 2, 2, 2, 0, 0};
} // namespace nspSpeedDown

void clsSpeedDown_Obj::destroyData()
{
}

void clsSpeedDown_Obj::createChain()
{
}

void clsSpeedDown_Obj::setLimit(clsGimmickRigidBody* pcRigidBodyA,
                                clsGimmickRigidBody* pcRigidBodyB,
                                f32 f32MaxAngle)
{
}

void clsSpeedDown_Obj::execute()
{
}

void clsSpeedDown_Obj::draw(clsMultiObTxModels& rcObj,
                            f32 (*psMtxPal)[4][4],
                            u32* psNodeStat,
                            const f32 (*opaNnViewMtx)[4][4],
                            f32 (*psMtxWork)[4][4],
                            u32 u32ViewNo)
{
}

clsSpeedDown_Task::clsSpeedDown_Task(const stcSetDataDetail& rParam)
    : clsMultiModelGimmick_Task<clsSpeedDown_Task, clsSpeedDown_Obj, clsMultiObTxModels>(0, 0)
{
}

void clsSpeedDown_Task::reset()
{
}

void clsSpeedDown_Task::regist(clsPlayerTask* pcPlayer, f32 f32Param)
{
}

void clsSpeedDown_Task::execute()
{
}

void clsSpeedDown_Task::draw()
{
}

clsSpeedDown_Task::~clsSpeedDown_Task()
{
}

void clsSpeedDown_Task::setSetData(const stcSetDataDetail& rParam)
{
}
