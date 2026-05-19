#ifndef SCRIPTCAMERA_HPP
#define SCRIPTCAMERA_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Camera/nncamera.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

class clsScript_Task;

// total size: 0x1C
class clsScriptCamera {
public:
    clsScriptCamera();
    virtual ~clsScriptCamera() {}

    void
    calcCamera(f32 f32Frame, NNS_CAMERAPTR* psPtr, NNS_MOTION* psMotion, NNS_CAMERAPTR* psCalcPtr);
    void codeSetCamera(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeAllDelCamera(u8* pcParam1, clsScript_Task* pParam2);
    void codeViewport(u8* pcParam1, clsScript_Task* pParam2);
    void playCamera(u8* pcParam1, clsScript_Task* pParam2);
    void setupCamera();
    void initData();
    void addData(u8* pu8BinTopAddr, u32* pu32OffsetNo, u16 u16BinNum, u32 u32LoopNum);
    u8 update();
    u8 setCamera();

    NNS_CAMERAPTR* m_psCalcCamera; // offset 0x4, size 0x4
    s32 m_s32No;                   // offset 0x8, size 0x4
    u32 m_u32Flg;                  // offset 0xC, size 0x4
    f32 m_f32MotionFrame;          // offset 0x10, size 0x4
    NNS_CAMERAPTR* m_psPtr;        // offset 0x14, size 0x4
    NNS_MOTION* m_psMotion;        // offset 0x18, size 0x4

    static s32 m_ts32DataNum;      // 0xB13CA8
    static u8* m_tapu8DataBuf[64]; // 0xB13CB0
};

#endif // SCRIPTCAMERA_HPP
