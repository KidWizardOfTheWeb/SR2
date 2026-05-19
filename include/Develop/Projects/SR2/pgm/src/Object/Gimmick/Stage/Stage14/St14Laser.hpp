#ifndef ST14LASER_HPP
#define ST14LASER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;

// total size: 0x8
class clsLaserThroughCollision : public clsBaseThroughCollision {
public:
    clsLaserThroughCollision() : clsBaseThroughCollision() {}
    virtual ~clsLaserThroughCollision() {}

    void contactTriggerEvent(clsPlayerTask* pcPlayer);
};

enum enmLaserMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_WAIT = 2,
};

class clsSt14Laser_Obj : public clsRigidBodyGimmickObj {
public:
    clsSt14Laser_Obj() {}
    virtual ~clsSt14Laser_Obj() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST14_LASER_24020; }
    virtual void reset() { m_eLaserMode = MODE_INIT; }
    enmLaserMode getMode() const { return m_eLaserMode; }

    static f32 tof32ClipSqDist;

public:
    enmLaserMode m_eLaserMode; // offset 0xD0, size 0x4
    f32 m_f32MatMotEndFrame;   // offset 0xD4, size 0x4
    f32 m_f32MatMotFrame;      // offset 0xD8, size 0x4
    f32 m_f32WaitFrame;        // offset 0xDC, size 0x4
    s32 m_s32CheckRank;        // offset 0xE0, size 0x4
};

// total size: 0xB8
class clsSt14Laser_Task : public clsSingleModelGimmick_Task<clsSt14Laser_Task,
                                                            clsSt14Laser_Obj,
                                                            clsModelType_OB_TX_MO_MA> {
public:
    clsSt14Laser_Task(u32 u32ObjectAreaNum);
    virtual ~clsSt14Laser_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    clsLaserThroughCollision m_cCollision; // offset 0xAC, size 0x8
    hkShape* m_pcThroughShape;             // offset 0xB4, size 0x4
};

#endif // ST14LASER_HPP
