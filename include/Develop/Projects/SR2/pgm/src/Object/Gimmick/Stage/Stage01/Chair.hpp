#ifndef CHAIR_HPP
#define CHAIR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NnDraw3d.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// Note: enmBulletinBoardMode name collision with ChairB.hpp
enum enmBulletinBoardMode_ChairA {
    INIT = 0,
    MAIN = 1,
};

class clsChairA_Obj : public clsRigidBodyGimmickObj {
public:
    clsChairA_Obj();
    virtual ~clsChairA_Obj();

    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();

    void draw(clsModelType_OB_TX& rModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4]);

    nspPackId::enm getPackId() const { return nspPackId::ST01_CHAIR_A_11190; }

    // Members
    enmBulletinBoardMode_ChairA m_enBulletinBoardMode; // offset 0xD0, size 0x4
};

// total size: 0x98
class clsChairA_Task
    : public clsSingleModelGimmick_Task<clsChairA_Task, clsChairA_Obj, clsModelType_OB_TX> {
public:
    clsChairA_Task(u32 u32ObjectAreaNum);
    virtual ~clsChairA_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // CHAIR_HPP
