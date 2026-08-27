#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GLinkTrain/GLinkTrainObject.hpp"
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
    {{2.0f, 0.0f, 0.0f, 1.0f}, {-0.8f, 0.0f, -1.0f, 1.0f}},
    {{-2.0f, 0.0f, 0.0f, 1.0f}, {0.8f, 0.0f, -1.0f, 1.0f}},
};
static stcGimickSubParam asTrainLineBackSubParam[2];
static u8 chk__asTrainLineParam_SizeCheck_[1];
static u8 chk__asTrainLineFrontSubParam_SizeCheck_[1];
static u8 chk__asTrainLineBackSubParam_SizeCheck_[1];
} // namespace

clsGravityGimmickParam clsGLinkTrain_Object::t_ocGravityGimmickParam;
clsGravityGimmickParam clsGLinkTrain_Object::t_ocGravityGimmickParam2;
u32 clsGLinkTrain_Object::otau32Se_TrainHorn[2] = {2734, 135854};
u32 clsGLinkTrain_Object::otau32Se_TrainL[2] = {68270, 201390};
u32 clsGLinkTrain_Object::otau32Se_TrainCrash[2] = {133806, 266926};
NNS_VECTOR clsGLinkTrain_Object::tosCollisionHalfSizeVec = {4.5f, 3.3f, 12.0f};
f32 clsGLinkTrain_Object::tof32ClipSqDist = 0.0f;

clsGLinkTrain_Object::clsGLinkTrain_Object()
{
}

void clsGLinkTrain_Object::draw(NNS_OBJECT* pParam1,
                                f32 (*)[4][4],
                                u32* pParam3,
                                const f32 (*)[4][4],
                                f32 (*)[4][4],
                                u32 u32Param6)
{
}

void clsGLinkTrain_Object::reset()
{
}

void clsGLinkTrain_Object::main()
{
}

void clsGLinkTrain_Object::requestDrawBreakEffect()
{
}

void clsGLinkTrain_Object::startGravityAction(clsPlayerTask* pParam1, enmFlag)
{
}

void clsGLinkTrain_Object::drawEffect(clsPlayerTask* pParam1)
{
}

void clsGLinkTrain_Object::setData()
{
}

void clsGLinkTrain_Object::createData()
{
}

void clsGLinkTrain_Object::destroyData()
{
}

void clsGLinkTrain_Object::callbackGravityEvent()
{
}
