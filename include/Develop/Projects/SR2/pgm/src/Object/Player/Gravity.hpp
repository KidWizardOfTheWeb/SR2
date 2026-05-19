#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/SlerpQuat.hpp"

class clsPlayerTask;

// total size: 0x130
class clsGravity {
public:
    typedef f32 (*MtxPtr)[4][4];

    static f32 DEFAULT_ACCELE;

    enum enmFlag {
        FLAG_NULL = 0,
        FLAG_DRAW_COL = 1,
        FLAG_DRAW_MOV_LINE = 2,
        FLAG_DRAW_PST_LINE = 4,
        FLAG_DRAW_VLC_LINE = 8,
        FLAG_DRAW_GRAVITY = 16,
        FLAG_DRAW_GRID = 32,
        FLAG_INFINI_AGP = 64,
        FLAG_FREE_GEARCHANGE = 128,
        FLAG_CHANGE_COM = 256,
        FLAG_STOP = 512,
        FLAG_UPDATE_TIMER = 268435456,
        FLAG_DEFAULT = 0,
    };

    enum enmType {
        TYPE_FRONT = 0,
        TYPE_BACK = 1,
    };

    f32 m_sMtx[4][4];            // offset 0x0, size 0x40
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
    clsGravity(clsPlayerTask* pcPlayer) : m_pcPlayer(pcPlayer) {}
    void setType(enmType eType);
    void update();
    void quicksetTypeNormal(f32 of32SlerpFrame);
    void setQuatAndUpVec(const NNS_QUATERNION* psQuat);
    NNS_VECTORFAST* getUpVecFastPtr() const { return const_cast<NNS_VECTORFAST*>(&m_sUpVecFast); }
    NNS_VECTORFAST* getVecFastPtr() const { return const_cast<NNS_VECTORFAST*>(&m_sVecFast); }
    clsPath* getPathRef() { return &m_cPath; }
    MtxPtr getMtxPtr() const { return const_cast<MtxPtr>(&m_sMtx); }
    void setFlag(enmFlag eParam1) { m_eFlag = eParam1; }
    void setFrameRate(f32 f32Param1) { m_f32FrameRate = f32Param1; }
    void setAccele(f32 f32Param1) { m_f32Accele = f32Param1; }
    void setSpeed(f32 f32Param1) { m_f32Speed = f32Param1; }
    enmType getType() const { return m_eType; }
    bool isChange() { return m_f32ChangeFrame != 0.0f; }
};

#endif // GRAVITY_HPP
