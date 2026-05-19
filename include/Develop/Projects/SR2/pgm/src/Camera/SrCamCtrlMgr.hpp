#ifndef SRCAMCTRLMGR_HPP
#define SRCAMCTRLMGR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

class clsDomeCam;
class clsGctrlCam;
class clsMotionCam;
class clsPathCam;
class clsSrCamMixer;
class clsTargetCam;
class clsVectorCam;

namespace nspCamParam {
clsMotionCam* createMotionCamCtrl();
clsPathCam* createPathCamCtrl();
clsVectorCam* createVectorCamCtrl();
clsDomeCam* createDomeCamCtrl();
clsGctrlCam* createGctrlCamCtrl();
clsTargetCam* createTagertCamCtrl();
clsSrCamMixer* createSrCamMixer();
} // namespace nspCamParam

// total size: 0x68
class clsSrCamCtrlMgr : public clsSingleton<clsSrCamCtrlMgr> {
public:
    clsSrCamCtrlMgr() {}
    virtual ~clsSrCamCtrlMgr();

    void setViewPortNormal(u32 ou32N);

    vector m_vecpcCamCtrl;    // offset 0x4, size 0xC
    vector m_vecpcTargetCam;  // offset 0x10, size 0xC
    vector m_vecpcGctrlCam;   // offset 0x1C, size 0xC
    vector m_vecpcDomeCam;    // offset 0x28, size 0xC
    vector m_vecpcVecCam;     // offset 0x34, size 0xC
    vector m_vecpcPathCam;    // offset 0x40, size 0xC
    vector m_vecpcMotionCam;  // offset 0x4C, size 0xC
    vector m_vecpcSrCamMixer; // offset 0x58, size 0xC
    u32 m_u32UniqNo;          // offset 0x64, size 0x4
};

#endif // SRCAMCTRLMGR_HPP
