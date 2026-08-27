#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GCtrTrain/GCtrTrain.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static clsBackLineEffectTask::stcParam asTrainLineParam[2] = {
    {2,
     0,
     0xFF,
     0xFF,
     1,
     6,
     0xD0A000FF,
     0.0f,
     1.0f,
     {-1.0f, 3.0f, -4.6f, 0.0f},
     {2.2f, 3.0f, 11.0f, 0.0f}},
    {2,
     0,
     0xFF,
     0xFF,
     1,
     6,
     0xD0A000FF,
     0.0f,
     1.0f,
     {1.0f, 3.0f, -4.6f, 0.0f},
     {-2.2f, 3.0f, 11.0f, 0.0f}},
};
static stcGimickSubParam asTrainLineFrontSubParam[2] = {
    {{3.0f, 0.0f, 0.0f, 1.0f}, {-0.8f, 0.0f, -2.0f, 1.0f}},
    {{-3.0f, 0.0f, 0.0f, 1.0f}, {0.8f, 0.0f, -2.0f, 1.0f}},
};
static stcGimickSubParam asTrainLineBackSubParam[2];
static u8 chk__asTrainLineParam_SizeCheck_[1];
static u8 chk__asTrainLineFrontSubParam_SizeCheck_[1];
static u8 chk__asTrainLineBackSubParam_SizeCheck_[1];
} // namespace

f32 clsGCtrlTrain_Obj::m_tof32CLIP_DISTx2 = 0.0f;

clsGCtrlTrain_Obj::clsGCtrlTrain_Obj()
{
}

void clsGCtrlTrain_Obj::init()
{
}

void clsGCtrlTrain_Obj::reset()
{
}

void clsGCtrlTrain_Obj::setData()
{
}

void clsGCtrlTrain_Obj::createData()
{
}

void clsGCtrlTrain_Obj::destroyData()
{
}

void clsGCtrlTrain_Obj::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsGCtrlTrain_Obj::controlPlayer()
{
}

void clsGCtrlTrain_Obj::start()
{
}

void clsGCtrlTrain_Obj::main()
{
}

u8 clsGCtrlTrain_Obj::draw(NNS_OBJECT* pParam1,
                           f32 (*)[4][4],
                           u32* pParam3,
                           const f32 (*)[4][4],
                           f32 (*)[4][4],
                           u32 u32Param6)
{
    return 0;
}
