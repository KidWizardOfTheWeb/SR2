#ifndef ST08ROADCARCONTROL_HPP
#define ST08ROADCARCONTROL_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "types.h"

struct stcRoadInfo;
class clsRoad_Obj;
class clsRoadBase_Obj;

// total size: 0x1D0
class clsRoadCarControl {
    // Members
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_SORT = 1,
        MODE_MAIN = 2,
    };
    enum enmState {
        STATE_START = 0,
        STATE_MOVEWAIT = 1,
        STATE_MOVE = 2,
        STATE_MOVE_FIX = 3,
        STATE_STOPWAIT = 4,
        STATE_STOP = 5,
        STATE_STOP_FIX = 6,
        STATE_MAX = 7,
        SIGNAL_BLUE = 2,
        SIGNAL_YELLOW = 4,
        SIGNAL_RED = 5,
    };

    enmMode m_eMode;                        // offset 0x0, size 0x4
    enmState m_eState;                      // offset 0x4, size 0x4
    stcRoadInfo* m_opsRoadInfo;             // offset 0x8, size 0x4
    clsRoad_Obj* m_pcRoadObj;               // offset 0xC, size 0x4
    clsRigidBodyGimmickObj* m_pcGimmickObj; // offset 0x10, size 0x4
    clsRoadBase_Obj* m_pcRoadBaseObj;       // offset 0x14, size 0x4
    f32 m_f32SlowDownSpeed;                 // offset 0x18, size 0x4
    f32 m_f32BodyHafeSize;                  // offset 0x1C, size 0x4
    f32 m_f32OffsetY;                       // offset 0x20, size 0x4
    clsFrameControl m_cFrameControl;        // offset 0x24, size 0x8
    clsGimmickPath m_cGimmickPath;          // offset 0x30, size 0x190
    s8 m_s8Priority;                        // offset 0x1C0, size 0x1

    // Weak/inline functions
public:
    ~clsRoadCarControl();
    clsRoadCarControl(clsRigidBodyGimmickObj* param_1, clsRoadBase_Obj* param_2);

    enmState getState() const { return m_eState; }
    f32 getBodyHalfSize() const { return m_f32BodyHafeSize; }
    clsGimmickPath getGimmickPathRef() const { return m_cGimmickPath; }

    void setInfo(u8 u8RoadNum, f32 f32BodyHafeSize, f32 f32OffsetY, s8 s8Priority);
    void reset();
    void setWait();
    void reinitPath();
    void stepPathFrame();
    void checkWait();
    void requestMoveStop(f32 f32StartFrame, f32 f32SlowDownSpeed);
    void requestMoveStart(f32 f32StartFrame);
    void setState(enmState eState);
    void update();
};

#endif // ST08ROADCARCONTROL_HPP
