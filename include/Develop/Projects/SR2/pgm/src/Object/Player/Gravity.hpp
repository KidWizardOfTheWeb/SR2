#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Matrix/nnmakematrix.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/SlerpQuat.hpp"

class clsPlayerTask;

// total size: 0x130
class clsGravity {
public:
    static const f32 DEFAULT_ACCELE;

    enum enmFlag {
        FLAG_CLEAR = 0,
        FLAG_NOT_GRAVITY = 1,
    };

    enum enmType {
        TYPE_NULL = 0,
        TYPE_NORMAL = 1,
        TYPE_GCTRL = 2,
        TYPE_STEEP = 3,
    };

    NNS_MATRIX m_sMtx;           // offset 0x0, size 0x40
    NNS_VECTORFAST m_sVecFast;   // offset 0x40, size 0x10
    NNS_VECTORFAST m_sUpVecFast; // offset 0x50, size 0x10
    clsPlayerTask* m_pcPlayer;   // offset 0x60, size 0x4
    clsPath m_cPath;             // offset 0x70, size 0x60
    clsSlerpQuat m_cSlerpQuat;   // offset 0xD0, size 0x3C
    f32 m_f32Speed;              // offset 0x10C, size 0x4
    f32 m_f32Accele;             // offset 0x110, size 0x4
    f32 m_f32FrameRate;          // offset 0x114, size 0x4
    enmFlag m_eFlag;             // offset 0x118, size 0x4
    enmType m_eType;             // offset 0x11C, size 0x4
    f32 m_f32ChangeFrame;        // offset 0x120, size 0x4

    clsGravity() {}
    clsGravity(clsPlayerTask* pcPlayer) : m_pcPlayer(pcPlayer)
    {
        m_f32Speed = 0.0f;
        m_f32Accele = DEFAULT_ACCELE;
        m_f32FrameRate = 1.0f;
        m_eFlag = FLAG_CLEAR;
        m_eType = TYPE_NORMAL;
        m_f32ChangeFrame = 0.0f;
        nnMakeUnitMatrix(&m_sMtx);
        nnSetUpVectorFast(&m_sVecFast, 0.0f, 0.0f, 0.0f);
        nnSetUpVectorFast(&m_sUpVecFast, 0.0f, 1.0f, 0.0f);
    }
    void setType(enmType eType);
    void update();
    void quicksetTypeNormal(f32 of32SlerpFrame);
    void setQuatAndUpVec(const NNS_QUATERNION* psQuat);
    const NNS_VECTORFAST* getUpVecFastPtr() const { return &m_sUpVecFast; }
    const NNS_VECTORFAST* getVecFastPtr() const { return &m_sVecFast; }
    clsPath* getPathRef() { return &m_cPath; }
    const NNS_MATRIX* getMtxPtr() const { return &m_sMtx; }
    void setFlag(enmFlag eParam1) { m_eFlag = eParam1; }
    void setFrameRate(f32 f32Param1) { m_f32FrameRate = f32Param1; }
    void setAccele(f32 f32Param1) { m_f32Accele = f32Param1; }
    void setSpeed(f32 f32Param1) { m_f32Speed = f32Param1; }
    enmType getType() const { return m_eType; }
    bool isChange() { return m_f32ChangeFrame != 0.0f; }
};

#endif // GRAVITY_HPP
