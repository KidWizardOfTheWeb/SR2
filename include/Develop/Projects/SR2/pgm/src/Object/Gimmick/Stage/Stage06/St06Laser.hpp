#ifndef ST06LASER_HPP
#define ST06LASER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14Laser.hpp" // provides enmLaserMode

class hkContactPoint;

// total size: 0x80
class clsLaser_Obj : public clsPhantomGimmickObject {
public:
    clsLaser_Obj() {}
    virtual ~clsLaser_Obj() {}
    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST06_LASER_16020; }

    enmLaserMode getMode() const { return m_eLaserMode; }

    enum enmLaserMode m_eLaserMode; // offset 0x60, size 0x4
    f32 m_f32MatMotEndFrame;        // offset 0x64, size 0x4
    f32 m_f32MatMotFrame;           // offset 0x68, size 0x4
    f32 m_f32WaitFrame;             // offset 0x6C, size 0x4
    u8 m_bVoicePlayFlag;            // offset 0x70, size 0x1

    static f32 tof32ClipSqDist;
};

// total size: 0xAC
class clsLaser_Task
    : public clsSingleModelGimmick_Task<clsLaser_Task, clsLaser_Obj, clsModelType_OB_TX_MO_MA> {
public:
    clsLaser_Task(u32 u32ObjectAreaNum);
    virtual ~clsLaser_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // ST06LASER_HPP
