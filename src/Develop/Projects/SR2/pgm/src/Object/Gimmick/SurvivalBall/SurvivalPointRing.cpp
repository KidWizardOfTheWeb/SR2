#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalPointRing.hpp"

namespace {
static NNS_VECTOR cosPhantomVector[3] = {
    {8.8f, 8.8f, 0.4f},
    {5.6f, 5.6f, 0.4f},
    {3.2f, 3.2f, 0.4f},
};

static NNS_VECTOR cosRegistRigidUpDownVector[3] = {
    {7.2f, 2.4f, 2.56f},
    {4.8f, 1.6f, 1.2f},
    {3.2f, 0.8f, 0.8f},
};

static NNS_VECTOR cosRegistRigidLeftRightVector[3] = {
    {2.4f, 8.8f, 2.56f},
    {1.6f, 5.6f, 1.2f},
    {0.8f, 3.2f, 0.8f},
};

static NNS_VECTOR cosRegistRigidUpDownPos[3] = {
    {0.0f, 12.8f, 0.0f},
    {0.0f, 8.8f, 0.0f},
    {0.0f, 4.8f, 0.0f},
};

static NNS_VECTOR cosRegistRigidLeftRightPos[3] = {
    {13.6f, 0.0f, 0.0f},
    {8.8f, 0.0f, 0.0f},
    {5.6f, 0.0f, 0.0f},
};

static s32 scos32SurvivalPointRing[3] = {10, 30, 50};
} // namespace

void clsSurvivalBallPointRing_Collision::execute()
{
}

clsSurvivalBallPointRing_Obj::clsSurvivalBallPointRing_Obj()
{
}

void clsSurvivalBallPointRing_Obj::createData()
{
}

void clsSurvivalBallPointRing_Obj::destroyData()
{
}

void clsSurvivalBallPointRing_Obj::init()
{
}

void clsSurvivalBallPointRing_Obj::reset()
{
}

void clsSurvivalBallPointRing_Obj::contactInterractionPhantomShape(clsRigidBodyGimmickObj* pcObject)
{
}

void clsSurvivalBallPointRing_Obj::contactInterraction(clsRigidBodyGimmickObj* pParam1)
{
}

void clsSurvivalBallPointRing_Obj::main()
{
}

void clsSurvivalBallPointRing_Obj::draw(clsModelType_OB_TX_MO_MA* pcModel,
                                        f32 (*psMtxPal)[4][4],
                                        u32* psNodeStat,
                                        const f32 (*opaNnViewMtx)[4][4],
                                        f32 (*psMtxWork)[4][4],
                                        u32 u32ViewNo)
{
}

clsSurvivalBallPointRing_Task::clsSurvivalBallPointRing_Task(u32 u32Param1)
    : clsSingleModelGimmick_Task<clsSurvivalBallPointRing_Task,
                                 clsSurvivalBallPointRing_Obj,
                                 clsModelType_OB_TX_MO_MA>(0, 0)
{
}

void clsSurvivalBallPointRing_Task::reset()
{
}

void clsSurvivalBallPointRing_Task::execute()
{
}

void clsSurvivalBallPointRing_Task::draw()
{
}

nspPackId::enm clsSurvivalBallPointRing_Obj::getPackId() const
{
    return nspPackId::SURVIVALBALL_GOALRING_28000;
}
