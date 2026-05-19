#ifndef PS2NNCAMERA_HPP
#define PS2NNCAMERA_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOCameraDebug.hpp"
#include "usr/local/sega/nn/src/Camera/nncamera.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "types.h"

class clsCamMixer;

// total size: 0x8
class clsOOCamera {
public:
    virtual void setNo(u32 param_1) { m_u32CamNo = param_1; }
    clsOOCamera& operator=(const clsOOCamera& param_1) { return *this; }

    u32 m_u32CamNo; // offset 0x4, size 0x4
};

// total size: 0x7AD0
class clsPfCamera : public clsOOCamera {
public:
    typedef f32 (*MtxPtr)[4];

    clsPfCamera();
    virtual void setNo(u32 u32Param1)
    {
        m_u32CamNo = u32Param1;
        m_cCamDebug.m_u8No = u32Param1;
    }
    virtual ~clsPfCamera();
    virtual clsCamMixer* getMixer() const { return m_pcMixer; }
    void init();
    void update();
    void setMixer(clsCamMixer* pcCamMix);
    void resetMixerData();
    void getCamFrontPos(NNS_VECTORFAST& rsVectorFastI, f32 of32Scale);
    void getOrthoCoord(s32& rs32DstX, s32& rs32DstY, s32 s32SrcX, s32 s32SrcY);
    void invalidateOrthoMtx();
    void DebugCamera();
    void DebugCameraDome();
    MtxPtr getViewMtx() const { return const_cast<MtxPtr>(m_sViewMtx); }
    NNS_VECTORFAST* getPosFast() const { return const_cast<NNS_VECTORFAST*>(&m_sCameraPosVF); }
    u8 getDebugDomeMode() const { return m_u8DomeCamera; }
    u8 getDebugLookMode() const { return m_u8LookPlayer; }
    void setAspect(f32 f32Param1) { m_sCamera.Aspect = f32Param1; }
    void setZFar(f32 f32Param1) { m_sCamera.ZFar = f32Param1; }
    void setZNear(f32 f32Param1) { m_sCamera.ZNear = f32Param1; }
    void setFovy(s32 s32Param1) { m_sCamera.Fovy = s32Param1; }
    void setUpVec(const NNS_VECTOR* opsVector) { m_sCamera.UpVector = *opsVector; }
    void setTarget(const NNS_VECTOR* opsVector) { m_sCamera.Target = *opsVector; }
    void setPos(const NNS_VECTOR* opsVector) { m_sCamera.Position = *opsVector; }

    clsOOCameraDebug m_cCamDebug;         // offset 0x8, size 0x7814
    f32 m_sViewMtx[4][4];                 // offset 0x7820, size 0x40
    f32 m_sBillBoardMtx[4][4];            // offset 0x7860, size 0x40
    f32 m_sYBillBoardMtx[4][4];           // offset 0x78A0, size 0x40
    f32 m_sPrjMtx[4][4];                  // offset 0x78E0, size 0x40
    f32 m_sOrthoMtx[4][4];                // offset 0x7920, size 0x40
    f32 m_sClipMtx[4][4];                 // offset 0x7960, size 0x40
    NNS_CAMERA_TARGET_UPVECTOR m_sCamera; // offset 0x79A0, size 0x38
    clsCamMixer* m_pcMixer;               // offset 0x79D8, size 0x4
    NNS_VECTORFAST m_sAxisX;              // offset 0x79E0, size 0x10
    NNS_VECTORFAST m_sAxisY;              // offset 0x79F0, size 0x10
    NNS_VECTORFAST m_sAxisZ;              // offset 0x7A00, size 0x10
    NNS_VECTORFAST m_sCameraPosVF;        // offset 0x7A10, size 0x10
    f32 m_sBkupViewMtx[4][4];             // offset 0x7A20, size 0x40
    f32 m_sBkupPrjMtx44[4][4];            // offset 0x7A60, size 0x40
    f32 m_f32Left;                        // offset 0x7AA0, size 0x4
    f32 m_f32Right;                       // offset 0x7AA4, size 0x4
    f32 m_f32Top;                         // offset 0x7AA8, size 0x4
    f32 m_f32Bottom;                      // offset 0x7AAC, size 0x4
    f32 m_f32CamDist;                     // offset 0x7AB0, size 0x4
    f32 m_f32CamHeight;                   // offset 0x7AB4, size 0x4
    u8 m_u8DebugSetCamFlg;                // offset 0x7AB8, size 0x1
    u8 m_u8LookPlayer;                    // offset 0x7AB9, size 0x1
    u8 m_u8DomeCamera;                    // offset 0x7ABA, size 0x1
    f32 m_f32DomeDist;                    // offset 0x7ABC, size 0x4
    s32 m_s32DomeRotY;                    // offset 0x7AC0, size 0x4
    s32 m_s32DomeRotX;                    // offset 0x7AC4, size 0x4
};

#endif // PS2NNCAMERA_HPP
