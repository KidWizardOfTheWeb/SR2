#ifndef SRCAMCTRL_HPP
#define SRCAMCTRL_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2CamCtrl.hpp"

// total size: 0x10
struct stcSetTbl {
    u32 u32JmpIdx;    // offset 0x0, size 0x4
    u32 u32TblIdx;    // offset 0x4, size 0x4
    u32 u32Num;       // offset 0x8, size 0x4
    u32 u32CurJmpIdx; // offset 0xC, size 0x4
};

// total size: 0x3C
struct stcCamFilter {
    NNS_VECTOR sTargetV; // offset 0x0, size 0xC
    NNS_VECTOR sPosV;    // offset 0xC, size 0xC
    f32 f32Fovy;         // offset 0x18, size 0x4
    s8 s8IpoRot;         // offset 0x1C, size 0x1
    s8 s8IpoDir;         // offset 0x1D, size 0x1
    s8 s8IpoTra;         // offset 0x1E, size 0x1
    s8 s8IpoUp;          // offset 0x1F, size 0x1
    u32 u32Flag;         // offset 0x20, size 0x4
    f32 f32YDelayRate;   // offset 0x24, size 0x4
    f32 f32ChangeFrame;  // offset 0x28, size 0x4
    f32 f32AliveFrame;   // offset 0x2C, size 0x4
    f32 f32FinishFrame;  // offset 0x30, size 0x4
    u32 u32FuncIdx;      // offset 0x34, size 0x4
    u32 u32FParamIdx;    // offset 0x38, size 0x4
};

// total size: 0x1C
struct stcPlayerQuakeFilter {
    NNS_VECTOR sMaxRangePosV; // offset 0x0, size 0xC
    NNS_VECTOR sMaxRangeTgtV; // offset 0xC, size 0xC
    u8 u8Speed;               // offset 0x18, size 0x1
};

// total size: 0x50
struct stcGctrlCam1 {
    u16 u16No;                       // offset 0x0, size 0x2
    c8* opc8Name;                    // offset 0x4, size 0x4
    NNS_VECTORFAST* opsTargetPosVF;  // offset 0x8, size 0x4
    f32* opf32RadX;                  // offset 0xC, size 0x4
    f32* opf32RadY;                  // offset 0x10, size 0x4
    NNS_QUATERNION* opsVelocityQ;    // offset 0x14, size 0x4
    NNS_VECTOR sEyePosFromTgt;       // offset 0x18, size 0xC
    f32 f32Dist;                     // offset 0x24, size 0x4
    f32 f32Height;                   // offset 0x28, size 0x4
    f32 f32Fovy;                     // offset 0x2C, size 0x4
    u32 u32EyeTgtIpoFrame;           // offset 0x30, size 0x4
    u32 u32setType;                  // offset 0x34, size 0x4
    u32 u32IpoFrame;                 // offset 0x38, size 0x4
    s32 s32AliveFrame;               // offset 0x3C, size 0x4
    f32 f32CurveRad;                 // offset 0x40, size 0x4
    f32 f32CurveDeg;                 // offset 0x44, size 0x4
    NNS_VECTORFAST* opsGravityUpVec; // offset 0x48, size 0x4
    stcCamFilter* psCamFilter;       // offset 0x4C, size 0x4
};

// total size: 0x38
struct stcDomeCam1 {
    u16 u16No;                      // offset 0x0, size 0x2
    c8* opc8Name;                   // offset 0x4, size 0x4
    NNS_VECTORFAST* opsTargetPosVF; // offset 0x8, size 0x4
    f32 (*opsPosturalMtx)[4][4];    // offset 0xC, size 0x4
    f32 f32Dist;                    // offset 0x10, size 0x4
    s32 s32RotX;                    // offset 0x14, size 0x4
    s32 s32RotY;                    // offset 0x18, size 0x4
    s32 s32Fovy;                    // offset 0x1C, size 0x4
    u32 u32IpoFrame;                // offset 0x20, size 0x4
    s32 s32AliveFrame;              // offset 0x24, size 0x4
    NNS_VECTOR sUpVec;              // offset 0x28, size 0xC
    stcCamFilter* psCamFilter;      // offset 0x34, size 0x4
};

// total size: 0x28
struct stcPathCam1 {
    u16 u16No;                    // offset 0x0, size 0x2
    c8* opc8Name;                 // offset 0x4, size 0x4
    NNS_VECTORFAST* opsAdjustPos; // offset 0x8, size 0x4
    u32 u32PathType;              // offset 0xC, size 0x4
    s32 s32LineNo;                // offset 0x10, size 0x4
    f32 f32Speed;                 // offset 0x14, size 0x4
    u32* pu32ActType;             // offset 0x18, size 0x4
    u32 u32Flag;                  // offset 0x1C, size 0x4
    f32 f32IpoTime;               // offset 0x20, size 0x4
    f32 f32AliveTime;             // offset 0x24, size 0x4
};

// total size: 0x70
struct stcVectorCam1 {
    u16 u16No;                      // offset 0x0, size 0x2
    c8* opc8Name;                   // offset 0x4, size 0x4
    NNS_VECTORFAST* opsTargetPosVF; // offset 0x8, size 0x4
    NNS_VECTORFAST sStartPos;       // offset 0x10, size 0x10
    NNS_VECTORFAST sEndPos;         // offset 0x20, size 0x10
    NNS_VECTORFAST sUpVF;           // offset 0x30, size 0x10
    NNS_VECTORFAST sEndUpVF;        // offset 0x40, size 0x10
    f32 f32Distance;                // offset 0x50, size 0x4
    s32 s32Fovy;                    // offset 0x54, size 0x4
    u32 u32IpoFrame;                // offset 0x58, size 0x4
    s32 s32AliveFrame;              // offset 0x5C, size 0x4
    u32 u32SetFlag;                 // offset 0x60, size 0x4
    stcCamFilter* psCamFilter;      // offset 0x64, size 0x4
    f32 (*opsPosturalMtx)[4][4];    // offset 0x68, size 0x4
};

// total size: 0xF750
class clsSrCamMixer : public clsCamMixer {
public:
    virtual ~clsSrCamMixer() {}
    virtual void mixing();
    virtual void setCamCtrlTbl(u32 u32JmpIdx, u32 u32Num, u8 u8NextFlg);
    virtual void nextMixData();
    virtual void finishMixing();

    void finishFilter();
    void setRegularFilter(stcCamFilter* psFilter);
    void clearCamFilter();
    void setCamFilter(const stcCamFilter* opsCamFilter, u32 u32Idx);
    void mixingFilter();
    clsSrCamMixer();

    stcSetTbl m_asSetTbl[2];        // offset 0xF5D0, size 0x20
    u32 m_u32MaxParamIdx;           // offset 0xF5F0, size 0x4
    f32 m_f32GcRad;                 // offset 0xF5F4, size 0x4
    NNS_QUATERNION m_sSurfaceQuat;  // offset 0xF5F8, size 0x10
    u8 m_u8FilterActive;            // offset 0xF608, size 0x1
    u8 m_u8RegularFilterActive;     // offset 0xF609, size 0x1
    stcCamFilter m_asCamFilter[2];  // offset 0xF60C, size 0x78
    u32 m_au32FilterIdx[2];         // offset 0xF684, size 0x8
    stcCamFilter m_sMixedCamFilter; // offset 0xF68C, size 0x3C
    stcCamFilter m_sRegularFilter;  // offset 0xF6C8, size 0x3C
    stcCamFilter m_sZeroFilter;     // offset 0xF704, size 0x3C
    f32 m_f32ZeroFilterFrame;       // offset 0xF740, size 0x4
};

// total size: 0x10
struct stcCamCtrlJumpTbl {
    u32 u32CamCtrlType; // offset 0x0, size 0x4
    u32 u32TblIdx;      // offset 0x4, size 0x4
    u16 u16Pri;         // offset 0x8, size 0x2
    u32 u32CamIvType;   // offset 0xC, size 0x4
};

#endif // SRCAMCTRL_HPP
