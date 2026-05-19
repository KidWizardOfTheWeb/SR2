#ifndef PATHCTRLCAMERA_HPP
#define PATHCTRLCAMERA_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPfCamera;

// total size: 0xC0
class clsPathCam : public clsCamCtrl {
public:
    ~clsPathCam();

    virtual s32 getControlType() const;

    virtual u32 execute(clsPfCamera* pcCamera, const clsPfCamera* pParam2);

    virtual void resetData();

    virtual void setParams(void* vpParams);

    virtual void getParams(void* vpParams);

    enum enmPCamFlags {
        PCAM_FLG_CHGACTTYPE = 1,
        PCAM_FLG_PATHUPVEC = 2,
    };

    enmPCamFlags enmPCamFlags; // offset 0x1C, size 0x4
    clsPath m_cPath;           // offset 0x20, size 0x60
    u32 m_u32PathType;         // offset 0x80, size 0x4
    u32 m_u32LineNo;           // offset 0x84, size 0x4
    f32 m_f32Speed;            // offset 0x88, size 0x4
    u32* m_pu32ActType;        // offset 0x8C, size 0x4
    u32 m_u32Flag;             // offset 0x90, size 0x4
    u32 m_u32ActTypeBkup;      // offset 0x94, size 0x4
    NNS_VECTORFAST m_sPosVF;   // offset 0xA0, size 0x10
    u32 m_u32PNo;              // offset 0xB0, size 0x4
};

#endif // PATHCTRLCAMERA_HPP
