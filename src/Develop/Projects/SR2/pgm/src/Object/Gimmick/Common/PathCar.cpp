#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PathCar.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

static stcParam asPathCurLineParam[2];
static stcGimickSubParam asPathCurLineSubParam[2];
static u8 chk__asPathCurLineParam_SizeCheck_[1];
static u8 chk__asPathCurLineSubParam_SizeCheck_[1];

f32 clsPathCar_Obj::t_of32CLIP_DISTx2;
u32 clsPathCar_Obj::otau32SeTbl[3][3] = {
    {6574, 137646, 72110},
    {199342, 264878, 461486},
    {660142, 332462, 397998},
};

clsPathCar_Obj::clsPathCar_Obj()
{
}

clsPathCar_Obj::~clsPathCar_Obj()
{
}

void clsPathCar_Obj::init()
{
}

void clsPathCar_Obj::reset()
{
}

void clsPathCar_Obj::setData()
{
}

void clsPathCar_Obj::createData()
{
}

void clsPathCar_Obj::destroyData()
{
}

void clsPathCar_Obj::requestDrawBreakEffect()
{
}

void clsPathCar_Obj::adminSe()
{
}

void clsPathCar_Obj::callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rEvent)
{
}

void clsPathCar_Obj::callbackGravityEvent()
{
}

u8 clsPathCar_Obj::draw(clsModelType_OB_TX* pcModels,
                        f32 (*psMtxPal)[4][4],
                        u32* psNodeStat,
                        const f32 (*opaNnViewMtx)[4][4],
                        f32 (*psMtxWork)[4][4])
{
    return 0;
}

clsPathCar_Task::clsPathCar_Task(u32 u32ObjectAreaNum)
    : clsMultiModelGimmick_Task<clsPathCar_Task, clsPathCar_Obj, clsMultiObTxModels>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsPathCar_Task::reset()
{
}

void clsPathCar_Task::execute()
{
}

void clsPathCar_Task::draw()
{
}
