#ifndef ST08UFOCATCHER_HPP
#define ST08UFOCATCHER_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"

class clsPlayerTask;
class clsDebrisControl;
class clsBackLineEffectTask;

// total size: 0x28
class clsUfoCatcherModels {
public:
    clsUfoCatcherModels() {}
    ~clsUfoCatcherModels() {}

    clsModelType_OB_TX_MO m_cArm;  // offset 0x0, size 0x10
    clsModelType_OB_TX_MO m_cDoor; // offset 0x10, size 0x10
    clsModelType_OB_TX m_cBall;    // offset 0x20, size 0x8
};

class clsUfoCatcher_Obj;

// total size: 0x280
class clsUfoCatcher : public clsGimmickAutoRunObj {
public:
    // Note: enmMode name collision with Game.hpp ? nested per scaffold rule
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    enum enmState {
        STATE_WAIT = 0,
        STATE_MOVE_UFO = 1,
        STATE_RETURN_UFO = 2,
        STATE_END_UFO = 3,
        STATE_FALL = 4,
        STATE_MOVE_PATH = 5,
        STATE_BALL_BREAK = 6,
        STATE_END = 7,
        STATE_STARTWAIT = 8,
    };

    clsUfoCatcher() {}
    virtual ~clsUfoCatcher() {}
    virtual void destroy() {}

    void draw(clsUfoCatcherModels& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo,
              u32 NodeStatus);
    void execute();
    u8 stepArmFrame(f32 f32EndFrame);
    void start(clsPlayerTask* pcPlayerTask, clsUfoCatcher_Obj* pcObj);
    void setBall(clsPlayerTask* pcPlayerTask, clsUfoCatcher_Obj* pcObj);

    void setState(enmState eState) { m_eState = eState; }
    void getBallPosition(NNS_VECTORFAST& rsVecFast) {}
    enmState getState() const { return m_eState; }

    enmMode m_eMode;                         // offset 0x1C0, size 0x4
    enmState m_eState;                       // offset 0x1C4, size 0x4
    clsUfoCatcher_Obj* m_pcUfoObj;           // offset 0x1C8, size 0x4
    f32 m_f32ArmMotionFrame;                 // offset 0x1CC, size 0x4
    f32 m_sTrsMtxBall[4][4];                 // offset 0x1D0, size 0x40
    clsDebrisControl* m_pcDebrisControl;     // offset 0x210, size 0x4
    f32 m_f32PlayerScale;                    // offset 0x214, size 0x4
    clsFrameControl m_cFrameControl;         // offset 0x218, size 0x8
    u8 m_bCatch;                             // offset 0x220, size 0x1
    u8 m_u8UfoSeFlg;                         // offset 0x221, size 0x1
    f32 m_sLineDrawMtx[4][4];                // offset 0x230, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x270, size 0x8

    static f32 m_tof32CLIP_DISTx2;
    static NNS_VECTORFAST t_osPlayerOffstVecFast;
};

// total size: 0xD0
class clsUfoCatcher_Obj : public clsPhantomGimmickObject {
public:
    // Note: enmMode name collision with Game.hpp ? nested per scaffold rule
    enum enmMode {
        MODE__READY = 0,
        MODE__WAIT = 1,
        MODE__CHARGE = 2,
        MODE__SHOOT = 3,
        MODE__HORMING = 4,
        MODE__BLAST = 5,
    };

    // Note: enmCtrlMode name collision with GearCtrl.hpp ? nested per scaffold rule
    enum enmCtrlMode {
        CTRL_NULL = 0,
        CTRL_RUN = 1,
        CTRL_STOP = 2,
    };

    enum enmDoorMode {
        DOOR_OPEN_INIT = 0,
        DOOR_OPEN = 1,
        DOOR_OPEN_FIX = 2,
        DOOR_CLOSE_INIT = 3,
        DOOR_CLOSE = 4,
        DOOR_CLOSE_FIX = 5,
    };

    clsUfoCatcher_Obj() {}
    virtual ~clsUfoCatcher_Obj() {}
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST08_UFOCATCHER_18050; }
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);

    void draw(clsUfoCatcherModels& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void execute();
    clsUfoCatcher* getStateCmp(clsUfoCatcher::enmState eState);
    void openDoor(f32 f32Distx2, clsPlayerTask* pcPlayer);
    void stopBallSe(clsPlayerTask* pcPlayer);
    void playBallSe(clsPlayerTask* pcPlayer);
    void registBall(clsPlayerTask* pcPlayer);
    void init();
    void setDoorMode(enmDoorMode ed) { m_eDoorMode = ed; }

    enum enmMode m_eMode;                                // offset 0x60, size 0x4
    clsGimmickAutoRunBuffer<clsUfoCatcher> m_cUfoBuffer; // offset 0x64, size 0x1C
    enum enmCtrlMode m_aeCtrlMode[8];                    // offset 0x80, size 0x20
    f32 m_f32MotionFrame;                                // offset 0xA0, size 0x4
    enum enmDoorMode m_eDoorMode;                        // offset 0xA4, size 0x4
    f32 m_f32DoorMotionFrame;                            // offset 0xA8, size 0x4
    NNS_VECTORFAST m_sDoorPosVecFast;                    // offset 0xB0, size 0x10
    s16 m_as16SeSfId[4];                                 // offset 0xC0, size 0x8

    static f32 t_of32ClipDistx2;
    static NNS_VECTORFAST t_osPosVecFast;
};

// total size: 0xB4
class clsUfoCatcher_Task
    : public clsBaseGimmickBody<clsUfoCatcher_Task, clsUfoCatcher_Obj, clsUfoCatcherModels> {
public:
    clsUfoCatcher_Task(u32 u32ObjectAreaNum);
    virtual ~clsUfoCatcher_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
};

#endif // ST08UFOCATCHER_HPP
