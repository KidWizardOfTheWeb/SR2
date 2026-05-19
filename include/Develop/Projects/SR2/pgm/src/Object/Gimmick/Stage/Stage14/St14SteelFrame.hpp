#ifndef ST14STEELFRAME_HPP
#define ST14STEELFRAME_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"

enum enmSteelFrameMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0xE0
class clsSteelFrame_Obj : public clsRigidBodyGimmickObj {
public:
    clsSteelFrame_Obj();
    virtual ~clsSteelFrame_Obj();
    virtual void init();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual void reset();
    virtual void main();
    virtual void requestDrawCrashEffect(const hkContactPoint* pParam1);
    virtual u8 checkRequestDrawDebris();

    enmSteelFrameMode m_eSteelFrameMode; // offset 0xD0, size 0x4

    static f32 tof32ClipSqDist;
};

// total size: 0x98
class clsSteelFrame_Task
    : public clsSingleModelGimmick_Task<clsSteelFrame_Task, clsSteelFrame_Obj, clsModelType_OB_TX> {
public:
    clsSteelFrame_Task(u32 u32ObjectAreaNum);
    virtual ~clsSteelFrame_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST14STEELFRAME_HPP
