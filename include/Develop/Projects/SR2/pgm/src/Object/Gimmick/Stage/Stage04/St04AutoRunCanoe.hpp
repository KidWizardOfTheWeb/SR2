#ifndef ST04AUTORUNCANOE_HPP
#define ST04AUTORUNCANOE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Sound/PlaySe_2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"

class hkShape;
class hkContactPoint;
class clsObject;
class clsAutoRunCanoe;
class clsMiniWaveGmkAutoRunObjEffect_Task;
class clsSe3DControl;

// total size: 0xC0
class clsAutoRunCanoe_Obj : public clsPhantomGimmickObject {
public:
    clsAutoRunCanoe_Obj();
    virtual ~clsAutoRunCanoe_Obj();

    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual void init();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST04_AUTORUN_CANOE_14000; }
    virtual void controlPlayer();

    enum enmAutoRunCanoeMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmControlMode {
        CONTROL_NULL = 0,
        CONTROL_RUN = 1,
        CONTROL_STOP = 2,
    };

    void setMode(enmAutoRunCanoeMode eMode) { m_eAutoRunCanoeMode = eMode; }
    enmAutoRunCanoeMode getMode() { return m_eAutoRunCanoeMode; }
    void elaseExexuteAutoRunCanoe(clsAutoRunCanoe* pCanoe);

    enum enmAutoRunCanoeMode m_eAutoRunCanoeMode;      // offset 0x60, size 0x4
    hkShape* m_pcPhantomShape;                         // offset 0x64, size 0x4
    f32 m_f32MaxSpeed;                                 // offset 0x68, size 0x4
    f32 m_f32MinSpeed;                                 // offset 0x6C, size 0x4
    NNS_VECTORFAST m_sDirPosVecFast;                   // offset 0x70, size 0x10
    u32 m_u32PlayerFlg;                                // offset 0x80, size 0x4
    enum enmControlMode m_aeControlMode[8];            // offset 0x84, size 0x20
    clsGimmickAutoRunBufferBase m_cAutoRunCanoeBuffer; // offset 0xA4, size 0x1C

    static NNS_VECTORFAST m_sPlayerOffsetFast;
};

// total size: 0x200
class clsAutoRunCanoe : public clsGimmickAutoRunObj {
public:
    // Note: enmMode name collision with Game.hpp and other gimmicks - nested.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_SLEEP = 2,
    };

    // Note: enmMoveMode name collision with Taxi.hpp and other auto-run objects - nested.
    enum enmMoveMode {
        MOVEMODE_WAIT = 0,
        MOVEMODE_PASH_MOVE = 1,
        MOVEMODE_PASH_SPEED_DOWN = 2,
        MOVEMODE_PASH_WAIT = 3,
        MOVEMODE_STOP = 4,
        MOVEMODE_RETURN = 5,
        MOVEMODE_END = 6,
        MOVEMODE_RETURN_EMPTYWAIT = 7,
        MOVEMODE_EMPTYWAIT = 8,
        MOVEMODE_EMPTYWAIT_RUN = 9,
        MOVEMODE_STARTWAIT = 10,
    };

    clsAutoRunCanoe() {}
    virtual ~clsAutoRunCanoe() {}

    void draw(clsModelType_OB_TX& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 NodeStatus);
    void movePlayer() {}

    static u32 otau32Se_CanoeL[2];
    static u32 otau32Se_CanoeBreak[2];
    static u32 otau32Se_WaterStraight[2];

    enmMode m_eMode;                                       // offset 0x1C0, size 0x4
    enmMoveMode m_eMoveMode;                               // offset 0x1C4, size 0x4
    clsAutoRunCanoe_Obj* m_pcAutoRunCanoeObj;              // offset 0x1C8, size 0x4
    NNS_VECTORFAST m_sOffsetPosVedFast;                    // offset 0x1D0, size 0x10
    f32 m_f32Level;                                        // offset 0x1E0, size 0x4
    f32 m_f32MoveLRAdd;                                    // offset 0x1E4, size 0x4
    u32 m_u32WaitCount;                                    // offset 0x1E8, size 0x4
    clsMiniWaveGmkAutoRunObjEffect_Task* pcMiniWaveEffect; // offset 0x1EC, size 0x4
    f32 m_f32WaterDropFrame;                               // offset 0x1F0, size 0x4
    clsSe3DControl* m_pcSe3DControl;                       // offset 0x1F4, size 0x4
    clsPlaySe_2D* m_pcPlaySe2D;                            // offset 0x1F8, size 0x4
};

// total size: 0x98
class clsAutoRunCanoe_Task : public clsSingleModelGimmick_Task<clsAutoRunCanoe_Task,
                                                               clsAutoRunCanoe_Obj,
                                                               clsModelType_OB_TX> {
public:
    clsAutoRunCanoe_Task(u32 u32ObjectAreaNum);
    virtual ~clsAutoRunCanoe_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST04AUTORUNCANOE_HPP
