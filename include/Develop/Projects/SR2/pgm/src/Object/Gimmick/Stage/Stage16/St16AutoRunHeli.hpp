#ifndef ST16AUTORUNHELI_HPP
#define ST16AUTORUNHELI_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08UfoCatcher.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/PendulumControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/SlerpQuat.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Macross.hpp"

class clsAutoRunHeli_Obj;

// total size: 0x18
class clsAutoRunHeliModel {
public:
    clsAutoRunHeliModel() {}
    ~clsAutoRunHeliModel() {}

    clsModelType_OB_TX_MO m_cModelHeli; // offset 0x0, size 0x10
    clsModelType_OB_TX m_cModelRope;    // offset 0x10, size 0x8
};

class clsPendulumControl;
class clsPlayerTask;

// total size: 0x250
class clsAutoRunHeli : public clsGimmickAutoRunObj {
public:
    clsAutoRunHeli() {}
    virtual ~clsAutoRunHeli() { destroy(); }
    virtual void destroy()
    {
        delete m_pcPendulumControl;
        m_pcPendulumControl = NULL;
        delete m_pcSe3DControl;
        m_pcSe3DControl = NULL;
    }
    // RECONSTRUCTED: enum scope.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };
    // RECONSTRUCTED: enum scope.
    enum enmMoveMode {
        MOVEMODE_WAIT = 0,
        MOVEMODE_MOVE = 1,
        MOVEMODE_STOP = 2,
        MOVEMODE_RETURN = 3,
        MOVEMODE_END = 4,
        MOVEMODE_EMPTYWAIT = 5,
        MOVEMODE_EMPTYWAIT_RUN = 6,
        MOVEMODE_STARTWAIT = 7,
    };

    enmMode m_eMode;                         // offset 0x1C0, size 0x4
    enmMoveMode m_eMoveMode;                 // offset 0x1C4, size 0x4
    clsAutoRunHeli_Obj* m_pcHeliObj;         // offset 0x1C8, size 0x4
    f32 m_f32InterpolateFrame;               // offset 0x1CC, size 0x4
    f32 m_f32EffectFrame;                    // offset 0x1D0, size 0x4
    clsPendulumControl* m_pcPendulumControl; // offset 0x1D4, size 0x4
    f32 m_f32AirMove;                        // offset 0x1D8, size 0x4
    NNS_QUATERNION m_sRopeRotQuat;           // offset 0x1DC, size 0x10
    clsSe3DControl* m_pcSe3DControl;         // offset 0x1EC, size 0x4
    clsSlerpQuat m_SlerpQuat;                // offset 0x1F0, size 0x3C
    f32 m_f32AccelFrame;                     // offset 0x22C, size 0x4
    f32 m_f32Accel;                          // offset 0x230, size 0x4
    u8 m_bIsCatch;                           // offset 0x234, size 0x1
    u8 m_bLight;                             // offset 0x235, size 0x1
    f32 m_f32EffectCnt;                      // offset 0x238, size 0x4
    NNS_VECTORFAST m_sEffectPos;             // offset 0x240, size 0x10

    static f32 m_tof32CLIP_DISTx2;

    virtual void setStartWait(clsAutoRunHeli_Obj* pcObj);
    virtual void start(clsPlayerTask* pcPlayerTask, clsAutoRunHeli_Obj* pcObj);
    virtual u8 movePath(bool bFunc);
    virtual void getPathRotQuat(NNS_QUATERNION& rsRotQuat);
    virtual void getEffectPosVecFast(NNS_VECTORFAST& rsPosVecFast);
    virtual void execute();
    virtual u8 draw(clsAutoRunHeliModel& rcModel,
                    NNS_MATRIX* psMtxPal,
                    u32* psNodeStat,
                    const NNS_MATRIX* opaNnViewMtx,
                    NNS_MATRIX* psMtxWork,
                    u32 u32ViewNo,
                    u32 NodeStatus);

    void setMoveMode(enmMoveMode eMode) { m_eMoveMode = eMode; }
    enmMoveMode getMoveMode() const { return m_eMoveMode; }
};

// total size: 0xB0
class clsAutoRunHeli_Obj : public clsPhantomGimmickObject {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmCtrlMode {
        CTRL_NULL = 0,
        CTRL_RUN = 1,
        CTRL_STOP = 2,
    };

    clsAutoRunHeli_Obj() : clsPhantomGimmickObject(), m_eMode(MODE_INIT)
    {
        memset(m_aeCtrlMode, 0, sizeof(m_aeCtrlMode));
    }
    virtual ~clsAutoRunHeli_Obj() { destroyData(); }

    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST16_AUTORUN_HELI_26030; }

    void init();
    void reset();
    clsAutoRunHeli* getMoveModeCmp(clsAutoRunHeli::enmMoveMode eMoveMode);
    void controlPlayer() {}

    void setMode(enmMode eMode) { m_eMode = eMode; }
    enmMode getMode() const { return m_eMode; }
    f32 getSpeed() const { return m_sScaleVec.x; }
    f32 getStartSpeed() const { return m_sScaleVec.y; }
    f32 getAccelFrame() const { return m_sScaleVec.z; }

    enmMode m_eMode;                                       // offset 0x60, size 0x4
    clsGimmickAutoRunBuffer<clsAutoRunHeli> m_cHeliBuffer; // offset 0x64, size 0x1C
    enmCtrlMode m_aeCtrlMode[8];                           // offset 0x80, size 0x20
    NNS_VECTORFAST m_sDirPosVecFast;                       // offset 0xA0, size 0x10
};

class clsAutoRunHeli_Task
    : public clsBaseGimmickBody<clsAutoRunHeli_Task, clsAutoRunHeli_Obj, clsAutoRunHeliModel> {
public:
    clsAutoRunHeli_Task(u32 u32ObjectAreaNum)
        : clsBaseGimmickBody<clsAutoRunHeli_Task, clsAutoRunHeli_Obj, clsAutoRunHeliModel>(
              u32ObjectAreaNum, 100099),
          m_pA32Rot(NULL), m_f32AirCnt(0.0f)
    {
        hkVector4 cBox(15.0f, 10.0f, 4.0f, 0.0f);
        m_pcPhantomShape = new hkBoxShape(cBox, hkConvexShapeDefaultRadius);
    }
    virtual ~clsAutoRunHeli_Task();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
    virtual void execute();
    virtual void draw();

    clsMacrossThroughCollision m_cThroughCollision; // offset 0xA4, size 0x8
    NNS_ROTATE_A32* m_pA32Rot;                      // offset 0xAC, size 0x4
    f32 m_f32AirCnt;                                // offset 0xB0, size 0x4
};

#endif // ST16AUTORUNHELI_HPP
