#ifndef GARBAGEBOX_HPP
#define GARBAGEBOX_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/ChairB.hpp"

// total size: 0xE0
class clsGarbageBox_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmBulletinBoardMode {
        INIT = 0,
        MAIN = 1,
    };

    clsGarbageBox_Obj();
    virtual ~clsGarbageBox_Obj();

    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();

    nspPackId::enm getPackId() const { return nspPackId::ST01_GARBAGE_BOX_11192; }

    void draw(clsModelType_OB_TX& rModels,
              NNS_MATRIX* psMtxPal,
              u32* psNodeStat,
              const NNS_MATRIX* opaNnViewMtx,
              NNS_MATRIX* psMtxWork);

    enmBulletinBoardMode m_enBulletinBoardMode; // offset 0xD0, size 0x4
};

// total size: 0x98
class clsGarbageBox_Task
    : public clsSingleModelGimmick_Task<clsGarbageBox_Task, clsGarbageBox_Obj, clsModelType_OB_TX> {
public:
    clsGarbageBox_Task(u32 u32ObjectAreaNum);
    virtual ~clsGarbageBox_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // GARBAGEBOX_HPP
