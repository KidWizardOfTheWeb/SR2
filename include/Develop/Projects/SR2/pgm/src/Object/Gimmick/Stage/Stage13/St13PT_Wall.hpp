#ifndef ST13PT_WALL_HPP
#define ST13PT_WALL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

enum enmGateMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

class clsPT_Wall_Obj;

// total size: 0x110
class clsPT_Wall_Parts : public clsRigidBodyGimmickObj {
public:
    inline clsPT_Wall_Parts() : clsRigidBodyGimmickObj() {}
    virtual ~clsPT_Wall_Parts() {}

    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enmMode m_eMode;                  // offset 0xD0, size 0x4
    clsPT_Wall_Obj* m_pcPTWallObj;    // offset 0xD4, size 0x4
    u32 m_u32PartsNo;                 // offset 0xD8, size 0x4
    NNS_VECTORFAST m_sInitPosVecFast; // offset 0xE0, size 0x10
    NNS_QUATERNION m_sInitRotQuat;    // offset 0xF0, size 0x10
    u8 m_bSetGravityFlag;             // offset 0x100, size 0x1
    u8 m_bCatchFlag;                  // offset 0x101, size 0x1

    static f32 tof32ClipSqDist;

    virtual void reset();
    virtual void main();
    virtual void createData();
    virtual void destroyData();
    virtual void draw(clsModelType_OB_TX& rParam1,
                      f32 (*)[4][4],
                      u32* pParam3,
                      const f32 (*)[4][4],
                      f32 (*)[4][4]);
    virtual void callbackGravityEvent();
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void requestDrawBreakEffect();
};

// total size: 0x4B0
class clsPT_Wall_Obj : public clsGimmickObj {
public:
    clsPT_Wall_Obj() {}
    virtual ~clsPT_Wall_Obj() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST13_PT_WALL_23120; }
    virtual void reset();

    enmGateMode m_eMode;           // offset 0x50, size 0x4
    clsPT_Wall_Parts m_acParts[4]; // offset 0x60, size 0x440
    f32 m_f32ResetCount;           // offset 0x4A0, size 0x4
};

// total size: 0x98
class clsPT_Wall_Task
    : public clsSingleModelGimmick_Task<clsPT_Wall_Task, clsPT_Wall_Obj, clsModelType_OB_TX> {
public:
    clsPT_Wall_Task(u32 u32ObjectAreaNum);
    virtual ~clsPT_Wall_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST13PT_WALL_HPP
