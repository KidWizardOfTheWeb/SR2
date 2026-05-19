#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalBall.hpp"

_strGyroData clsSurvivalBallBall_Obj::gsGyroData[4];
clsGravityGimmickParam* clsSurvivalBallBall_Obj::t_pocGravityGimmickParam[3];
clsGravityGimmickParam clsSurvivalBallBall_Obj::t_ocGravityGimmickParamSt01;
clsGravityGimmickParam clsSurvivalBallBall_Obj::t_ocGravityGimmickParamSt02;
clsGravityGimmickParam clsSurvivalBallBall_Obj::t_ocGravityGimmickParamSt03;

void clsSurvivalBallBall_Task::setSetDataBall(const stcSetDataDetail& rParam1)
{
}

void clsSurvivalBallBallCollision::execute()
{
}

clsSurvivalBallBall_Obj::clsSurvivalBallBall_Obj()
{
}

void clsSurvivalBallBall_Obj::createData()
{
}

void clsSurvivalBallBall_Obj::destroyData()
{
}

void clsSurvivalBallBall_Obj::reset()
{
}

void clsSurvivalBallBall_Obj::searchPointRing()
{
}

void clsSurvivalBallBall_Obj::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsSurvivalBallBall_Obj::requestDrawBreakEffect()
{
}

void clsSurvivalBallBall_Obj::contactInterraction(clsRigidBodyGimmickObj* pParam1)
{
}

void clsSurvivalBallBall_Obj::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsSurvivalBallBall_Obj::execute()
{
}

void clsSurvivalBallBall_Obj::main()
{
}

void clsSurvivalBallBall_Obj::draw(clsSurvivalBallBallModels& rParam1)
{
}

void clsSurvivalBallBall_Obj::drawBall(clsModelType_OB_TX_MO_MA& rParam1, f32 (*)[4][4])
{
}

void clsSurvivalBallBall_Obj::drawGyro(clsModelType_OB_TX_MO_MA& rParam1,
                                       clsModelType_OB_TX_MO_MA& rParam2)
{
}

clsSurvivalBallBall_Task::clsSurvivalBallBall_Task(u32 u32Param1)
    : clsSingleModelGimmick_Task<clsSurvivalBallBall_Task,
                                 clsSurvivalBallBall_Obj,
                                 clsSurvivalBallBallModels>(0, 0)
{
}

void clsSurvivalBallBall_Task::createModel(stcBinInfo& rParam1)
{
}

void clsSurvivalBallBall_Task::reset()
{
}

void clsSurvivalBallBall_Task::searchBallPos(const NNS_VECTORFAST* pParam1,
                                             const NNS_VECTORFAST* pParam2,
                                             NNS_VECTORFAST* pParam3)
{
}

void clsSurvivalBallBall_Task::execute()
{
}

void clsSurvivalBallBall_Task::draw()
{
}
