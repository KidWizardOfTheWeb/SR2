#ifndef GCTRLCAMCTRL_HPP
#define GCTRLCAMCTRL_HPP

#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2CamCtrl.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPfCamera;

class clsGctrlCam : public clsCamCtrl {
public:
    virtual ~clsGctrlCam();
    virtual u32 getControlType() const;
    virtual u32 execute(clsPfCamera* pcCamera, const clsPfCamera* pParam2);
    virtual void resetData();
    virtual void setParams(void* vpParams);
    virtual void getParams(void* vpParams);

    // Members
    NNS_VECTORFAST* m_opsTgtPosVF;  // offset 0x1C, size 0x4
    NNS_QUATERNION* m_opsVelocityQ; // offset 0x20, size 0x4
    NNS_VECTORFAST* m_opsUpVF;      // offset 0x24, size 0x4
    f32* m_opf32RadX;               // offset 0x28, size 0x4
    f32* m_opf32RadY;               // offset 0x2C, size 0x4
    f32* m_opf32CurveRate;          // offset 0x30, size 0x4
    f32 m_f32BeforeRadX;            // offset 0x34, size 0x4
    f32 m_f32BeforeRadY;            // offset 0x38, size 0x4
    f32 m_f32BeforeRadY2;           // offset 0x3C, size 0x4
    NNS_VECTORFAST m_sEyeTgtVF;     // offset 0x40, size 0x10
    f32 m_f32Dist;                  // offset 0x50, size 0x4
    f32 m_f32HeightFromTgt;         // offset 0x54, size 0x4
    f32 m_f32Fovy;                  // offset 0x58, size 0x4
    u8 m_u8IpoDir;                  // offset 0x5C, size 0x1
    u8 m_u8IpoRot;                  // offset 0x5D, size 0x1
    u8 m_u8IpoTra;                  // offset 0x5E, size 0x1
    u8 m_u8IpoUp;                   // offset 0x5F, size 0x1
    u32 m_u32Flag;                  // offset 0x60, size 0x4
    u16 m_u16Mode;                  // offset 0x64, size 0x2
    u16 m_u16IpoStart;              // offset 0x66, size 0x2
    f32 m_f32CurveRad;              // offset 0x68, size 0x4
    f32 m_f32CurveDeg;              // offset 0x6C, size 0x4
    u8 m_u8KeyDiff;                 // offset 0x70, size 0x1
    u32 m_u32EyeTgtIpoFrame;        // offset 0x74, size 0x4
    u32 m_u32EyeTgtIpoTime;         // offset 0x78, size 0x4
};

#endif // GCTRLCAMCTRL_HPP
