#ifndef OOCAMERADEBUG_HPP
#define OOCAMERADEBUG_HPP

#include "usr/local/sega/nn/src/Camera/nncamera.h"
#include "types.h"

// total size: 0x7814
class clsOOCameraDebug {
public:
    virtual ~clsOOCameraDebug() {}
    void draw();
    void resetCamData();
    void addCamData(NNS_CAMERA_TARGET_UPVECTOR* psCamera);

    NNS_VECTOR m_asCamPosV[512];    // offset 0x4, size 0x1800
    NNS_VECTOR m_asTargetV[512][2]; // offset 0x1804, size 0x3000
    NNS_VECTOR m_asCamUpV[512][2];  // offset 0x4804, size 0x3000
    s32 m_s32CurIdx;                // offset 0x7804, size 0x4
    u32 m_u32DrawFlag;              // offset 0x7808, size 0x4
    u8 m_u8No;                      // offset 0x780C, size 0x1
    u32 m_u32ActiveNum;             // offset 0x7810, size 0x4
};

#endif // OOCAMERADEBUG_HPP
