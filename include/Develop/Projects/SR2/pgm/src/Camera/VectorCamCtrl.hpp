#ifndef VECTORCAMCTRL_HPP
#define VECTORCAMCTRL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPfCamera;

// total size: 0x80
class clsVectorCam : public clsCamCtrl {
public:
    ~clsVectorCam();

    virtual s32 getControlType() const;

    virtual u32 execute(clsPfCamera* pcCamera, const clsPfCamera* pParam2);

    virtual void resetData();

    virtual void setParams(void* vpParams);

    virtual void getParams(void* vpParams);

    NNS_VECTORFAST* m_opsTgtPosVF; // offset 0x1C, size 0x4
    NNS_VECTORFAST m_sStartPos;    // offset 0x20, size 0x10
    NNS_VECTORFAST m_sEndPos;      // offset 0x30, size 0x10
    NNS_VECTORFAST m_sUpVF;        // offset 0x40, size 0x10
    NNS_VECTORFAST m_sEndUpVF;     // offset 0x50, size 0x10
    NNS_VECTORFAST m_sPos;         // offset 0x60, size 0x10
    f32 m_f32Distance;             // offset 0x70, size 0x4
    s32 m_s32Fovy;                 // offset 0x74, size 0x4
    stcCamFilter* m_psCamFilter;   // offset 0x78, size 0x4
    f32 (*m_psPosturalMtx)[4][4];  // offset 0x7C
};

#endif // VECTORCAMCTRL_HPP
