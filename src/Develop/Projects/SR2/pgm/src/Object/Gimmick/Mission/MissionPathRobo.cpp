#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionPathRobo.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

static stcParam asRoboLineParam[2];
static stcGimickSubParam asRoboLineAddParam[2];
static u8 chk__asRoboLineAddParam_SizeCheck_[1];
static u8 chk__asRoboLineParam_SizeCheck_[1];
static NNS_VECTORFAST tosOffsetVecFast = {0.0f, -3.0f, 1.0f, 1.0f};

void clsMissionPathRoboCollision::setPosRot(const NNS_VECTORFAST* psPosVec,
                                            const NNS_QUATERNION* psQuat)
{
}

void clsMissionPathRoboCollision::contactTriggerEvent(clsPlayerTask* pParam1)
{
}

clsMissionPathRobo_Obj::clsMissionPathRobo_Obj()
{
}

void clsMissionPathRobo_Obj::init()
{
}

void clsMissionPathRobo_Obj::reset()
{
}

void clsMissionPathRobo_Obj::createData()
{
}

void clsMissionPathRobo_Obj::destroyData()
{
}

void clsMissionPathRobo_Obj::draw(clsModelType_OB_TX& rcObj,
                                  f32 (*psMtxPal)[4][4],
                                  u32* psNodeStat,
                                  const f32 (*opaNnViewMtx)[4][4],
                                  f32 (*psMtxWork)[4][4],
                                  u32 u32ViewNo)
{
}

void clsMissionPathRobo_Obj::main()
{
}

clsMissionPathRobo_Task::clsMissionPathRobo_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMissionPathRobo_Task,
                                 clsMissionPathRobo_Obj,
                                 clsModelType_OB_TX>(0, 0)
{
}

s32 clsMissionPathRobo_Task::getPathPoint()
{
    return 0;
}

NNS_VECTORFAST* clsMissionPathRobo_Task::getPosVecFastPtr()
{
    return 0;
}

void clsMissionPathRobo_Task::reset()
{
}

void clsMissionPathRobo_Task::execute()
{
}

void clsMissionPathRobo_Task::draw()
{
}

clsMissionPathRobo_Task::~clsMissionPathRobo_Task()
{
}

void clsMissionPathRobo_Task::setMode(u32)
{
}

void clsMissionPathRobo_Task::addMode()
{
}

void clsMissionPathRobo_Task::addMode(u32)
{
}

void clsMissionPathRobo_Task::subMode()
{
}

void clsMissionPathRobo_Task::subMode(u32)
{
}

void clsMissionPathRobo_Task::reinitMode()
{
}

void clsMissionPathRobo_Task::createModel(stcBinInfo& rsBinInfo)
{
}

void clsMissionPathRobo_Task::setSetData(const stcSetDataDetail& rsDetail)
{
}
