#ifndef ST12MOTIONOBJ_HPP
#define ST12MOTIONOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSt12MotionObj_Obj;

// total size: 0xC
class clsSt12MotionObjThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsSt12MotionObjThroughCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pParam1);

    clsSt12MotionObj_Obj* m_pcBridge; // offset 0x8, size 0x4
};

// total size: 0x70
class clsSt12MotionObj_Obj : public clsGimmickObj {
public:
    inline clsSt12MotionObj_Obj() : clsGimmickObj() {}
    virtual ~clsSt12MotionObj_Obj() {}

    enum enmBridgeMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmBridgeState {
        STATE_WAIT = 0,
        STATE_MOVE = 1,
        STATE_MOVE_END = 2,
    };

    enmBridgeMode m_eMode;                           // offset 0x50, size 0x4
    enmBridgeState m_eState;                         // offset 0x54, size 0x4
    clsSt12MotionObjThroughCollision* m_pcCollision; // offset 0x58, size 0x4
    hkShape* m_pcShape;                              // offset 0x5C, size 0x4
    f32 m_f32MotionFrame;                            // offset 0x60, size 0x4
    u8 m_bSePlayFlg;                                 // offset 0x64, size 0x1

    static f32 tof32ClipSqDist;

    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST12_MOTIONOBJ_22040; }
};

// total size: 0xAC
class clsSt12MotionObj_Task : public clsSingleModelGimmick_Task<clsSt12MotionObj_Task,
                                                                clsSt12MotionObj_Obj,
                                                                clsModelType_OB_TX_MO_MA> {
public:
    clsSt12MotionObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsSt12MotionObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST12MOTIONOBJ_HPP
