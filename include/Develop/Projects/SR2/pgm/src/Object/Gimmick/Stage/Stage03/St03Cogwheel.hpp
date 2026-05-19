#ifndef ST03COGWHEEL_HPP
#define ST03COGWHEEL_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/hkArray.hpp"

class clsSe3DControl;
class hkContactImpulseLimitBreachedListener;

enum enmCogwheelState {
    STATE_STARTWAIT = 0,
    STATE_MAIN = 1,
    STATE_SLOW_INIT = 2,
    STATE_SLOW = 3,
    STATE_SLEEP = 4,
};

// Forward declarations for circular references
class clsCogwheel_Obj;
class clsCogwheel_Task;

// total size: 0x14
// Note: original source has spelling error — "clsCogWhellModel" (f64-l)
class clsCogWhellModel {
public:
    clsCogWhellModel() {}
    ~clsCogWhellModel() {}

    clsModelType_OB_TX_MO m_cModel; // offset 0x0, size 0x10
    void* m_pvBin;                  // offset 0x10, size 0x4
};

// total size: 0xF0
class clsCogwheel_Parts : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode collision with global enmMode from Game.hpp — nested for safety
    enum enmMode {
        MODE_MAIN = 0,
        MDOE_BREAK = 1, // typo preserved from original
        MODE_DIE = 2,
    };

    virtual ~clsCogwheel_Parts() {}
    clsCogwheel_Parts() {}
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawCrashEffect(const hkContactPoint* pParam1);
    virtual void requestDrawBreakEffect();
    virtual void callbackCrashEvent();
    virtual void callbackBreakEvent() {}

    inline enmMode getMode() const { return m_eMode; }

    enmMode m_eMode;                   // offset 0xD0, size 0x4
    clsCogwheel_Obj* m_pcCogwheelObj;  // offset 0xD4, size 0x4
    u32 m_u32PartsNo;                  // offset 0xD8, size 0x4
    NNS_VECTORFAST m_sCrushPosVecFast; // offset 0xE0, size 0x10
};

// total size: 0xBD0
class clsCogwheel_Obj : public clsGimmickObj {
public:
    // enmCogwheelMode — nested: setMode is Q2-mangled as clsCogwheel_Obj::enmCogwheelMode
    enum enmCogwheelMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    virtual ~clsCogwheel_Obj() {}
    clsCogwheel_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST03_COGWHEEL_13000; }
    virtual u32 getMultiDrawNum() const { return 13; }
    virtual void createData();
    virtual void destroyData();

    void debugDrawCollision();
    inline enmCogwheelMode getMode() const { return m_eCogwheelMode; }
    inline void setMode(enmCogwheelMode mode) { m_eCogwheelMode = mode; }
    void executeParts() {}
    void reset() {}
    void stepMotoinFrame() {} // typo preserved from original
    void init() {}
    void resetPartsParam() {}

    enmCogwheelMode m_eCogwheelMode;   // offset 0x50, size 0x4
    enmCogwheelState m_eCogwheelState; // offset 0x54, size 0x4
    f32 m_f32MotionFrame;              // offset 0x58, size 0x4
    f32 m_f32StartWaitFrame;           // offset 0x5C, size 0x4
    f32 m_f32AddFrame;                 // offset 0x60, size 0x4
    f32 m_f32Angle;                    // offset 0x64, size 0x4
    u32 m_u32BreakFlg;                 // offset 0x68, size 0x4
    u32 m_u32GroundFlg;                // offset 0x6C, size 0x4
    u32 m_u32WallFlg;                  // offset 0x70, size 0x4
    clsCogwheel_Parts m_acParts[12];   // offset 0x80, size 0xB40
    clsSe3DControl* m_pcSe3DControl;   // offset 0xBC0, size 0x4
};

// total size: 0x14
class clsCogwheelThroughCollision : public clsBaseThroughCollision {
public:
    // enmMode — nested: createThroughCollision parameter is Q2-mangled as
    // clsCogwheelThroughCollision::enmMode
    enum enmMode {
        MODE_START = 0,
        MODE_STOP = 1,
        MODE_WHEEL_IN = 2,
        MODE_WHEEL_OUT = 3,
    };

    virtual ~clsCogwheelThroughCollision() {}
    clsCogwheelThroughCollision();
    virtual void contactTriggerEvent(clsPlayerTask* pParam1);

    enmMode m_eMode;                     // offset 0x8, size 0x4
    clsCogwheel_Task* m_pcCogwheel_Task; // offset 0xC, size 0x4
    clsCogwheel_Obj* m_pcCogwheel_Obj;   // offset 0x10, size 0x4
};

// total size: 0x8
class _stcShapeInfo {
public:
    hkShape* pcShape;    // offset 0x0, size 0x4
    u32 u32CollisionNum; // offset 0x4, size 0x4
};

// total size: 0x138
class clsCogwheel_Task
    : public clsSingleModelGimmick_Task<clsCogwheel_Task, clsCogwheel_Obj, clsCogWhellModel> {
public:
    // Note: enmState collision with St07MapPartsFloorSwitch.hpp — nested for safety
    enum enmState {
        STATE_START = 0,
        STATE_STOP = 1,
    };

    enum enmThroughCollisionNum {
        THROUGH_COLLISION_START_00 = 0,
        THROUGH_COLLISION_START_01 = 1,
        THROUGH_COLLISION_START_02 = 2,
        THROUGH_COLLISION_START_03 = 3,
        THROUGH_COLLISION_STOP = 4,
        THROUGH_COLLISION_MAX = 5,
    };

    clsCogwheel_Task(u32 u32Param1);
    virtual ~clsCogwheel_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rParam1);

    f32 getMissionRot(clsCogwheel_Obj* pParam1);
    void createThroughCollision(enmThroughCollisionNum,
                                clsCogwheelThroughCollision::enmMode,
                                u8 u8Param3);

    static NNS_VECTORFAST m_tosPartsOffsetFast[12];   // 0x67E990
    static NNS_VECTOR m_tosThroughCollisionPosVec[5]; // 0x67EA50
    static f32 m_tof32ThroughCollisionRotY[5];        // 0x67EA90

    hkShape* m_pcThroughShape[2];                                 // offset 0xA0, size 0x8
    clsCogwheelThroughCollision m_acCollision[5];                 // offset 0xA8, size 0x64
    enmState m_eState;                                            // offset 0x10C, size 0x4
    u32 m_u32PlayerFlg;                                           // offset 0x110, size 0x4
    s32 m_s32CollisionNum;                                        // offset 0x114, size 0x4
    _stcShapeInfo* m_apcShape;                                    // offset 0x118, size 0x4
    NNS_NODE* m_psNodeList;                                       // offset 0x11C, size 0x4
    vector m_vctShapeSearch;                                      // offset 0x120, size 0xC
    hkArray<hkContactImpulseLimitBreachedListener*> m_vctpcShape; // offset 0x12C, size 0xC
};

#endif // ST03COGWHEEL_HPP
