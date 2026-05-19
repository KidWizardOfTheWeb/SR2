#ifndef PS2_GRAVITYWAVE_HPP
#define PS2_GRAVITYWAVE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/GravityWave/BaseGravityWave.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

// total size: 0x30
struct stcWaveVtxFmt {
    NNS_VECTORFAST sPosVF; // offset 0x0, size 0x10
    NNS_VECTORFAST sNrmVF; // offset 0x10, size 0x10
    NNS_VECTORFAST sUV_VF; // offset 0x20, size 0x10
};

// total size: 0xD0
class clsGravityWave_Task : public clsBaseGravityWave_Task {
public:
    virtual ~clsGravityWave_Task() {}
    clsGravityWave_Task(u32 u32PrioI, s32 s32FlgI);

    virtual void execute();
    virtual void captureFullScreen();
    virtual void drawNega(u32 u32v);
    virtual void drawOrthoModel(u32 u32v, clsModelType_OB_TX_MO_MA_MF& rcModel);
    virtual f32 changeNegaRatio(f32 param_1) const { return param_1; }

    void replaceMorphUV(NNS_OBJECT* psMorphObj, u32 u32v);
    void initModel(clsModelType_OB_TX_MO_MA_MF& rcModel, u32 u32Param);

    u64* m_pu64GsPacket_DrawNega; // offset 0xC0, size 0x4
    u64* m_pu64GsPacket_Capture;  // offset 0xC4, size 0x4
    u32 m_u32DrawHeightx16;       // offset 0xC8, size 0x4
    f32 m_f32ScalePalY;           // offset 0xCC, size 0x4
};

#endif // PS2_GRAVITYWAVE_HPP
