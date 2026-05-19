#ifndef ST07MAPPARTSFLOORCHANGE_HPP
#define ST07MAPPARTSFLOORCHANGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBomb.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;

// total size: 0x150
class clsMapPartsFloorChange_Object : public clsMapPartsObject {
public:
    inline clsMapPartsFloorChange_Object() : clsMapPartsObject() {}
    virtual ~clsMapPartsFloorChange_Object() {}

    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    }; // Note: name collision with Game.hpp enmMode

    enum enmState {
        STATE_MAIN = 0,
        STATE_ACTION = 1,
        STATE_WAIT = 2,
    }; // Note: name collision with St03Cogwheel.hpp enmState

    f32 m_f32MotionFrame;            // offset 0xE0, size 0x4
    f32 m_f32Num;                    // offset 0xE4, size 0x4
    enmMode m_eMode;                 // offset 0xE8, size 0x4
    enmState m_eState;               // offset 0xEC, size 0x4
    hkVector4 m_cUpSpeed;            // offset 0xF0, size 0x10
    hkVector4 m_cRotSpeed;           // offset 0x100, size 0x10
    f32 m_f32Count;                  // offset 0x110, size 0x4
    f32 m_f32MoveAngle;              // offset 0x114, size 0x4
    f32 m_f32MovePos;                // offset 0x118, size 0x4
    NNS_VECTORFAST m_sInitPosVF;     // offset 0x120, size 0x10
    NNS_QUATERNION m_sInitQuat;      // offset 0x130, size 0x10
    clsSe3DControl* m_pcSe3DControl; // offset 0x140, size 0x4

    static f32 tof32ClipSqDist;

    virtual void execute();
    virtual void StepMotionFrame();
    virtual void createData();
    virtual void reset();
    virtual u8 checkObj(f32 f32Num, bool bPowerFlag);
    virtual u8 checkObj_Reverse(f32 f32Num, bool bPowerFlag);
    virtual u8 set_Kicker(f32 f32Num);
    virtual void destroyData();
};

// total size: 0x94
class clsMapPartsFloorChange_Task : public clsSingleModelGimmick_Task<clsMapPartsFloorChange_Task,
                                                                      clsMapPartsFloorChange_Object,
                                                                      clsModelType_OB_TX_MO> {
public:
    clsMapPartsFloorChange_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsFloorChange_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    static NNS_VECTOR tosCollisionHalfSizeVec;
};

#endif // ST07MAPPARTSFLOORCHANGE_HPP
