#ifndef ST04FOUNTAIN_HPP
#define ST04FOUNTAIN_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;
class clsTask;
class clsFountainThroughCollision;

enum enmFountainMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0x160
class clsFountain_Obj : public clsRigidBodyGimmickObj {
public:
    // Nested: collides with other enmMode declarations at global scope
    enum enmWaterColumnMode {
        MODE_SLEEP = 0,
        MODE_UP = 1,
        MODE_WAIT = 2,
        MODE_DOWN = 3,
    };

    clsFountain_Obj() {}
    virtual ~clsFountain_Obj() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST04_FOUNTAIN_14020;
    } // likely: return 14020
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackCrashEvent() {}

    enmFountainMode m_eMode;                    // offset 0xD0, size 0x4
    enmWaterColumnMode m_eWaterColumnMode;      // offset 0xD4, size 0x4
    u8 m_bWaterColumnDarw;                      // offset 0xD8, size 0x1
    NNS_VECTORFAST* m_opsPointVecFast;          // offset 0xDC, size 0x4
    f32 m_psMtx[4][4];                          // offset 0xE0, size 0x40
    f32 m_f32WaterColumnScale_y;                // offset 0x120, size 0x4
    f32 m_f32WaterColumnScale_xz;               // offset 0x124, size 0x4
    f32 m_f32WaterColumnFrame;                  // offset 0x128, size 0x4
    f32 m_f32UpSpeed;                           // offset 0x12C, size 0x4
    f32 m_f32DownSpeed;                         // offset 0x130, size 0x4
    u32 m_u32OldCount;                          // offset 0x134, size 0x4
    clsFountainThroughCollision* m_pcCollision; // offset 0x138, size 0x4
    hkShape* m_pcShape;                         // offset 0x13C, size 0x4
    clsSe3DControl* m_pcSe3DControl;            // offset 0x140, size 0x4
    f32 m_f32MotionFrame;                       // offset 0x144, size 0x4
    clsTask* m_psWaterParticle;                 // offset 0x148, size 0x4
    NNS_VECTORFAST m_sSetPosFast;               // offset 0x150, size 0x10

    enmWaterColumnMode getWaterColumnMode() const { return m_eWaterColumnMode; }      // likely
    void setWaterColumnMode(enmWaterColumnMode eMode) { m_eWaterColumnMode = eMode; } // likely

    static f32 tof32ClipSqDist;
};

// total size: 0x10
class clsFountainModels {
public:
    clsFountainModels() {}
    ~clsFountainModels() {}

    clsModelType_OB_TX m_cFountain;    // offset 0x0, size 0x8
    clsModelType_OB_TX m_cWaterColumn; // offset 0x8, size 0x8
};

// total size: 0xC
class clsFountainThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsFountainThroughCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    clsFountain_Obj* m_pcFountain; // offset 0x8, size 0x4
};

// total size: 0xA8
class clsFountain_Task
    : public clsBaseGimmickBody<clsFountain_Task, clsFountain_Obj, clsFountainModels> {
public:
    clsFountain_Task(u32 u32ObjectAreaNum);
    virtual ~clsFountain_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);

    f32* m_pf32TexCoordV;        // offset 0x9C, size 0x4
    f32* m_pf32TexCoordV_Under;  // offset 0xA0, size 0x4
    f32* m_pf32TexCoordV_Column; // offset 0xA4, size 0x4
};

#endif // ST04FOUNTAIN_HPP
