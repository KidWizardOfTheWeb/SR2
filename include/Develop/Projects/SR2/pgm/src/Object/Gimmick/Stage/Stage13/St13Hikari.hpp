#ifndef ST13HIKARI_HPP
#define ST13HIKARI_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0xE0
class clsSt13Hikari_Object : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode name collision — Game.hpp declares enmMode with different values; nested here
    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    };

    clsSt13Hikari_Object() {}
    virtual ~clsSt13Hikari_Object() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST13_HIKARI_23090; }
    virtual void reset();
    virtual void main();
    void draw(clsModelType_OB_TX_MO_MA& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    enmMode m_eMode;   // offset 0xD0, size 0x4
    f32 m_f32MatFrame; // offset 0xD4, size 0x4
    f32 m_f32Scale;    // offset 0xD8, size 0x4
    f32 m_f32MaxScale; // offset 0xDC, size 0x4

    static f32 tof32ClipSqDist;
};

class clsSt13Hikari_Task : public clsSingleModelGimmick_Task<clsSt13Hikari_Task,
                                                             clsSt13Hikari_Object,
                                                             clsModelType_OB_TX_MO_MA> {
public:
    clsSt13Hikari_Task(u32 u32ObjectAreaNum);
    virtual ~clsSt13Hikari_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST13HIKARI_HPP
