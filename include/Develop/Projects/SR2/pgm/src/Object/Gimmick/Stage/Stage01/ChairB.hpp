#ifndef CHAIRB_HPP
#define CHAIRB_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsChairB_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmBulletinBoardMode {
        INIT = 0,
        MAIN = 1,
    };

    clsChairB_Obj();
    virtual ~clsChairB_Obj();

    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();

    void draw(clsModelType_OB_TX& rModels,
              NNS_MATRIX* psMtxPal,
              u32* psNodeStat,
              const NNS_MATRIX* opaNnViewMtx,
              NNS_MATRIX* psMtxWork);

    nspPackId::enm getPackId() const { return nspPackId::ST01_CHAIR_B_11191; }

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
