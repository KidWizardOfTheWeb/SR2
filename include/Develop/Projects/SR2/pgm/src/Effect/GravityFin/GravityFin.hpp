#ifndef GRAVITYFIN_HPP
#define GRAVITYFIN_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/BaseEffect.hpp"

// total size: 0xF0
class clsGravityFinEffect_Task : public clsBaseEffect_Task {
public:
    clsGravityFinEffect_Task(u32 u32Param1,
                             s32 s32Param2,
                             clsModelType_OB_TX_MO_MA* pcModel,
                             u32 u32Param5,
                             u32 u32Param6,
                             nspPlayer::enmNo eNo,
                             clsPlayerTask::enmCalcNodePos eNodePos);
    virtual ~clsGravityFinEffect_Task() {}
    virtual void execute();
    virtual void draw();

    NNS_VECTORFAST m_sPosVectorFast; // offset 0xD0, size 0x10
    f32 m_f32AddFrame;               // offset 0xE0, size 0x4
    f32 m_f32EndWaitFrame;           // offset 0xE4, size 0x4
};

#endif // GRAVITYFIN_HPP
