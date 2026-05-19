#ifndef ELECTRICDAMAGE_HPP
#define ELECTRICDAMAGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/ObjectEffect.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0xF0
class clsElectricDamageEffect_Task : public clsBaseEffect_Task {
public:
    ~clsElectricDamageEffect_Task();

    clsElectricDamageEffect_Task(f32 f32LifeFrame,
                                 u32 u32Type,
                                 s32 s32SeId,
                                 clsModelType_OB_TX_MO_MA* pcModel,
                                 u32 u32StageNo,
                                 enmNo eNo,
                                 enmCalcNodePos eNodePos);

    virtual void execute();

    virtual void draw();

    NNS_VECTORFAST m_sPosVF; // offset 0xD0, size 0x10
    f32 m_f32AliveFrame;     // offset 0xE0, size 0x4
    s32 m_s32SeID;           // offset 0xE4, size 0x4
};

#endif // ELECTRICDAMAGE_HPP
