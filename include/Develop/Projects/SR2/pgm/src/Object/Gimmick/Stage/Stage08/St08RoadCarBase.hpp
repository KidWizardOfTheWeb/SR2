#ifndef ST08ROADCARBASE_HPP
#define ST08ROADCARBASE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadCarControl.hpp"
#include "types.h"

// total size: 0x0
class clsRoadBase_Obj {
public:
    static f32 t_of32MaxVelocity;
    static f32 t_of32MaxAngleVelocity;

    clsRoadBase_Obj() {}
    virtual ~clsRoadBase_Obj() {}
    virtual void eventSetPosition() {}
    virtual void eventStartMove() {}
    virtual void eventStopMove() {}
    virtual void requestRunSe() {}
    virtual void requestHorn() {}
    virtual void stopRunSe() {}
    virtual void resetRigidBody() {}
};

// total size: 0x2B0
class clsRoadCarBase_Obj : public clsRigidBodyGimmickObj, public clsRoadBase_Obj {
public:
    clsRoadCarBase_Obj() : m_cRoadCarControl(this, this) {}

    enum enmMode {
        MODE_INIT = 0,
        MODE_STARTWAIT = 1,
        MODE_MAIN = 2,
        MODE_WAIT = 3,
    };

    enmMode m_eMode;                     // offset 0xD4, size 0x4
    clsRoadCarControl m_cRoadCarControl; // offset 0xE0, size 0x1D0

    virtual ~clsRoadCarBase_Obj() {}
    virtual void init();
    virtual void reset();
    virtual void main();
    virtual void callbackGravityEvent() {}
    virtual void execute();
    virtual void resetObject();
    virtual void eventStartMove() {}
    virtual void eventStopMove() {}
    virtual void resetRigidBody();
};

// total size: 0x2C0
class clsRoadGlinkCarBase_Obj : public clsBaseGravityLinkObject, public clsRoadBase_Obj {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enmMode m_eMode;                     // offset 0xE4, size 0x4
    clsRoadCarControl m_cRoadCarControl; // offset 0xF0, size 0x1D0

    clsRoadGlinkCarBase_Obj() : m_cRoadCarControl((clsRigidBodyGimmickObj*)0, (clsRoadBase_Obj*)0)
    {
    }
    virtual ~clsRoadGlinkCarBase_Obj() {}
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void callbackGravityEvent() {}
    virtual void resetObject();
    virtual void execute();
    virtual void eventStartMove() {}
    virtual void eventStopMove() {}
    virtual void resetRigidBody();
};

#endif // ST08ROADCARBASE_HPP
