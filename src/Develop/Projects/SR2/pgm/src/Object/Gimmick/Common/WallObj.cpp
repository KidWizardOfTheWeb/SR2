#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/WallObj.hpp"

void clsWallObjThrCol::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsWallObjThrCol::contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsWallObj_Obj::main()
{
}

void clsWallObj_Obj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

void clsWallObj_Obj::contactInterraction(clsRigidBodyGimmickObj* pParam1)
{
}

void clsWallObj_Obj::createData()
{
}

void clsWallObj_Obj::destroyData()
{
}

clsWallObj_Task::clsWallObj_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsWallObj_Task, clsWallObj_Obj, clsModelType_OB_TX>(0, u32ObjectAreaNum)
{
}

void clsWallObj_Task::createModel(stcBinInfo& rParam1)
{
}

void clsWallObj_Task::execute()
{
}

void clsWallObj_Task::draw()
{
}
