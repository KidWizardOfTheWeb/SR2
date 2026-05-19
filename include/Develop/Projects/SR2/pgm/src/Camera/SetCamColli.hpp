#ifndef SETCAMCOLLI_HPP
#define SETCAMCOLLI_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsPlayerTask;
class hkBoxShape;
class hkSphereShape;

enum enmSetCamColliMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_SLEEP = 2,
};

enum enmSCamType {
    SCAM_TYPE_LOOKTGT = 0,
    SCAM_TYPE_CHGMAXSPEED = 1,
    SCAM_TYPE_DOMEPLAYER = 2,
    SCAM_TYPE_CHGCAMERA = 3,
    SCAM_TYPE_VECTORCAMERA = 4,
    SCAM_TYPE_PATHCAMERA = 5,
    SCAM_TYPE_FILTER = 6,
    SCAM_TYPE_CLEAR = 7,
    SCAM_TYPE_MAX = 8,
};

enum enmSCamShapeType {
    SCAM_SHAPE_SPHERE = 0,
    SCAM_SHAPE_BOX = 1,
};

// total size: 0x44
struct stcBaseSetCam {
    s8* opcName;                 // offset 0x0, size 0x4
    u8 bIsEnable;                // offset 0x4, size 0x1
    u8 u8IsReplay;               // offset 0x5, size 0x1
    NNS_VECTOR sPos;             // offset 0x8, size 0xC
    NNS_VECTOR sRotZXYRad;       // offset 0x14, size 0xC
    NNS_VECTOR sScale;           // offset 0x20, size 0xC
    s32 s32Fovy;                 // offset 0x2C, size 0x4
    enmSCamType eSetCamType;     // offset 0x30, size 0x4
    enmSCamShapeType eShapeType; // offset 0x34, size 0x4
    u32 u32ActiveType;           // offset 0x38, size 0x4
    u32 u32CamIdx;               // offset 0x3C, size 0x4
    u32 u32PlayerActType;        // offset 0x40, size 0x4
};

namespace nspSetCam {
// total size: 0x34
struct stcSCamLookPlayer {
    NNS_VECTOR sCamPos;      // offset 0x0, size 0xC
    u32 u32TgtCamTblIdx;     // offset 0xC, size 0x4
    s32 s32RotX;             // offset 0x10, size 0x4
    s32 s32RotY;             // offset 0x14, size 0x4
    f32 f32Dist;             // offset 0x18, size 0x4
    s32 s32IpoFrame;         // offset 0x1C, size 0x4
    s32 s32AliveFrame;       // offset 0x20, size 0x4
    u32 u32InMaxSpeedTblIdx; // offset 0x24, size 0x4
    NNS_VECTOR sUpVec;       // offset 0x28, size 0xC
};

// total size: 0x50
struct stcSCamVector {
    NNS_VECTORFAST sStartPos; // offset 0x0, size 0x10
    NNS_VECTORFAST sEndPos;   // offset 0x10, size 0x10
    NNS_VECTORFAST sUpVF;     // offset 0x20, size 0x10
    NNS_VECTORFAST sEndUpVF;  // offset 0x30, size 0x10
    f32 f32Distance;          // offset 0x40, size 0x4
    u32 u32IpoFrame;          // offset 0x44, size 0x4
    s32 s32AliveFrame;        // offset 0x48, size 0x4
};
} // namespace nspSetCam

// total size: 0x50
class clsSetCamColli_Obj : public clsBaseThroughCollision {
public:
    clsSetCamColli_Obj() {}
    virtual ~clsSetCamColli_Obj() {}

    virtual void init();
    virtual void execute();
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactAlwaysEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);

    hkBoxShape* m_pcBoxShape;       // offset 0x8, size 0x4
    hkSphereShape* m_pcSphereShape; // offset 0xC, size 0x4
    enmSetCamColliMode m_eMode;     // offset 0x10, size 0x4
    NNS_VECTORFAST m_sPosVF;        // offset 0x20, size 0x10
    NNS_QUATERNION m_sQuat;         // offset 0x30, size 0x10
    s32 m_s32SetNo;                 // offset 0x40, size 0x4
    u32 m_u32BaseParamIdx;          // offset 0x44, size 0x4
    stcBaseSetCam* m_psBaseParam;   // offset 0x48, size 0x4
};

// total size: 0x2AC
class clsSetCamColli_Task : public clsSingleton<clsSetCamColli_Task>, public clsTask {
public:
    clsSetCamColli_Task();
    virtual ~clsSetCamColli_Task();

    virtual void execute();
    virtual void draw();

    NNS_VECTOR m_vecpcSCamObj;          // offset 0x58, size 0xC
    clsSetCamColli_Obj* m_pcDeleteAddr; // offset 0x64, size 0x4
    u32 m_u32Used;                      // offset 0x68, size 0x4
    NNS_VECTOR m_avecLookPlayer[16];    // offset 0x6C, size 0xC0
    NNS_VECTOR m_avecSCamVector[16];    // offset 0x12C, size 0xC0
    NNS_VECTOR m_avecCamFilter[16];     // offset 0x1EC, size 0xC0
};

#endif // SETCAMCOLLI_HPP
