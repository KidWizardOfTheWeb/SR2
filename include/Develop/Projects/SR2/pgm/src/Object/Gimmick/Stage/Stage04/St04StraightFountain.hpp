#ifndef ST04STRAIGHTFOUNTAIN_HPP
#define ST04STRAIGHTFOUNTAIN_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsStraightFountain_Obj;
class clsStraightFountainThroughCollision;
class clsTask;
class clsSe3DControl;
class hkShape;

// total size: 0xC
class clsStraightFountainThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsStraightFountainThroughCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pParam1);

    clsStraightFountain_Obj* m_pcStraightFountain; // offset 0x8, size 0x4
};

// total size: 0xE0
class clsStraightFountain_Obj : public clsGimmickObj {
public:
    enum enmStraightFountainMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmStraightFountainState {
        STATE_WAIT = 0,
        STATE_MOVE = 1,
    };

    clsStraightFountain_Obj() {}
    virtual ~clsStraightFountain_Obj() {}

    enmStraightFountainMode getMode() const { return m_eMode; }
    enmStraightFountainState getState() const { return m_eState; }
    void setMode(enmStraightFountainMode eMode) { m_eMode = eMode; }
    void setState(enmStraightFountainState eState) { m_eState = eState; }
    virtual nspPackId::enm getPackId() const { return nspPackId::ST04_STRAIGHT_FOUNTAIN_14030; }
    void init() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    u8 stepMotionFrame();
    void ChackMode();
    void setMist(bool bFlg);

    static f32 tof32ClipSqDist;
    static u32 otau32Se_Spring[2];

    enmStraightFountainMode m_eMode;                    // offset 0x50, size 0x4
    enmStraightFountainState m_eState;                  // offset 0x54, size 0x4
    clsStraightFountainThroughCollision* m_pcCollision; // offset 0x58, size 0x4
    hkShape* m_pcShape;                                 // offset 0x5C, size 0x4
    f32 m_f32MotionFrame;                               // offset 0x60, size 0x4
    NNS_VECTOR m_sPosition;                             // offset 0x64, size 0xC
    NNS_QUATERNION m_sRotQuat;                          // offset 0x70, size 0x10
    f32 m_sScale;                                       // offset 0x80, size 0x4
    f32 m_f32Wait;                                      // offset 0x84, size 0x4
    clsTask* m_psWaterParticle;                         // offset 0x88, size 0x4
    f32 m_sPosturalMtx[4][4];                           // offset 0x90, size 0x40
    clsSe3DControl* m_pcSe3DControl;                    // offset 0xD0, size 0x4
};

// total size: 0xA0
class clsStraightFountain_Task : public clsSingleModelGimmick_Task<clsStraightFountain_Task,
                                                                   clsStraightFountain_Obj,
                                                                   clsModelType_OB_TX_MO> {
public:
    clsStraightFountain_Task(u32 u32ObjectAreaNum);
    virtual ~clsStraightFountain_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    f32* m_pf32TexCoordV; // offset 0x9C, size 0x4
};

#endif // ST04STRAIGHTFOUNTAIN_HPP
