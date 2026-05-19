#ifndef ST11FAN_HPP
#define ST11FAN_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsFan_Obj;
class clsFan_Task;
struct _stcShapeInfo;

// total size: 0x14
class clsFanThroughCollision : public clsBaseThroughCollision {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_WAIT = 1,
        MODE_RISE = 2,
        MODE_FLOAT = 3,
        MODE_MOVE_INIT = 4,
        MODE_MOVE = 5,
        MODE_END = 6,
    };

    clsFanThroughCollision() {}
    virtual ~clsFanThroughCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    enmMode m_eMode;           // offset 0x8, size 0x4
    clsFan_Task* m_pcFan_Task; // offset 0xC, size 0x4
    clsFan_Obj* m_pcFan_Obj;   // offset 0x10, size 0x4
};

// total size: 0x14
class clsFanModel {
public:
    clsFanModel() {}
    ~clsFanModel() {}

    clsModelType_OB_TX_MO m_cModel; // offset 0x0, size 0x10
    void* m_pvBin;                  // offset 0x10, size 0x4
};

enum enmState {
    STATE_MAIN = 0,
    STATE_ACTION = 1,
    STATE_WAIT = 2,
    STATE_STOP = 3,
};

// total size: 0xEC
class clsFan_Task : public clsBaseGimmickBody<clsFan_Task, clsFan_Obj, clsFanModel> {
public:
    clsFan_Task(u32 u32ObjectAreaNum);
    virtual ~clsFan_Task() {}

    static NNS_VECTORFAST m_tosPartsOffsetFast[12];
    static NNS_VECTOR m_tosThroughCollisionPosVec[5];
    static f32 m_tof32ThroughCollisionRotY[5];

    hkShape* m_pcThroughShape;               // offset 0xA0, size 0x4
    clsFanThroughCollision m_acCollision[2]; // offset 0xA4, size 0x28
    enmState m_eState;                       // offset 0xCC, size 0x4
    u32 m_u32PlayerFlg;                      // offset 0xD0, size 0x4
    s32 m_s32CollisionNum;                   // offset 0xD4, size 0x4
    _stcShapeInfo* m_apcShape;               // offset 0xD8, size 0x4
    NNS_NODE* m_psNodeList;                  // offset 0xDC, size 0x4
    vector m_vctShapeSearch;                 // offset 0xE0, size 0xC

    virtual void reset();
    virtual void execute();
    virtual void draw();
    virtual void createModel(stcBinInfo& rsBinInfoI);
};

// total size: 0xE0
class clsFan_Parts : public clsRigidBodyGimmickObj {
public:
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    clsFan_Parts() {}
    virtual ~clsFan_Parts() {}

    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawCrashEffect(const hkContactPoint* pParam1);
    virtual void requestDrawBreakEffect();
    virtual void callbackCrashEvent();
    virtual void callbackBreakEvent() {}

    enmMode getMode() const { return m_eMode; }

    enmMode m_eMode;        // offset 0xD0, size 0x4
    clsFan_Obj* m_pcFanObj; // offset 0xD4, size 0x4
    u32 m_u32PartsNo;       // offset 0xD8, size 0x4
};

// total size: 0x320
class clsFan_Obj : public clsGimmickObj {
public:
    enum enmFanMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmFanState {
        STATE_STARTWAIT = 0,
        STATE_MAIN = 1,
        STATE_SLOW_INIT = 2,
        STATE_SLOW = 3,
        STATE_SLEEP = 4,
    };

    clsFan_Obj() {}
    virtual ~clsFan_Obj() {}

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST11_FAN_21030; }

    void setMode(enmFanMode eMode) { m_eFanMode = eMode; }
    enmFanMode getMode() const { return m_eFanMode; }
    void init() {}
    void reset() {}
    void stepMotoinFrame() {}
    void executeParts() {}

    enmFanMode m_eFanMode;     // offset 0x50, size 0x4
    enmFanState m_eFanState;   // offset 0x54, size 0x4
    f32 m_f32MotionFrame;      // offset 0x58, size 0x4
    f32 m_f32StartWaitFrame;   // offset 0x5C, size 0x4
    f32 m_f32AddFrame;         // offset 0x60, size 0x4
    f32 m_f32Angle;            // offset 0x64, size 0x4
    u32 m_u32BreakFlg;         // offset 0x68, size 0x4
    u32 m_u32GroundFlg;        // offset 0x6C, size 0x4
    u32 m_u32WallFlg;          // offset 0x70, size 0x4
    clsFan_Parts m_acParts[3]; // offset 0x80, size 0x2A0
};

#endif // ST11FAN_HPP
