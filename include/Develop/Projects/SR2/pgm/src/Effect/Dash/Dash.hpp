#ifndef DASH_HPP
#define DASH_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/BaseEffect.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0xD0
class clsDashEffect_Task : public clsBaseEffect_Task {
public:
    clsDashEffect_Task(u32 u32TpI,
                       s32 s32TypeI,
                       clsModelType_OB_TX_MO_MA* pcModelI,
                       u32 eFlagI,
                       u32 u32ViewNo,
                       enmNo eNo,
                       enmCalcNodePos eBornNo)
        : clsBaseEffect_Task(u32TpI, s32TypeI, pcModelI, eFlagI, u32ViewNo, eNo, eBornNo, 0.0f)
    {
    }
    virtual ~clsDashEffect_Task() {}

    virtual void execute();

    static u8 getVisible(enmNo eParam1) { return (m_tu8Used & (1 << eParam1)) != 0; }

    static u8 m_tu8Used;
};

#endif // DASH_HPP
