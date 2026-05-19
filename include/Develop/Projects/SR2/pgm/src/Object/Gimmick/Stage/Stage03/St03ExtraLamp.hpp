#ifndef ST03EXTRALAMP_HPP
#define ST03EXTRALAMP_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsPress_Obj;

enum enmExtraLampMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

enum enmExtraLampState {
    STATE_STARTWAIT = 0,
    STATE_FALL = 1,
    STATE_FALL_WAIT = 2,
    STATE_RISE = 3,
    STATE_SLEEP = 4,
};

// total size: 0x60
class clsExtraLamp_Obj : public clsGimmickObj {
public:
    clsExtraLamp_Obj() {}
    virtual ~clsExtraLamp_Obj() {}
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST03_EXTRALAMP_13020; }
    void draw(clsModelType_OB_TX& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo,
              u32 NodeFlg);

    enmExtraLampMode m_eExtraLampMode;   // offset 0x50, size 0x4
    enmExtraLampState m_eExtraLampState; // offset 0x54, size 0x4
};

// total size: 0x54
class clsExtraLampDraw_Task : public clsTask {
public:
    virtual ~clsExtraLampDraw_Task() {}
    virtual void draw();
};

// total size: 0x8
struct _stcColorParam {
    u32 u32TexId; // offset 0x0, size 0x4
    f32 f32Frame; // offset 0x4, size 0x4
};

// total size: 0xB4
class clsExtraLamp_Task
    : public clsSingleModelGimmick_Task<clsExtraLamp_Task, clsExtraLamp_Obj, clsModelType_OB_TX> {
public:
    enum enmState {
        STATE_START = 0,
        STATE_STOP = 1,
        STATE_SAFE_STOP = 2,
    };

    clsExtraLamp_Task(u32 u32ObjectAreaNum);
    virtual ~clsExtraLamp_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    void start();
    void stop();
    void setLampColor(u32 u32ParamNo);

    enmState m_eState;          // offset 0x94, size 0x4
    u32 m_u32ColorParamNo;      // offset 0x98, size 0x4
    f32 m_f32MotionFrame;       // offset 0x9C, size 0x4
    u16* m_pTexIdxLamp;         // offset 0xA0, size 0x4
    u16 m_pOldTexIdxLamp;       // offset 0xA4, size 0x2
    f32* m_pf32TexCoordU;       // offset 0xA8, size 0x4
    clsPress_Obj* m_pcPressObj; // offset 0xAC, size 0x4
    s32 m_s32SeId;              // offset 0xB0, size 0x4

    static _stcColorParam m_tosColorParam[5];
};

#endif // ST03EXTRALAMP_HPP
