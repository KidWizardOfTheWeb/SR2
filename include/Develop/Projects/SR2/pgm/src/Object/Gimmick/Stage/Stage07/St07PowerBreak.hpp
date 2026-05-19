#ifndef ST07POWERBREAK_HPP
#define ST07POWERBREAK_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0xE0
class clsSt07PowerBreak_Obj : public clsRigidBodyGimmickObj {
public:
    // Note: enmPowerBreakMode name collision with St03PowerBreak.hpp — nested to resolve ambiguity
    enum enmPowerBreakMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsSt07PowerBreak_Obj();
    virtual ~clsSt07PowerBreak_Obj();
    virtual void init();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void setCollisionFilter(bool bParam1);

    enmPowerBreakMode m_eMode;       // offset 0xD0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xD4, size 0x4

    static f32 tof32ClipSqDist;
};

// total size: 0x94
class clsSt07PowerBreak_Task : public clsSingleModelGimmick_Task<clsSt07PowerBreak_Task,
                                                                 clsSt07PowerBreak_Obj,
                                                                 clsModelType_OB_TX> {
public:
    clsSt07PowerBreak_Task(u32 u32ObjectAreaNum);
    virtual ~clsSt07PowerBreak_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST07POWERBREAK_HPP
