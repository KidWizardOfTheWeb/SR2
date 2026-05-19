#ifndef MOTIONCAMCTRL_HPP
#define MOTIONCAMCTRL_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlash.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2CamCtrl.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPfCamera;

class clsMotionCam : public clsCamCtrl {
public:
    clsMotionCam();
    virtual ~clsMotionCam();
    virtual u32 getControlType() const;
    virtual u32 execute(clsPfCamera* pcCamera, const clsPfCamera* pParam2);
    virtual void resetData();
    virtual void setParams(void* vpParams);
    virtual void getParams(void* vpParams);

    // Members
    NNS_VECTOR m_sAddPos;       // offset 0x1C, size 0xC
    NNS_QUATERNION m_sAddQuat;  // offset 0x28, size 0x10
    NNS_CAMERAPTR* m_psBaseCam; // offset 0x38, size 0x4
    NNS_CAMERAPTR* m_psCalcCam; // offset 0x3C, size 0x4
    NNS_MOTION* m_psCamMotion;  // offset 0x40, size 0x4
    f32 m_f32StartFrame;        // offset 0x44, size 0x4
    f32 m_f32PlayFrame;         // offset 0x48, size 0x4
    f32 m_f32EndFrame;          // offset 0x4C, size 0x4
    f32 m_f32SpeedRate;         // offset 0x50, size 0x4

    static void calcCameraMotion(clsPfCamera* pcCamera,
                                 f32 f32Frame,
                                 NNS_CAMERAPTR* psPtr,
                                 NNS_MOTION* psMotion,
                                 NNS_CAMERAPTR* psCalcPtr);
};

#endif // MOTIONCAMCTRL_HPP
