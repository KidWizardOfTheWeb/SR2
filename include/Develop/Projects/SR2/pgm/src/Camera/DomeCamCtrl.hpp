#ifndef DOMECAMCTRL_HPP
#define DOMECAMCTRL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPfCamera;

// total size: 0x40
class clsDomeCam : public clsCamCtrl {
public:
    ~clsDomeCam();

    virtual s32 getControlType() const;

    virtual u32 execute(clsPfCamera* pcCamera, const clsPfCamera* pParam2);

    virtual void resetData();

    virtual void setParams(void* vpParams);

    virtual void getParams(void* vpParams);

    NNS_VECTORFAST* m_opsTgtPosVF; // offset 0x1C, size 0x4
    f32 (*m_opsPosturalMtx)[4][4]; // offset 0x20
    NNS_VECTOR m_sUpVec;           // offset 0x24, size 0xC
    f32 m_f32Dist;                 // offset 0x30, size 0x4
    s32 m_s32RotX;                 // offset 0x34, size 0x4
    s32 m_s32RotY;                 // offset 0x38, size 0x4
    s32 m_s32Fovy;                 // offset 0x3C, size 0x4
};

#endif // DOMECAMCTRL_HPP
