#ifndef ST07MAPPARTSFLOORSWITCH_HPP
#define ST07MAPPARTSFLOORSWITCH_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x310
class clsMapPartsFloorSwitch_Object : public clsMapPartsObject {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
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

    f32 m_f32MatMotionFrame;         // offset 0xE0, size 0x4
    f32 m_f32MotionFrame;            // offset 0xE4, size 0x4
    enmMode m_eMode;                 // offset 0xE8, size 0x4
    f32 m_f32Count;                  // offset 0xEC, size 0x4
    enmState m_eState;               // offset 0xF0, size 0x4
    u32 m_u32Type;                   // offset 0xF4, size 0x4
    clsGimmickObj* m_pcObj[31];      // offset 0xF8, size 0x7C
    f32 m_sEffectMtx[6][4][4];       // offset 0x180, size 0x180
    clsSe3DControl* m_pcSe3DControl; // offset 0x300, size 0x4

    clsMapPartsFloorSwitch_Object() {}
    virtual ~clsMapPartsFloorSwitch_Object() {}
    enmState getState() const { return m_eState; }

    void extensionActiveFrame();
    void destroyData();
    u8 checkPath(u32 u32PathNum);
    u32 getType(u32 u32Rank);
    void init();
    void resetObject();
    void setObject();
    void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pcOther);
    void reset();
    void createData();
    void execute();

    static f32 tof32ClipSqDist;
};

// total size: 0xAC
class clsMapPartsFloorSwitch_Task : public clsSingleModelGimmick_Task<clsMapPartsFloorSwitch_Task,
                                                                      clsMapPartsFloorSwitch_Object,
                                                                      clsModelType_OB_TX_MO_MA> {
public:
    clsMapPartsFloorSwitch_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsFloorSwitch_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    static NNS_VECTOR tosCollisionHalfSizeVec;
};

#endif // ST07MAPPARTSFLOORSWITCH_HPP
