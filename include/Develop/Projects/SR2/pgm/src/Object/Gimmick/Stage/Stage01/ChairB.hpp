#ifndef CHAIRB_HPP
#define CHAIRB_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

enum enmBulletinBoardMode {
    INIT = 0,
    MAIN = 1,
};

class clsChairB_Obj : public clsRigidBodyGimmickObj {
public:
    clsChairB_Obj();
    virtual ~clsChairB_Obj();

    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();

    void draw(clsModelType_OB_TX& rModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4]);

    nspPackId::enm getPackId() const { return nspPackId::ST01_CHAIR_B_11191; }

    // Members
    enmBulletinBoardMode m_enBulletinBoardMode; // offset 0xD0, size 0x4
};

// total size: 0x98
class clsChairB_Task
    : public clsSingleModelGimmick_Task<clsChairB_Task, clsChairB_Obj, clsModelType_OB_TX> {
public:
    clsChairB_Task(u32 u32ObjectAreaNum);
    virtual ~clsChairB_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // CHAIRB_HPP
