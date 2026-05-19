#ifndef WALLOBJ_HPP
#define WALLOBJ_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsWallObj_Obj;

// total size: 0xC
class clsWallObjThrCol : public clsBaseThroughCollision {
public:
    virtual ~clsWallObjThrCol() {}

    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2);

    clsWallObj_Obj* m_pcWallObj; // offset 0x8, size 0x4
};

// total size: 0xF0
class clsWallObj_Obj : public clsRigidBodyGimmickObj {
public:
    clsWallObj_Obj() {}
    virtual ~clsWallObj_Obj() {}

    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::WALL_OBJ_2120; }
    virtual void main();
    virtual void contactInterraction(clsRigidBodyGimmickObj* pParam1);

    clsWallObjThrCol m_cThrCol;   // offset 0xD0, size 0xC
    hkShape* m_pcShape;           // offset 0xDC, size 0x4
    NNS_VECTORFAST m_sDirVecFast; // offset 0xE0, size 0x10
};

// total size: 0x94
class clsWallObj_Task
    : public clsBaseGimmickBody<clsWallObj_Task, clsWallObj_Obj, clsModelType_OB_TX> {
public:
    clsWallObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsWallObj_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void createModel(stcBinInfo& rParam1);
};

#endif // WALLOBJ_HPP
