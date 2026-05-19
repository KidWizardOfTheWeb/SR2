#ifndef CAMIVS_HPP
#define CAMIVS_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPfCamera;

// total size: 0x28
class clsLandDownCamIv : public clsCamIvBase {
public:
    ~clsLandDownCamIv();

    virtual u32 PreIv(clsPfCamera* pcCamera);

    virtual u32 PostIv(clsPfCamera* pcCamera);

    virtual void Init();

    NNS_VECTOR m_sBkupEyeTgtWV; // offset 0x4, size 0xC
    f32 m_f32DownLen1;          // offset 0x10, size 0x4
    f32 m_f32UpLen;             // offset 0x14, size 0x4
    f32 m_f32DownLen2;          // offset 0x18, size 0x4
    u32 m_u32Frame;             // offset 0x1C, size 0x4
    u16 m_u16DownFrm1;          // offset 0x20, size 0x2
    u16 m_u16UpFrm;             // offset 0x22, size 0x2
    u16 m_u16DownFrm2;          // offset 0x24, size 0x2
    u16 m_u16TotalFrm;          // offset 0x26, size 0x2
};

namespace nspCamIvs {
extern clsLandDownCamIv cLandDownCamIv;
} // namespace nspCamIvs

#endif // CAMIVS_HPP
