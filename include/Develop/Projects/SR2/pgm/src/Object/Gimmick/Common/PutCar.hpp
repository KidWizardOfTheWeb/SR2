#ifndef PUTCAR_HPP
#define PUTCAR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsSe3DControl;

enum enmPutCarMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0xE0
class clsPutCar_Obj : public clsRigidBodyGimmickObj {
public:
    inline clsPutCar_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsPutCar_Obj() {}

    enmPutCarMode m_eMode;           // offset 0xD0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xD4, size 0x4
    u8 m_u8ContactSeCount;           // offset 0xD8, size 0x1

    static u32 otau32Se_CarCrash[3];
    static f32 tof32ClipSqDist;
    static u32 t_ou32DrawNode[2];

    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    inline u32 getMultiDrawNum() const { return 4; }
    inline nspPackId::enm getPackId() const { return nspPackId::ST01_PUT_CAR_11010; }
};

// total size: 0x9C
class clsPutCar_Task
    : public clsMultiModelGimmick_Task<clsPutCar_Task, clsPutCar_Obj, clsMultiObTxModels> {
public:
    clsPutCar_Task(u32 u32ObjectAreaNum);
    virtual ~clsPutCar_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTCAR_HPP
