#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/PathTrain/PathTrain.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static NNS_VECTOR tosLightOffsetVec = {0.0f, 0.0f, 12.0f};
static clsBackLineEffectTask::stcParam asTrainLineParam[2] = {
    {1,
     0,
     0xFF,
     0xFF,
     1,
     6,
     0xD0A000FF,
     0.0f,
     1.0f,
     {-1.0f, 3.0f, -4.6f, 0.0f},
     {2.8f, 3.0f, 11.0f, 0.0f}},
    {1,
     0,
     0xFF,
     0xFF,
     1,
     6,
     0xD0A000FF,
     0.0f,
     1.0f,
     {1.0f, 3.0f, -4.6f, 0.0f},
     {-2.8f, 3.0f, 11.0f, 0.0f}},
};
static stcGimickSubParam asTrainLineFrontSubParam[2] = {
    {{2.0f, 0.0f, 0.0f, 1.0f}, {-0.8f, 0.0f, -1.0f, 1.0f}},
    {{-2.0f, 0.0f, 0.0f, 1.0f}, {0.8f, 0.0f, -1.0f, 1.0f}},
};
static stcGimickSubParam asTrainLineBackSubParam[2];
static u8 chk__asTrainLineParam_SizeCheck_[1];
static u8 chk__asTrainLineFrontSubParam_SizeCheck_[1];
static u8 chk__asTrainLineBackSubParam_SizeCheck_[1];
} // namespace

clsPathTrain_Obj::clsPathTrain_Obj()
{
}

clsPathTrain_Obj::~clsPathTrain_Obj()
{
}

void clsPathTrain_Obj::setData()
{
}

void clsPathTrain_Obj::createData()
{
}

void clsPathTrain_Obj::destroyData()
{
}

void clsPathTrain_Obj::init()
{
}

void clsPathTrain_Obj::reset()
{
}

void clsPathTrain_Obj::setTrainQuat(NNS_QUATERNION* pParam1,
                                    clsGimmickObj* pParam2,
                                    clsGimmickObj* pParam3)
{
}

void clsPathTrain_Obj::start()
{
}

void clsPathTrain_Obj::main()
{
}

void clsPathTrain_Obj::draw(clsModelType_OB_TX* pParam1,
                            clsModelType_OB_TX_MO_MA* pParam2,
                            f32 (*)[4][4],
                            u32* pParam4,
                            const f32 (*)[4][4],
                            f32 (*)[4][4],
                            u32 u32Param7)
{
}
