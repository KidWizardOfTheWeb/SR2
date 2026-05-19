#ifndef TARGETCAMCTRL_HPP
#define TARGETCAMCTRL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_CRI/PS2CriFileMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"

// total size: 0x74
struct stcTargetCam1 {
    u16 u16No;                        // offset 0x0, size 0x2
    u32 u32SetFlag;                   // offset 0x4, size 0x4
    s8* opc8Name;                     // offset 0x8, size 0x4
    NNS_VECTORFAST* opsTargetPosVF;   // offset 0xC, size 0x4
    NNS_QUATERNION* opsSurfaceQuat;   // offset 0x10, size 0x4
    f32* opf32Rad;                    // offset 0x14, size 0x4
    f32* opf32CurveRate;              // offset 0x18, size 0x4
    NNS_VECTOR sEyePosFromTgt;        // offset 0x1C, size 0xC
    f32 f32Dist;                      // offset 0x28, size 0x4
    f32 f32Height;                    // offset 0x2C, size 0x4
    f32 f32Fovy;                      // offset 0x30, size 0x4
    u8 u8IpoRot;                      // offset 0x34, size 0x1
    u8 u8IpoDir;                      // offset 0x35, size 0x1
    u8 u8IpoTra;                      // offset 0x36, size 0x1
    u8 u8IpoUp;                       // offset 0x37, size 0x1
    u32 u32Flag;                      // offset 0x38, size 0x4
    f32 f32UpVecRotDeg;               // offset 0x3C, size 0x4
    u32 u32setType;                   // offset 0x40, size 0x4
    u32 u32IpoFrame;                  // offset 0x44, size 0x4
    s32 s32AliveFrame;                // offset 0x48, size 0x4
    f32 f32YDelayRate;                // offset 0x4C, size 0x4
    u8 u8IpoTraNext;                  // offset 0x50, size 0x1
    stcInfo* opsColInfo;              // offset 0x54, size 0x4
    f32* opf32Speed;                  // offset 0x58, size 0x4
    f32* opf32MaxSpeed;               // offset 0x5C, size 0x4
    stcTargetCam1* psMaxSpeedParam;   // offset 0x60, size 0x4
    NNS_VECTORFAST* opsGravityUpVec;  // offset 0x64, size 0x4
    stcCamFilter* psCamFilter;        // offset 0x68, size 0x4
    NNS_VECTORFAST* opsTgtUpVF;       // offset 0x6C, size 0x4
    NNS_VECTORFAST* opsExternalPosVF; // offset 0x70, size 0x4
};

// total size: 0xC0
class clsTargetCam : public clsCamCtrl {
public:
    // total size: 0x30
    struct stcSpeedMixParam {
        f32 f32HeightFromTgt;     // offset 0x0, size 0x4
        f32 f32Dist;              // offset 0x4, size 0x4
        f32 f32Fovy;              // offset 0x8, size 0x4
        f32 f32IpoRot;            // offset 0xC, size 0x4
        f32 f32IpoDir;            // offset 0x10, size 0x4
        f32 f32IpoTra;            // offset 0x14, size 0x4
        f32 f32IpoUp;             // offset 0x18, size 0x4
        NNS_VECTORFAST sEyeTgtVF; // offset 0x20, size 0x10
    };

    NNS_VECTORFAST* m_opsTgtPosVF;       // offset 0x1C, size 0x4
    NNS_QUATERNION* m_opsSlerpQuat;      // offset 0x20, size 0x4
    f32* m_opf32Rad;                     // offset 0x24, size 0x4
    f32* m_opf32CurveRate;               // offset 0x28, size 0x4
    stcInfo* m_opsColInfo;               // offset 0x2C, size 0x4
    f32* m_opf32Speed;                   // offset 0x30, size 0x4
    NNS_VECTORFAST* m_opsGravityUpVF;    // offset 0x34, size 0x4
    NNS_VECTORFAST* m_opsExTargetPosVF;  // offset 0x38, size 0x4
    f32* m_opf32MaxSpeed;                // offset 0x3C, size 0x4
    NNS_VECTORFAST m_sTgtBeforePosVF;    // offset 0x40, size 0x10
    NNS_VECTORFAST m_sAdjustBeforePosVF; // offset 0x50, size 0x10
    f32 m_f32BeforeRad;                  // offset 0x60, size 0x4
    f32 m_f32BeforeDir;                  // offset 0x64, size 0x4
    f32 m_f32BeforeCurveRate;            // offset 0x68, size 0x4
    NNS_VECTORFAST m_sEyeTgtVF;          // offset 0x70, size 0x10
    f32 m_f32Dist;                       // offset 0x80, size 0x4
    f32 m_f32HeightFromTgt;              // offset 0x84, size 0x4
    f32 m_f32Fovy;                       // offset 0x88, size 0x4
    u8 m_u8IpoDir;                       // offset 0x8C, size 0x1
    u8 m_u8IpoRot;                       // offset 0x8D, size 0x1
    u8 m_u8IpoTra;                       // offset 0x8E, size 0x1
    u8 m_u8IpoUp;                        // offset 0x8F, size 0x1
    u32 m_u32Flag;                       // offset 0x90, size 0x4
    u32 m_u32CurveCnt;                   // offset 0x94, size 0x4
    f32 m_f32CurveDeg;                   // offset 0x98, size 0x4
    f32 m_f32CurveRad;                   // offset 0x9C, size 0x4
    u16 m_u16ZRotRate;                   // offset 0xA0, size 0x2
    u8 m_u8KickerFovyCnt;                // offset 0xA2, size 0x1
    f32 m_f32YDelayRate;                 // offset 0xA4, size 0x4
    stcTargetCam1* m_psMaxSpeedParam;    // offset 0xA8, size 0x4
    stcCamFilter* m_psCamFilter;         // offset 0xAC, size 0x4
    NNS_VECTORFAST* m_opsTgtUpVF;        // offset 0xB0, size 0x4
    u8 m_u8IpoTraNext;                   // offset 0xB4, size 0x1

    virtual ~clsTargetCam() {}
    virtual u32 getControlType() const { return 10; } // likely: return 10;
    virtual u32 execute(clsPfCamera* a, const clsPfCamera* b);
    virtual void startMixing();
    virtual void resetData();
    virtual void setParams(void* p);
    virtual void getParams(void* p);

    void adjustMaxSpeed(stcSpeedMixParam* p);
};

#endif // TARGETCAMCTRL_HPP
