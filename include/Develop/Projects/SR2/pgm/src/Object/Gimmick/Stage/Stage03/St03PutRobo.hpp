#ifndef ST03PUTROBO_HPP
#define ST03PUTROBO_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;

enum enmPutRoboMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0xF0
class clsPutRobo_Obj : public clsRigidBodyGimmickObj {
public:
    inline clsPutRobo_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsPutRobo_Obj() {}

    enmPutRoboMode m_enPutRoboMode;  // offset 0xD0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xD4, size 0x4
    u32 m_u32ClipFlg;                // offset 0xD8, size 0x4
    f32 m_f32GravityLimitFrame;      // offset 0xDC, size 0x4
    f32 m_f32ClipDist;               // offset 0xE0, size 0x4

    static f32 m_tof32CLIP_DISTx2;
    static clsGravityGimmickParam t_ocGravityGimmickParams[2];
    static u32 otau32Se_RoboExp[2];
    static u32 otau32Se_RoboCrash[2];

    virtual void createData();
    virtual void destroyData();
    virtual void requestDrawBreakEffect();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual void callbackGravityEvent();
    virtual void main();
    virtual void mainGravity();
    inline void init() {}
    inline void reset() {}
    inline nspPackId::enm getPackId() const { return nspPackId::ST03_PUT_ROBO_13030; }
};

// total size: 0x98
class clsPutRobo_Task
    : public clsSingleModelGimmick_Task<clsPutRobo_Task, clsPutRobo_Obj, clsModelType_OB_TX> {
public:
    clsPutRobo_Task(u32 u32ObjectAreaNum);
    virtual ~clsPutRobo_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    u32 m_u32DrawType; // offset 0x94, size 0x4
};

#endif // ST03PUTROBO_HPP
