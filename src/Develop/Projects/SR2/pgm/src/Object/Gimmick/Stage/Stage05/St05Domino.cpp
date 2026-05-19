#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05Domino.hpp"

f32 clsDomino_Obj::m_tof32ClipSqDist;
u8 clsDomino_Obj::t_u8DownCount;

NNS_VECTOR clsDomino_Task::m_tosThroughColPosVec[4] = {
    {-18.0f, -743.5f, 42.800003f},
};

void clsDominoThroughCol::contactAlwaysEvent(clsPlayerTask* pcPlayer)
{
}

void clsDomino_Obj::reset()
{
}

void clsDomino_Obj::setData()
{
}

void clsDomino_Obj::createData()
{
}

void clsDomino_Obj::destroyData()
{
}

void clsDomino_Obj::requestDrawBreakEffect()
{
}

void clsDomino_Obj::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsDomino_Obj::start(const NNS_VECTORFAST& rsLocalFoceVecFast)
{
}

void clsDomino_Obj::contactInterraction(clsRigidBodyGimmickObj* pcObject)
{
}

void clsDomino_Obj::main()
{
}

void clsDomino_Obj::mainCrash()
{
}

clsDomino_Task::clsDomino_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsDomino_Task, clsDomino_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0)
{
}

void clsDomino_Task::reset()
{
}

void clsDomino_Task::setThroughObj()
{
}

void clsDomino_Task::execute()
{
}

void clsDomino_Task::draw()
{
}
