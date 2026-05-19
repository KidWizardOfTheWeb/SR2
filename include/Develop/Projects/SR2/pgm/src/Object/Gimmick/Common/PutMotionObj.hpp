#ifndef PUTMOTIONOBJ_HPP
#define PUTMOTIONOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;

// total size: 0x90
class clsPutMotionObj_Obj : public clsGimmickObj {
public:
    enum enmPutMotionObjMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_MOTION = 2,
        MODE_CHECK_WAIT = 3,
        MODE_WAIT = 4,
    };

    clsPutMotionObj_Obj() { init(); }
    virtual ~clsPutMotionObj_Obj() {}

    void init() {}
    void setMode(enmPutMotionObjMode ePutMotionObjMode) { m_ePutMotionObjMode = ePutMotionObjMode; }
    enmPutMotionObjMode getMode() const { return m_ePutMotionObjMode; }
    virtual nspPackId::enm getPackId() const { return nspPackId::PUT_MOTIONOBJ_2110; }
    void reset() {}
    u32 stepMotoinFrame() { return 0; }
    u32 checkHitPlayer() { return 0; }
    u32 checkWaitFrame() { return 0; }

    NNS_VECTORFAST m_sColPosVecFast;         // offset 0x50, size 0x10
    enmPutMotionObjMode m_ePutMotionObjMode; // offset 0x60, size 0x4
    f32 m_f32WaitFrame;                      // offset 0x64, size 0x4
    f32 m_f32Frame;                          // offset 0x68, size 0x4
    f32 m_f32MotionFrame;                    // offset 0x6C, size 0x4
    f32 m_f32MatMotionFrame;                 // offset 0x70, size 0x4
    f32 m_f32Radius;                         // offset 0x74, size 0x4
    u32 m_u32Type;                           // offset 0x78, size 0x4
    clsSe3DControl* m_pcSe3DControl;         // offset 0x7C, size 0x4
    u8 m_bSePlayFlg;                         // offset 0x80, size 0x1
};

class clsPutMotionObj_Task : public clsSingleModelGimmick_Task<clsPutMotionObj_Task,
                                                               clsPutMotionObj_Obj,
                                                               clsModelType_OB_TX_MO_MA> {
public:
    clsPutMotionObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsPutMotionObj_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // PUTMOTIONOBJ_HPP
