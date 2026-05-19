#ifndef PARTICLEBASE_HPP
#define PARTICLEBASE_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "types.h"

// total size: 0x20
struct stcParticleExtensionData {
    NNS_VECTORFAST sPosVecFast;    // offset 0x0, size 0x10
    NNS_VECTORFAST sRamPosVecFast; // offset 0x10, size 0x10
};

// total size: 0x60
struct stcParticleDetail {
    NNS_VECTORFAST sPosFast;      // offset 0x0, size 0x10
    NNS_VECTORFAST sVelocityFast; // offset 0x10, size 0x10
    NNS_RGBA sRGBA;               // offset 0x20, size 0x10
    u32 u32RGBA;                  // offset 0x30, size 0x4
    s16 s16LiveFrame;             // offset 0x34, size 0x2
    s16 s16Loops;                 // offset 0x36, size 0x2
    s16 s16EndFrame;              // offset 0x38, size 0x2
    f32 f32HalfSizeX;             // offset 0x3C, size 0x4
    f32 f32HalfSizeY;             // offset 0x40, size 0x4
    f32 f32HalfSizeZ;             // offset 0x44, size 0x4
    NNS_ROTATE_A32 sRotA32;       // offset 0x48, size 0xC
    NNS_ROTATE_A32 sRotSpeedA32;  // offset 0x54, size 0xC
};

// total size: 0x80
struct stcParticleData {
    u16 u16CtrlFlag;            // offset 0x0, size 0x2
    u8 u8DrawType;              // offset 0x2, size 0x1
    u8 u8CtrlType;              // offset 0x3, size 0x1
    u8 u8BlendMode;             // offset 0x4, size 0x1
    u8 u8TextureNo;             // offset 0x5, size 0x1
    u16 u16Num;                 // offset 0x6, size 0x2
    NNS_VECTOR sSize;           // offset 0x8, size 0xC
    u8 u8RandAppear;            // offset 0x14, size 0x1
    u8 u8Pad1;                  // offset 0x15, size 0x1
    u16 u16Pad2;                // offset 0x16, size 0x2
    f32 f32Speed;               // offset 0x18, size 0x4
    NNS_VECTOR sRandSpeed;      // offset 0x1C, size 0xC
    f32 f32Gravitation;         // offset 0x28, size 0x4
    f32 f32ClipDist;            // offset 0x2C, size 0x4
    s16 s16LiveFrame;           // offset 0x30, size 0x2
    s16 s16Loops;               // offset 0x32, size 0x2
    NNS_RGBA sStartRGBA;        // offset 0x34, size 0x10
    NNS_RGBA sEndRGBA;          // offset 0x44, size 0x10
    NNS_VECTOR sRandSize;       // offset 0x54, size 0xC
    NNS_ROTATE_A32 sRotA32;     // offset 0x60, size 0xC
    NNS_ROTATE_A32 sRotRandA32; // offset 0x6C, size 0xC
    f32 f32SpeedScale;          // offset 0x78, size 0x4
    f32 f32EndSizeX;            // offset 0x7C, size 0x4
};

// total size: 0x130
class clsParticleBase : public clsTask {
public:
    virtual ~clsParticleBase() {}
    virtual void execute();
    virtual void draw();
    virtual void setCreatedSeparate(NNS_VECTORFAST* param_1,
                                    stcParticleDetail* param_2,
                                    bool param_3,
                                    stcParticleExtensionData* param_4,
                                    u32 param_5)
    {
    }
    virtual void moveCalc(NNS_VECTORFAST* param_1,
                          stcParticleDetail* param_2,
                          stcParticleExtensionData* param_3,
                          f32 param_4,
                          const f32 (*param_5)[4][4],
                          bool param_6)
    {
    }

    void drawBase();
    void moveBase();

    // Inline utility functions
    u8 checkBits(u16 param_1, u16 param_2) { return 0; }
    void setTransrateMtx(f32 (*param_1)[4][4], stcParticleDetail* param_2) {}
    u8 checkClip(u32 param_1) { return 0; }

    clsParticleBase(u8 param_1,
                    const u16* param_2,
                    stcParticleData* param_3,
                    const NNS_VECTORFAST* param_4,
                    const NNS_VECTORFAST* param_5,
                    const NNS_VECTOR* param_6,
                    const NNS_VECTOR* param_7,
                    const NNS_VECTOR* param_8,
                    const f32 (*param_9)[4][4],
                    const NNS_VECTORFAST* param_10,
                    const _NNS_TEXLIST* param_11,
                    u8 param_12,
                    f32 param_13,
                    f32 param_14,
                    s32 param_15)
        : clsTask(0, 0)
    {
    }

    // Inline draw sub-functions (statics defined locally in each body)
    void drawTryangle() {}
    void drawPolygon() {}
    void drawUnBillPolygon() {}
    void drawTryangle2D() {}
    void drawPolygon2D() {}
    void drawDiamond() {}
    void drawLine() {}

    NNS_VECTORFAST m_sPosFast;          // offset 0x60, size 0x10
    NNS_VECTORFAST m_sBasePosFast;      // offset 0x70, size 0x10
    f32 m_sPosturMatrix[4][4];          // offset 0x80, size 0x40
    NNS_RGBA m_sLinearDiffRGBA;         // offset 0xC0, size 0x10
    NNS_RGBA m_sStartRGBA;              // offset 0xD0, size 0x10
    NNS_VECTOR m_sLinearDiffScale;      // offset 0xE0, size 0xC
    u16 m_u16DeadNum;                   // offset 0xEC, size 0x2
    stcParticleDetail* m_psDetailHi;    // offset 0xF0, size 0x4
    stcParticleData* m_psDefData;       // offset 0xF4, size 0x4
    NNS_VECTORFAST* m_opsFollowPosFast; // offset 0xF8, size 0x4
    NNS_VECTORFAST* m_opsRelatePosFast; // offset 0xFC, size 0x4
    _NNS_TEXLIST* m_opsTexList;         // offset 0x100, size 0x4
    f32 (*m_opsFollowMtx)[4][4];        // offset 0x104
    NNS_VECTORFAST* m_opsStartVecFast;  // offset 0x108, size 0x4
    u8 m_u8ParticleType;                // offset 0x10C, size 0x1
    u8 m_u8ViewportNo;                  // offset 0x10D, size 0x1
    NNS_VECTOR* m_opsCenterPosVec;      // offset 0x110, size 0x4
    NNS_VECTOR* m_opsStartRange;        // offset 0x114, size 0x4
    f32 m_f32EndSizeY;                  // offset 0x118, size 0x4
    f32 m_f32EndSizeZ;                  // offset 0x11C, size 0x4
    s32 m_s32EndFrame;                  // offset 0x120, size 0x4
    u16* m_pu16StopCode;                // offset 0x124, size 0x4
};

#endif // PARTICLEBASE_HPP
