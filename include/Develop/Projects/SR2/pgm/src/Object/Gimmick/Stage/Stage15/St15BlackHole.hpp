#ifndef ST15BLACKHOLE_HPP
#define ST15BLACKHOLE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Postural.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsBlackHoleModel;
class clsPfCameraMgr;
class clsPfFog;
class clsPfSystem;
class clsPlayerGravityWave_Task;
class clsTaskManager;
class clsPathData;

// Enum used by clsBlackHole_Obj and clsBlackHole_Task
enum enmBlackHoleMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_STANDBY = 2,
    MODE_MAIN_AND_EFFECT = 3,
    MODE_MAIN = 4,
    MODE_FADE = 5,
    MODE_RESTART_WAIT = 6,
};

// total size: 0x430
class clsBlackHole_Obj : public clsGimmickObj {
public:
    clsBlackHole_Obj() {}
    virtual ~clsBlackHole_Obj() {}

    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_BLACK_HOLE_25050; }

    enmBlackHoleMode getMode() { return m_eBlackHoleMode; }
    clsPath& getPathRef() { return m_cPath; }
    void reset() {}
    void update() {}
    s32 getNo() { return m_s32No; }
    void setMode(enmBlackHoleMode eMode) { m_eBlackHoleMode = eMode; }

    clsPath m_cPath;                   // offset 0x50, size 0x60
    clsPosturalCtrl m_cPostural;       // offset 0xB0, size 0xB0
    enmBlackHoleMode m_eBlackHoleMode; // offset 0x160, size 0x4
    f32 m_f32MotionFrame;              // offset 0x164, size 0x4
    f32 m_f32MatMotionFrame;           // offset 0x168, size 0x4
    f32 m_f32Count;                    // offset 0x16C, size 0x4
    s32 m_s32No;                       // offset 0x170, size 0x4
    clsPath m_cSubPath;                // offset 0x180, size 0x60
    NNS_VECTORFAST m_asPosVecFast[3];  // offset 0x1E0, size 0x30
    clsPosturalCtrl m_acPostural[3];   // offset 0x210, size 0x210
    u32 m_au32PointNo[3];              // offset 0x420, size 0xC
    f32 m_f32Scale;                    // offset 0x42C, size 0x4
};

// total size: 0xBC
class clsBlackHole_Task : public clsSingleModelGimmick_Task<clsBlackHole_Task,
                                                            clsBlackHole_Obj,
                                                            clsModelType_OB_TX_MO_MA>,
                          public clsGimmickCommon {
public:
    clsBlackHole_Task(u32 u32ObjectAreaNum);
    virtual ~clsBlackHole_Task() {}

    u8 m_bEnableDebug;      // offset 0xAD, size 0x1
    u8 m_bDisp;             // offset 0xAE, size 0x1
    f32 m_f32DebugDistance; // offset 0xB0, size 0x4
    f32 m_f32DebugOffsetY;  // offset 0xB4, size 0x4
    u8 m_bInitFlag;         // offset 0xB8, size 0x1

    virtual void reset();
    virtual void execute();
    virtual void draw();
    virtual void setBlackHole();
    virtual void endBlackHole();
};

#endif // ST15BLACKHOLE_HPP
