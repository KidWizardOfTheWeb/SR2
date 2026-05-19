#ifndef GRAVITYRING_HPP
#define GRAVITYRING_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

class clsGravityRing_Object;

// total size: 0xC
class clsGravityRingThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsGravityRingThroughCollision() {}

    virtual void contactAlwaysEvent(clsPlayerTask* pcPlayer);

    clsGravityRing_Object* m_pcObject; // offset 0x8, size 0x4
};

// total size: 0x90
class clsGravityRing_Object : public clsPhantomGimmickObject {
public:
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    clsGravityRing_Object() {}
    virtual ~clsGravityRing_Object() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::GRAVITY_RING_2150; }

    void execute();
    void draw(clsModelType_OB_TX_MO_MA& rcModel, f32 (*psMtxWork)[4][4]);
    void start(clsPlayerTask* pcPlayer);

    static f32 tof32ClipSqDist;

    clsGravityRingThroughCollision m_cThroughCollision; // offset 0x60, size 0xC
    clsPlayerTask* m_pcPlayer;                          // offset 0x6C, size 0x4
    enmMode m_eMode;                                    // offset 0x70, size 0x4
    f32 m_f32MatMotionFrame;                            // offset 0x74, size 0x4
    f32 m_f32MatMotionAcceleRate;                       // offset 0x78, size 0x4
    f32 m_f32Frame;                                     // offset 0x7C, size 0x4
    f32 m_f32InvalidFrame;                              // offset 0x80, size 0x4
};

// total size: 0xB0
class clsGravityRing_Task : public clsSingleModelGimmick_Task<clsGravityRing_Task,
                                                              clsGravityRing_Object,
                                                              clsModelType_OB_TX_MO_MA> {
public:
    clsGravityRing_Task(u32 u32ObjectAreaNum);
    virtual ~clsGravityRing_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
    virtual void createModel(stcBinInfo& rsBinInfoI);

    clsGravityRing_Object* getGravityRingObjectPtr();

    u8 m_bDisableFog; // offset 0xAC, size 0x1
};

#endif // GRAVITYRING_HPP
