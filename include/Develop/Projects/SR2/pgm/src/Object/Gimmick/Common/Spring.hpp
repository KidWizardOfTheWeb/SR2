#ifndef SPRING_HPP
#define SPRING_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;
class clsMapPartsFloorSwitch_Object;

enum enmSpringMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0xB0
class clsSpring_Obj : public clsPhantomGimmickObject {
public:
    enmSpringMode m_enSpringMode;                 // offset 0x60, size 0x4
    f32 m_f32Count;                               // offset 0x64, size 0x4
    f32 m_f32JumpSpeed;                           // offset 0x68, size 0x4
    clsSpring_Obj* m_pcNextObj;                   // offset 0x6C, size 0x4
    clsPlayerTask* m_pcPlayerTask;                // offset 0x70, size 0x4
    s32 m_s32HitFrame;                            // offset 0x74, size 0x4
    NNS_VECTORFAST m_sUpVecFast;                  // offset 0x80, size 0x10
    NNS_VECTORFAST m_sTopPosVecFast;              // offset 0x90, size 0x10
    f32 m_f32Scale;                               // offset 0xA0, size 0x4
    u16 m_ModelNo;                                // offset 0xA4, size 0x2
    clsMapPartsFloorSwitch_Object* m_pcSwitchObj; // offset 0xA8, size 0x4

    static f32 m_tof32CLIP_DISTx2;
    static u8 m_toau8TopNodeNo[3];

    clsSpring_Obj() {}
    virtual ~clsSpring_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::SPRING_2030; }
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void init() {}
};

// total size: 0xB0
class clsSpring_Task
    : public clsSingleModelGimmick_Task<clsSpring_Task, clsSpring_Obj, clsModelType_OB_TX>,
      public clsGimmickCommon {
public:
    clsSpring_Task(u32 u32ObjectAreaNum) : clsSingleModelGimmick_Task(0, 0) {}
    virtual ~clsSpring_Task() {}
    virtual void execute();
    virtual void draw();

    void playSpringSe(clsPlayerTask* pcPlayer);
    void stopSpringSe(clsPlayerTask* pcPlayer);

    NNS_VECTORFAST m_sDebugPathMoveFast; // offset 0xA0, size 0x10
};

#endif // SPRING_HPP
