#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBomb.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

clsModelType_OB_TX_MO_MA clsItemBomb_Task::t_cModel;
clsModelType_OB_TX_MO_MA clsItemBomb_Task::t_cExpModel;
f32 clsItemBomb_Obj::tof32ClipSqDist;

clsItemBomb_Obj::clsItemBomb_Obj(clsItemBomb_Task* pParam1,
                                 const NNS_VECTORFAST* pParam2,
                                 const NNS_QUATERNION* pParam3,
                                 f32 f32Param4,
                                 s16 s16Param5)
{
}

clsItemBomb_Obj::~clsItemBomb_Obj()
{
}

void clsItemBomb_Obj::reset()
{
}

void clsItemBomb_Obj::createData()
{
}

void clsItemBomb_Obj::destroyData()
{
}

void clsItemBomb_Obj::main()
{
}

void clsItemBomb_Obj::updataPath()
{
}

void clsItemBomb_Obj::CalcGravityVelocity(NNS_VECTORFAST* pParam1)
{
}

void clsItemBomb_Obj::CalcNonGravityVelocity(NNS_VECTORFAST* pParam1)
{
}

void clsItemBomb_Obj::searchObj()
{
}

void clsItemBomb_Obj::contactInterraction(clsRigidBodyGimmickObj* pParam1)
{
}

void clsItemBomb_Obj::draw(clsModelType_OB_TX_MO_MA& rParam1,
                           f32 (*)[4][4],
                           u32* pParam3,
                           const f32 (*)[4][4],
                           f32 (*)[4][4],
                           u32 u32Param6)
{
}

clsItemBomb_Task::clsItemBomb_Task(const NNS_VECTORFAST* pParam1,
                                   const NNS_QUATERNION* pParam2,
                                   f32 f32Param3,
                                   s16 s16Param4)
    : clsTask(0, 0)
{
}

void clsItemBomb_Task::reset()
{
}

void clsItemBomb_Task::registModel(stcBinInfo& rParam1)
{
}

void clsItemBomb_Task::execute()
{
}

void clsItemBomb_Task::draw()
{
}
