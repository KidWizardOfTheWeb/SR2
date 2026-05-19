#ifndef MINIWAVE_HPP
#define MINIWAVE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/CharaData.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

class clsPlayerTask;
class clsPlaySe_2D;

namespace nspMiniWave {
extern _NNS_TEXLIST* psTexList_MiniWave;
}

// total size: 0x24
struct stcMiniWaveParam {
    f32 f32UVSpeed;          // offset 0x0, size 0x4
    f32 f32StartWidth;       // offset 0x4, size 0x4
    f32 f32EndWidth;         // offset 0x8, size 0x4
    f32 f32MaxWidth;         // offset 0xC, size 0x4
    f32 f32BackLength;       // offset 0x10, size 0x4
    f32 f32ReviseValIn;      // offset 0x14, size 0x4
    f32 f32ReviseValOut;     // offset 0x18, size 0x4
    f32 f32CurveMax;         // offset 0x1C, size 0x4
    f32 f32InclinationAngle; // offset 0x20, size 0x4
};

// total size: 0xD00
class clsMiniWaveEffect_Task : public clsTask {
public:
    NNS_PRIM3D_PCT m_asPrim3D_PCT[40];        // offset 0x54, size 0x3C0
    NNS_PRIM3D_PCT m_asPrim3D_L_PCT[40];      // offset 0x414, size 0x3C0
    NNS_PRIM3D_PCT m_asPrim3D_R_PCT[40];      // offset 0x7D4, size 0x3C0
    f32 m_sVelocityMtxPtr[4][4];              // offset 0xBA0, size 0x40
    f32 m_sPosturalMtxPtr[4][4];              // offset 0xBE0, size 0x40
    NNS_VECTORFAST m_sPosVecFast;             // offset 0xC20, size 0x10
    NNS_VECTORFAST m_asEffectLocalVecFast[2]; // offset 0xC30, size 0x20
    NNS_VECTORFAST m_asEffectPosVecFast[5];   // offset 0xC50, size 0x50
    f32 m_f32AnmStart;                        // offset 0xCA0, size 0x4
    f32 m_f32Distance;                        // offset 0xCA4, size 0x4
    f32 m_f32Speed;                           // offset 0xCA8, size 0x4
    f32 m_f32Curve;                           // offset 0xCAC, size 0x4
    s8 m_s8Cnt;                               // offset 0xCB0, size 0x1
    s8 m_s8BackCnt;                           // offset 0xCB1, size 0x1
    u8 m_u8GetData;                           // offset 0xCB2, size 0x1
    u8 m_u8TexType;                           // offset 0xCB3, size 0x1
    u8 m_eMiniWaveAttr;                       // offset 0xCB4, size 0x1
    u32 m_u32DataNo;                          // offset 0xCB8, size 0x4
    u32 m_u32ViewNo;                          // offset 0xCBC, size 0x4
    u8 m_u8PlayerNo;                          // offset 0xCC0, size 0x1
    u8 m_u8EffectNo;                          // offset 0xCC1, size 0x1
    clsPlayerTask* m_pcPlayer;                // offset 0xCC4, size 0x4
    clsPlaySe_2D* m_cPlaySe2d[2];             // offset 0xCC8, size 0x8
    stcMiniWaveParam sMiniWaveParam;          // offset 0xCD0, size 0x24

    clsMiniWaveEffect_Task(u8 u8PlayerNo, u8 u8EffectNo, u32 u32DataNo, u8 u8TexType);
    virtual ~clsMiniWaveEffect_Task() {}

    virtual void execute();
    virtual void draw();

    void init();
    void setWavePosition(NNS_VECTORFAST& rsPosVecFast);
    void setVelocityMtxPtr(const f32 (*opaMtx)[4][4]);
    void setPosturalMtxPtr(const f32 (*opaMtx)[4][4]);
    void setPosVecFast(NNS_VECTORFAST& rsPosVecFast);
};

#endif // MINIWAVE_HPP
