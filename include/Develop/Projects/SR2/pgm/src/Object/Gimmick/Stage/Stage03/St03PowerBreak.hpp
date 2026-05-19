#ifndef ST03POWERBREAK_HPP
#define ST03POWERBREAK_HPP

#include "types.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

enum enmPowerBreakMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0xE0
class clsPowerBreak_Obj : public clsRigidBodyGimmickObj {
public:
    clsPowerBreak_Obj();
    virtual ~clsPowerBreak_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual inline nspPackId::enm getPackId() const;

    void reset();
    void main();
    void requestDrawBreakEffect();

    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    enum enmPowerBreakMode m_eMode;  // offset 0xD0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xD4, size 0x4
};

// total size: 0x98
class clsPowerBreak_Task
    : public clsSingleModelGimmick_Task<clsPowerBreak_Task, clsPowerBreak_Obj, clsModelType_OB_TX> {
public:
    clsPowerBreak_Task(u32 u32ObjectAreaNum);
    virtual ~clsPowerBreak_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST03POWERBREAK_HPP
