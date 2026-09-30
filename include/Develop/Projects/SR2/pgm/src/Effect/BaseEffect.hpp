#ifndef BASEEFFECT_HPP
#define BASEEFFECT_HPP

#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleAbsorb.hpp"
#include "types.h"

// total size: 0xD0
class clsBaseEffect_Task : public clsTask {
public:
    virtual ~clsBaseEffect_Task();
    virtual void execute();
    virtual void draw();

    clsBaseEffect_Task(u32 u32TpI,
                       s32 s32TypeI,
                       clsModelType_OB_TX_MO_MA* pcModelI,
                       u32 eFlagI,
                       u32 u32ViewNo,
                       nspPlayer::enmNo eNo,
                       clsPlayerTask::enmCalcNodePos eBornNo,
                       f32 f32WaitFrame);

    NNS_MATRIX m_sTrsMtx;                    // offset 0x60, size 0x40
    f32 m_f32MotionFrame;                    // offset 0xA0, size 0x4
    f32 m_f32MatMotionFrame;                 // offset 0xA4, size 0x4
    f32 m_f32WaitFrame;                      // offset 0xA8, size 0x4
    f32 m_f32DrawScale;                      // offset 0xAC, size 0x4
    clsModelType_OB_TX_MO_MA* m_pcModel;     // offset 0xB0, size 0x4
    u32 m_eFlag;                             // offset 0xB4, size 0x4
    nspPlayer::enmNo m_ePlayerNo;            // offset 0xB8, size 0x4
    clsPlayerTask::enmCalcNodePos m_eBornNo; // offset 0xBC, size 0x4
    u32 m_u32ViewNo;                         // offset 0xC0, size 0x4
    s32 m_s32RotZ;                           // offset 0xC4, size 0x4
};

#endif // BASEEFFECT_HPP
