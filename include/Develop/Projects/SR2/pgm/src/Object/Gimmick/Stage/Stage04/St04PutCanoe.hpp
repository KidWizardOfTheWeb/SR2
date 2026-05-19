#ifndef ST04PUTCANOE_HPP
#define ST04PUTCANOE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

enum enmPutCarMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

class clsPutCanoe_Obj : public clsRigidBodyGimmickObj {
public:
    clsPutCanoe_Obj();
    virtual ~clsPutCanoe_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackCrashEvent();

    nspPackId::enm getPackId() const { return nspPackId::ST04_PUT_CANOE_14060; }

    static f32 tof32ClipSqDist;
    static u32 otau32Se_CanoeBreak[2];
    static u32 otau32Se_CanoeExp[2];

    // Members
    enmPutCarMode m_eMode; // offset 0xD0, size 0x4
    u32 m_u32TexIdx;       // offset 0xD4, size 0x4
};

// total size: 0x9C
class clsPutCanoe_Task
    : public clsSingleModelGimmick_Task<clsPutCanoe_Task, clsPutCanoe_Obj, clsModelType_OB_TX> {
public:
    clsPutCanoe_Task(u32 u32ObjectAreaNum);
    virtual ~clsPutCanoe_Task() {}
    virtual void reset();
    virtual void execute();
    virtual void draw();

    u16* m_TexIdx;  // offset 0x94, size 0x4
    u16* m_TexIdx2; // offset 0x98, size 0x4
};

#endif // ST04PUTCANOE_HPP
