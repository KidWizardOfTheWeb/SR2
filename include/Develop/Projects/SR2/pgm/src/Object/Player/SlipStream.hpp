#ifndef SLIPSTREAM_HPP
#define SLIPSTREAM_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlayerTask;

// total size: 0xD0
class clsSlipStream {
public:
    enum enmStatus {
        STATUS__NONE = 0,
        STATUS__RANGE_IN = 1,
        STATUS__RANGE_ALWAYS = 2,
        STATUS__RANGE_OUT = 3,
    };

    struct stcData {
        NNS_VECTORFAST sPosVecFast; // offset 0x0, size 0x10
        NNS_VECTORFAST sDirVecFast; // offset 0x10, size 0x10
        f32 f32Speed;               // offset 0x20, size 0x4
        f32 f32Accele;              // offset 0x24, size 0x4
        f32 f32Reserved[2];         // offset 0x28, size 0x8
    }; // total size: 0x30

    clsSlipStream() {}

    void update(clsPlayerTask* pcPlayer);
    void execute(clsPlayerTask* pcPlayer);
    void draw();

    static f32 t_of32Range;

    class stcData m_sData[4]; // offset 0x0, size 0xC0
    enmStatus m_eStatus;      // offset 0xC0, size 0x4
    f32 m_f32UpdateCount;     // offset 0xC4, size 0x4
    u32 m_u32PointNo;         // offset 0xC8, size 0x4
};

#endif // SLIPSTREAM_HPP
